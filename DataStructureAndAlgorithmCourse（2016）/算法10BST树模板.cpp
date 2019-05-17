//�㷨10����������(BST) 
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
        void pretree(TreeNode* node); //ǰ�� 
		void intree(TreeNode* node);//�������
		void posttree(TreeNode* node); //���� 
        void leveltree(TreeNode* node);//��α��� 
        int height(TreeNode* node);//�����ĸ߶�

    public:
        AVLTree():root(NULL){}
        void insert(T x);//����ӿ�
        void Delete(T x);//ɾ���ӿ�
        void preorder(); //ǰ������ӿ�   
        void inorder(); //��������ӿ� 
        void postorder(); //��������ӿ� 
        void levelorder(); //��α����ӿ� 

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
    if(node) node->hgt=Max(height(node->lson),height(node->rson))+1;
    return node;
}
//ɾ���ӿ�
void AVLTree::Delete(T x)
{
    root=Deletepri(root,x);
}

//ǰ�����
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
	
//�����������
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

//������� 
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

//��α�������
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
