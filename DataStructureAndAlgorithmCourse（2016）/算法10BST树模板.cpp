//算法10二叉搜索树(BST) 
#include<iostream>
#include<queue>
#define Max(a,b) (a>b?a:b)
using namespace std;

//AVL树节点信息
typedef int T;
class TreeNode
{
    public:
        T data;
        TreeNode* lson;
        TreeNode* rson;
		int hgt;//以此节点为根的树的高度
        unsigned int freq;//频率
		
		TreeNode():lson(NULL),rson(NULL),hgt(0),freq(1){}
		TreeNode(T a):data(a),lson(NULL),rson(NULL),freq(1){}
};

//AVL树类的属性和方法声明
class AVLTree
{
    private:
        TreeNode* root;//根节点
        TreeNode* insertpri(TreeNode* node,T x);//插入
		TreeNode* Deletepri(TreeNode* node,T x);//删除
        void pretree(TreeNode* node); //前序 
		void intree(TreeNode* node);//中序遍历
		void posttree(TreeNode* node); //后序 
        void leveltree(TreeNode* node);//层次遍历 
        int height(TreeNode* node);//求树的高度

    public:
        AVLTree():root(NULL){}
        void insert(T x);//插入接口
        void Delete(T x);//删除接口
        void preorder(); //前序遍历接口   
        void inorder(); //中序遍历接口 
        void postorder(); //后序遍历接口 
        void levelorder(); //层次遍历接口 

};

//计算以节点为根的树的高度
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}

//插入
TreeNode* AVLTree::insertpri(TreeNode* node,T x)
{
    if(node==NULL)//如果节点为空,就在此节点处加入x信息
    {
        node=new TreeNode(x);
    }
    else if(node->data > x)//如果x小于节点的值,就继续在节点的左子树中插入x
    {
        node->lson= insertpri(node->lson,x);
    }
    else if(x>node->data)//如果x大于节点的值,就继续在节点的右子树中插入x
    {
        node->rson= insertpri(node->rson,x);
    }
    else ++(node->freq);//如果相等,就把频率加1
    node->hgt=Max(height(node->lson),height(node->rson))+1;
    return node;
}
//插入接口
void AVLTree::insert(T x)
{
    root=insertpri(root,x);
}

//删除
TreeNode* AVLTree::Deletepri(TreeNode* node,T x)
{
    if(node==NULL) return NULL;//没有找到值是x的节点
    if(x < node->data)
    {
         node->lson= Deletepri(node->lson,x);//如果x小于节点的值,就继续在节点的左子树中删除x
    }
    else if(x > node->data)
    {
         node->rson= Deletepri(node->rson,x);//如果x大于节点的值,就继续在节点的右子树中删除x
    }
    else//如果相等,此节点就是要删除的节点
    {
        if(node->lson&&node->rson)//此节点有两个儿子
        {
            if( height(node->lson)>height(node->rson) )//左子树比右子树高；
            {
                TreeNode* temp=node->lson;
                while(temp&&temp->rson) temp=temp->rson;
                node->data=temp->data;
                node->freq=temp->freq;
                node->lson=Deletepri(node->lson,temp->data);
            }
            else//它们相等，或右子树比左子树高
            {
                TreeNode* temp=node->rson;
                while(temp&&temp->lson) temp=temp->lson;
                node->rson=Deletepri(node->rson, temp->data);
            }
        }
        else//此节点有1个或0个儿子
        {
            TreeNode* temp=node;
            node=(node->lson!=NULL) ? node->lson : node->rson;
            delete(temp);
        }
    }
    if(node) node->hgt=Max(height(node->lson),height(node->rson))+1;
    return node;
}
//删除接口
void AVLTree::Delete(T x)
{
    root=Deletepri(root,x);
}

//前序遍历
void AVLTree::pretree(TreeNode* node)
{
	if(node==NULL) return;
	cout<<node->data<<" ";
	pretree(node->lson);
	pretree(node->rson);
}
void AVLTree::preorder()
{
	pretree(root);
	cout<<endl;
}
	
//中序遍历函数
void AVLTree::intree(TreeNode* node)
{
    if(node==NULL) return;
    intree(node->lson);
    cout<<node->data<<" ";
    intree(node->rson);
}
void AVLTree::inorder()
{
    intree(root);
    cout<<endl;
}

//后序遍历 
void AVLTree::posttree(TreeNode* node)
{
	if(node==NULL) return;
	posttree(node->lson);
	posttree(node->rson);
	cout<<node->data<<" ";
}
void AVLTree::postorder()
{
	posttree(root);
	cout<<endl;
}

//层次遍历函数
void AVLTree::leveltree(TreeNode* node)
{
    queue<TreeNode*>q;
	if(node) q.push(node);
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		cout<<node->data<<" ";
		if(node->lson)  q.push(node->lson);
		if(node->rson)  q.push(node->rson);
	}
}
void AVLTree::levelorder()
{
	leveltree(root);
	cout<<endl;
}

int main()
{
	AVLTree tree;
	int i,n,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		tree.insert(a);
		tree.inorder();
		tree.levelorder();
	}
	return 0;
}
