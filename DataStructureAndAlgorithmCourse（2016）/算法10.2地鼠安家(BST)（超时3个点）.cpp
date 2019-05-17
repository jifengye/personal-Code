//�㷨10.2���󰲼�(BST) 
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
		int hgt;//�Դ˽ڵ�Ϊ�������ĸ߶�
        unsigned int freq;//Ƶ��
		
		TreeNode():lson(NULL),rson(NULL),parent(NULL),hgt(0),freq(1){}
};

//AVL��������Ժͷ�������
class AVLTree
{
    private:
        TreeNode* root;//���ڵ�                                           //�������Ͷ��� 
        void insertpri(TreeNode* pnode,TreeNode* &node,T x);//����        //��Ա�������� 
        TreeNode* findpri(TreeNode* node,T x);//����
        void insubtree(TreeNode* node);//�������
        void leveltree(TreeNode* node);//��α��� 
        void Deletepri(TreeNode* &node,T x);//ɾ��
        int height(TreeNode* node);//�����ĸ߶�

    public:
        AVLTree():root(NULL){}
        void insert(T x);//����ӿ�
        TreeNode* find(T x);//���ҽӿ�
        void Delete(T x);//ɾ���ӿ�
        void traversal();//��������ӿ�
        void levelorder();//��α����ӿ� 

};

//�����Խڵ�Ϊ�������ĸ߶�
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}

//����
void AVLTree::insertpri(TreeNode* pnode,TreeNode* &node,T x)
{
    if(node==NULL)//����ڵ�Ϊ��,���ڴ˽ڵ㴦����x��Ϣ
    {
        node=new TreeNode();
        node->data=x;
        node->parent=pnode;
		if(pnode==NULL) {root=node;node->data.h=1;}
		else node->data.h=pnode->data.h+1;
        return;
    }
    if(node->data>x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
    {
        insertpri(node,node->lson,x);
    }
    else if(x>node->data)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
    {
        insertpri(node,node->rson,x);
    }
    else ++(node->freq);//������,�Ͱ�Ƶ�ʼ�1
    node->hgt=Max(height(node->lson),height(node->rson))+1;
}

//����ӿ�
void AVLTree::insert(T x)
{
    insertpri(NULL,root,x);
}

//�����������
void AVLTree::insubtree(TreeNode* node)
{
    if(node==NULL) return;
    insubtree(node->lson);//�ȱ���������
    printf("%d ",node->data.h);//������ڵ�
    insubtree(node->rson);//�ٱ���������
}
//��������ӿ�
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
