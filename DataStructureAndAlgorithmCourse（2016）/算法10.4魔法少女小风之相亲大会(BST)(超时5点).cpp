//�㷨10.4ħ����ŮС��֮���״��(BST) 
#include<iostream>
#include<queue>
#define Max(a,b) (a>b?a:b)
using namespace std;

//AVL���ڵ���Ϣ
typedef int T;
class TreeNode
{
    public:
        T data;
        TreeNode* lson;
        TreeNode* rson;
		int hgt;//�Դ˽ڵ�Ϊ�������ĸ߶�
        unsigned int freq;//Ƶ��
		
		TreeNode():lson(NULL),rson(NULL),hgt(0),freq(1){}
		TreeNode(T a):data(a),lson(NULL),rson(NULL),freq(1){}
};

//AVL��������Ժͷ�������
class AVLTree
{
    private:
        TreeNode* root;//���ڵ�
        TreeNode* insertpri(TreeNode* node,T x);//����
		TreeNode* Deletepri(TreeNode* node,T x);//ɾ��
		void intree(TreeNode* node,T x);//�������
        int height(TreeNode* node);//�����ĸ߶�

    public:
        AVLTree():root(NULL){}
        void insert(T x);//����ӿ�
        void Delete(T x);//ɾ���ӿ�  
        void inorder(T x); //��������ӿ� 

};

//�����Խڵ�Ϊ�������ĸ߶�
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}

//����
TreeNode* AVLTree::insertpri(TreeNode* node,T x)
{
    if(node==NULL)//����ڵ�Ϊ��,���ڴ˽ڵ㴦����x��Ϣ
    {
        node=new TreeNode(x);
    }
    else if(node->data > x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
    {
        node->lson= insertpri(node->lson,x);
    }
    else if(x>node->data)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
    {
        node->rson= insertpri(node->rson,x);
    }
    else ++(node->freq);//������,�Ͱ�Ƶ�ʼ�1
    node->hgt=Max(height(node->lson),height(node->rson))+1;
    return node;
}
//����ӿ�
void AVLTree::insert(T x)
{
    root=insertpri(root,x);
}

//ɾ��
TreeNode* AVLTree::Deletepri(TreeNode* node,T x)
{
    if(node==NULL) return NULL;//û���ҵ�ֵ��x�Ľڵ�
    if(x < node->data)
    {
         node->lson= Deletepri(node->lson,x);//���xС�ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
    }
    else if(x > node->data)
    {
         node->rson= Deletepri(node->rson,x);//���x���ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
    }
    else//������,�˽ڵ����Ҫɾ���Ľڵ�
    {
        if(node->lson&&node->rson)//�˽ڵ�����������
        {
            if( height(node->lson)>height(node->rson) )//���������������ߣ�
            {
                TreeNode* temp=node->lson;
                while(temp&&temp->rson) temp=temp->rson;
                node->data=temp->data;
                node->freq=temp->freq;
                node->lson=Deletepri(node->lson,temp->data);
            }
            else//������ȣ�������������������
            {
                TreeNode* temp=node->rson;
                while(temp&&temp->lson) temp=temp->lson;
                node->rson=Deletepri(node->rson, temp->data);
            }
        }
        else//�˽ڵ���1����0������
        {
            TreeNode* temp=node;
            node=(node->lson!=NULL) ? node->lson : node->rson;
            delete(temp);
        }
    }
    return node;
}
//ɾ���ӿ�
void AVLTree::Delete(T x)
{
    root=Deletepri(root,x);
}

int place=0,book=0;
//�����������
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
