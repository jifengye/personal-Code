//算法10.2地鼠安家(BST) 
#include<iostream>
#include<cstdio>
#include<queue>
#define Max(a,b) (a>b?a:b)
using namespace std;

class Rat;
bool operator > (Rat &a,Rat &b);
class Rat
{
	public:
	int no;
	int h; 
	Rat():no(0),h(0){} 
	friend bool operator > (Rat &a,Rat &b);
}; 
bool operator >(Rat &a,Rat &b)
{
	return a.no>b.no;
}
typedef Rat T;
class TreeNode
{
    public:
        T data;
        TreeNode* lson;
        TreeNode* rson;
        TreeNode* parent; 
		int hgt;//以此节点为根的树的高度
        unsigned int freq;//频率
		
		TreeNode():lson(NULL),rson(NULL),parent(NULL),hgt(0),freq(1){}
};

//AVL树类的属性和方法声明
class AVLTree
{
    private:
        TreeNode* root;//根节点                                           //数据类型定义 
        void insertpri(TreeNode* pnode,TreeNode* &node,T x);//插入        //成员函数声明 
        TreeNode* findpri(TreeNode* node,T x);//查找
        void insubtree(TreeNode* node);//中序遍历
        void leveltree(TreeNode* node);//层次遍历 
        void Deletepri(TreeNode* &node,T x);//删除
        int height(TreeNode* node);//求树的高度

    public:
        AVLTree():root(NULL){}
        void insert(T x);//插入接口
        TreeNode* find(T x);//查找接口
        void Delete(T x);//删除接口
        void traversal();//中序遍历接口
        void levelorder();//层次遍历接口 

};

//计算以节点为根的树的高度
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}

//插入
void AVLTree::insertpri(TreeNode* pnode,TreeNode* &node,T x)
{
    if(node==NULL)//如果节点为空,就在此节点处加入x信息
    {
        node=new TreeNode();
        node->data=x;
        node->parent=pnode;
		if(pnode==NULL) {root=node;node->data.h=1;}
		else node->data.h=pnode->data.h+1;
        return;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
    {
        insertpri(node,node->lson,x);
    }
    else if(x>node->data)//如果x大于节点的值,就继续在节点的右子树中插入x
    {
        insertpri(node,node->rson,x);
    }
    else ++(node->freq);//如果相等,就把频率加1
    node->hgt=Max(height(node->lson),height(node->rson))+1;
}

//插入接口
void AVLTree::insert(T x)
{
    insertpri(NULL,root,x);
}

//中序遍历函数
void AVLTree::insubtree(TreeNode* node)
{
    if(node==NULL) return;
    insubtree(node->lson);//先遍历左子树
    printf("%d ",node->data.h);//输出根节点
    insubtree(node->rson);//再遍历右子树
}
//中序遍历接口
void AVLTree::traversal()
{
    insubtree(root);
    cout<<endl;
}

int main()
{
	AVLTree tree;
	int i,n;
	Rat a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a.no);
		tree.insert(a);	
	}
	tree.traversal();
	return 0;
}
/*
5
4 2 1 3 5
output 3 2 3 1 2

3
1 3 2
output 1 3 2
*/
