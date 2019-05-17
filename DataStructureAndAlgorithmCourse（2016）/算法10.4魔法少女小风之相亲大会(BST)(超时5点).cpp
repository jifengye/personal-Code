//算法10.4魔法少女小风之相亲大会(BST) 
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
		void intree(TreeNode* node,T x);//中序遍历
        int height(TreeNode* node);//求树的高度

    public:
        AVLTree():root(NULL){}
        void insert(T x);//插入接口
        void Delete(T x);//删除接口  
        void inorder(T x); //中序遍历接口 

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
    return node;
}
//删除接口
void AVLTree::Delete(T x)
{
    root=Deletepri(root,x);
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
