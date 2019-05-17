//�㷨10.4ħ����ŮС��֮���״��(AVL) 
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
		void intree(TreeNode* node,T x);//�������
		void posttree(TreeNode* node); //���� 
        void leveltree(TreeNode* node);//��α��� 
        int height(TreeNode* node);//�����ĸ߶�
        TreeNode* SingRotateLeft(TreeNode* k2);//��������µ���ת
        TreeNode* SingRotateRight(TreeNode* k2);//��������µ���ת
        TreeNode* DoubleRotateLR(TreeNode* k3);//��������µ���ת
        TreeNode* DoubleRotateRL(TreeNode* k3);//��������µ���ת 

    public:
        AVLTree():root(NULL){}
        void insert(T x);//����ӿ�
        void Delete(T x);//ɾ���ӿ�
        void preorder(); //ǰ������ӿ�   
        void inorder(T x); //��������ӿ� 
        void postorder(); //��������ӿ� 
        void levelorder(); //��α����ӿ� 

};

//�����Խڵ�Ϊ�������ĸ߶�
int AVLTree::height(TreeNode* node)
{
    if(node!=NULL) return node->hgt;
    return -1;
}


//��������µ���ת
TreeNode* AVLTree::SingRotateLeft(TreeNode* k2)
{
    TreeNode* k1=k2->lson;
    k2->lson=k1->rson;
    k1->rson=k2;

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1; 
    k1->hgt=Max(height(k1->lson),k2->hgt)+1;
    
    return k1;
}

//��������µ���ת
TreeNode* AVLTree::SingRotateRight(TreeNode* k2)
{   
    TreeNode *k1=k2->rson;
    k2->rson=k1->lson;
    k1->lson=k2;           

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt=Max(height(k1->rson),k2->hgt)+1;
    
    return k1;
}

//�����������ת
TreeNode* AVLTree::DoubleRotateLR(TreeNode* k3)
{
    k3->lson=SingRotateRight(k3->lson);
    return SingRotateLeft(k3);
}

//�����������ת
TreeNode* AVLTree::DoubleRotateRL(TreeNode* k3)
{
    k3->rson=SingRotateLeft(k3->rson);
    return SingRotateRight(k3);
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
        if(2==height(node->lson)-height(node->rson))
            if(node->lson->data>x)
                node=SingRotateLeft(node);
            else
                node=DoubleRotateLR(node);
    }
    else if(x>node->data)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
    {
        node->rson= insertpri(node->rson,x);
        if(2==height(node->rson)-height(node->lson))//����߶�֮��Ϊ2�Ļ���ʧȥ��ƽ��,��Ҫ��ת
            if(x>node->rson->data)
				node=SingRotateRight(node);
            else
                node=DoubleRotateRL(node);
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
         if(2==height(node->rson)-height(node->lson))
            if(node->rson->lson!=NULL&&(height(node->rson->lson)>height(node->rson->rson)) )
                node=DoubleRotateRL(node);
            else
                node=SingRotateRight(node);
    }
    else if(x > node->data)
    {
         node->rson= Deletepri(node->rson,x);//���x���ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
         if(2==height(node->lson)-height(node->rson))
            if(node->lson->rson!=NULL&& (height(node->lson->rson)>height(node->lson->lson) ))
                node=DoubleRotateLR(node);
            else
                node=SingRotateLeft(node);
    }
    else//������,�˽ڵ����Ҫɾ���Ľڵ�
    {
        if(node->lson&&node->rson)//�˽ڵ�����������
        {
            if( height(node->lson)>height(node->rson) )//���������������ߣ�
            {
                //(01)�ҳ�tree���������е����ڵ�
                //(02)�������ڵ��ֵ��ֵ��tree��
                //(03)ɾ�������ڵ㡣
                //����������"tree�������������ڵ�"��"tree"������
                //�������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
                TreeNode* temp=node->lson;
                while(temp&&temp->rson) temp=temp->rson;
                node->data=temp->data;
                node->freq=temp->freq;
                node->lson=Deletepri(node->lson,temp->data);
            }
            else//������ȣ�������������������
            {
                //��(01)�ҳ�tree���������е���С�ڵ�
                //(02)������С�ڵ��ֵ��ֵ��tree��
                //(03)ɾ������С�ڵ㡣
                //����������"tree������������С�ڵ�"��"tree"������
                //�������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
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
    //if(node) node->hgt=Max(height(node->lson),height(node->rson))+1;
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
