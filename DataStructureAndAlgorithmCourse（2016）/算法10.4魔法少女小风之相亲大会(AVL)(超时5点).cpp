//算法10.4魔法少女小风之相亲大会(AVL) 
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
		void intree(TreeNode* node,T x);//中序遍历
		void posttree(TreeNode* node); //后序 
        void leveltree(TreeNode* node);//层次遍历 
        int height(TreeNode* node);//求树的高度
        TreeNode* SingRotateLeft(TreeNode* k2);//左左情况下的旋转
        TreeNode* SingRotateRight(TreeNode* k2);//右右情况下的旋转
        TreeNode* DoubleRotateLR(TreeNode* k3);//左右情况下的旋转
        TreeNode* DoubleRotateRL(TreeNode* k3);//右左情况下的旋转 

    public:
        AVLTree():root(NULL){}
        void insert(T x);//插入接口
        void Delete(T x);//删除接口
        void preorder(); //前序遍历接口   
        void inorder(T x); //中序遍历接口 
        void postorder(); //后序遍历接口 
        void levelorder(); //层次遍历接口 

};

//计算以节点为根的树的高度
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}


//左左情况下的旋转
TreeNode* AVLTree::SingRotateLeft(TreeNode* k2)
{
    TreeNode* k1=k2->lson;
    k2->lson=k1->rson;
    k1->rson=k2;

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1; 
    k1->hgt=Max(height(k1->lson),k2->hgt)+1;
    
    return k1;
}

//右右情况下的旋转
TreeNode* AVLTree::SingRotateRight(TreeNode* k2)
{   
    TreeNode *k1=k2->rson;
    k2->rson=k1->lson;
    k1->lson=k2;           

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt=Max(height(k1->rson),k2->hgt)+1;
    
    return k1;
}

//左右情况的旋转
TreeNode* AVLTree::DoubleRotateLR(TreeNode* k3)
{
    k3->lson=SingRotateRight(k3->lson);
    return SingRotateLeft(k3);
}

//右左情况的旋转
TreeNode* AVLTree::DoubleRotateRL(TreeNode* k3)
{
    k3->rson=SingRotateLeft(k3->rson);
    return SingRotateRight(k3);
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
        if(2==height(node->lson)-height(node->rson))
            if(node->lson->data>x)
                node=SingRotateLeft(node);
            else
                node=DoubleRotateLR(node);
    }
    else if(x>node->data)//如果x大于节点的值,就继续在节点的右子树中插入x
    {
        node->rson= insertpri(node->rson,x);
        if(2==height(node->rson)-height(node->lson))//如果高度之差为2的话就失去了平衡,需要旋转
            if(x>node->rson->data)
				node=SingRotateRight(node);
            else
                node=DoubleRotateRL(node);
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
         if(2==height(node->rson)-height(node->lson))
            if(node->rson->lson!=NULL&&(height(node->rson->lson)>height(node->rson->rson)) )
                node=DoubleRotateRL(node);
            else
                node=SingRotateRight(node);
    }
    else if(x > node->data)
    {
         node->rson= Deletepri(node->rson,x);//如果x大于节点的值,就继续在节点的右子树中删除x
         if(2==height(node->lson)-height(node->rson))
            if(node->lson->rson!=NULL&& (height(node->lson->rson)>height(node->lson->lson) ))
                node=DoubleRotateLR(node);
            else
                node=SingRotateLeft(node);
    }
    else//如果相等,此节点就是要删除的节点
    {
        if(node->lson&&node->rson)//此节点有两个儿子
        {
            if( height(node->lson)>height(node->rson) )//左子树比右子树高；
            {
                //(01)找出tree的左子树中的最大节点
                //(02)将该最大节点的值赋值给tree。
                //(03)删除该最大节点。
                //这类似于用"tree的左子树中最大节点"做"tree"的替身；
                //采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                TreeNode* temp=node->lson;
                while(temp&&temp->rson) temp=temp->rson;
                node->data=temp->data;
                node->freq=temp->freq;
                node->lson=Deletepri(node->lson,temp->data);
            }
            else//它们相等，或右子树比左子树高
            {
                //则(01)找出tree的右子树中的最小节点
                //(02)将该最小节点的值赋值给tree。
                //(03)删除该最小节点。
                //这类似于用"tree的右子树中最小节点"做"tree"的替身；
                //采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
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
    //if(node) node->hgt=Max(height(node->lson),height(node->rson))+1;
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

int place=0,book=0;
//中序遍历函数
void AVLTree::intree(TreeNode* node,T x)
{
    if(node==NULL) return;
    intree(node->lson,x);
    if(++place==x)  {book=node->data;return;}
    intree(node->rson,x);
}
void AVLTree::inorder(T x)
{
    intree(root,x);
    printf("%d\n",book);
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
	char opt[4];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",opt);
		if(opt[0]=='J')
		{
			scanf("%d",&a);
			tree.insert(a);
		}
		else if(opt[0]=='X')
		{
			scanf("%d",&a);
			tree.Delete(a);
			
		}
		else if(opt[0]=='W')
		{
			scanf("%d",&a);
			book=place=0;
			tree.inorder(a);
		}
		else printf("Single dog!\n");
	}
	return 0;
}
/*
10
JX 11
JX 111
JX 1111
WT 1
XQ 11
WT 1
XQ 111
WT 1
WT 1111
YOU
output:
11
111
1111
0
Single dog!

10
JX 11
XQ 11
*/
