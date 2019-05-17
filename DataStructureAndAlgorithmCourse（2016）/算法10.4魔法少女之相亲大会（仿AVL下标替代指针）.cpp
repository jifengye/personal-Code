//�㷨10.4ħ����Ů֮���״�ᣨ��AVL�±����ָ�룩
//��ת�ж�����������Ͳ���ʱ��ά��ƽ��
//��λ������ʱ�����������һ�Σ���Լʱ�� 
//ʹ�����ô��ݣ�������ʽ�����ӽڵ����� 
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
using namespace std;
const int N=100001;
  
struct Node  
{  
    int data; //ֵ 
	int lson; //���� 
	int rson; //���� 
	int num; //�Լ��������ܸ��� 
	int rnd;  //�洢����� (�������ת��ת) 
	int frg;  //Ƶ�� 
}node[N];
int size=0,root; 

//���½����Ϣ  
void update(int k)
{  
    node[k].num=node[node[k].lson].num+node[node[k].rson].num+node[k].frg;  
} 
 
void rturn(int &k2)  //���� 
{  
    int k1=node[k2].lson;  
    node[k2].lson=node[k1].rson;  
    node[k1].rson=k2;  
    node[k1].num=node[k2].num;  
    update(k2);  
    k2=k1; //��Ϊ��������һ�������� 
}  

void lturn(int &k2) //���� 
{  
    int k1=node[k2].rson;  
    node[k2].rson=node[k1].lson;  
    node[k1].lson=k2;  
    node[k1].num=node[k2].num;  
    update(k2);  
    k2=k1;  
}  

void insert(int &k,int x)  
{  
    if(k==0)  
    {  
        k=++size;  
        node[k].num=node[k].frg=1;  
        node[k].data=x;  
        node[k].rnd=rand();
        return;  
    }  
    node[k].num++;  
    if(node[k].data==x)node[k].frg++;//ÿ�����˳���¼����ýڵ���ֵͬ�����ĸ���  
    else if(x>node[k].data)  
    {  
        insert(node[k].rson,x);  
        if(node[node[k].rson].rnd<node[k].rnd)lturn(k);//ά��������  
    }  
    else  
    {  
        insert(node[k].lson,x);  
        if(node[node[k].lson].rnd<node[k].rnd)rturn(k);  
    }  
}

void del(int &k,int x)  
{  
    if(k==0)return;
    if(node[k].data==x)  
    {  
        if(node[k].frg>1)  
        {  
            node[k].frg--;  
            node[k].num--;  
            return;//����ֹ��ֵͬ�ĸ����ж����ɾȥһ��  
        }  
        if(node[k].lson*node[k].rson==0)k=node[k].lson+node[k].rson;//��һ������Ϊ��  
        else if(node[node[k].lson].rnd<node[node[k].rson].rnd)  
            rturn(k),del(k,x);  
        else lturn(k),del(k,x);  
    }  
    else if(x>node[k].data)   node[k].num--,del(node[k].rson,x);  
    else                 node[k].num--,del(node[k].lson,x);  
} 

//��ѯxֵ��λ��
int query_rank(int k,int x)  
{  
    if(k==0) return 0;
	 
    if(x<node[k].data)  
	    return query_rank(node[k].lson,x);
    else if(x>node[k].data)  
        return node[node[k].lson].num+node[k].frg+query_rank(node[k].rson,x);  
    else   
	    return node[node[k].lson].num+1;
}  

//��ѯxλ�õ�ֵ
int query_num(int k,int x)  
{  
    if(k==0) return 0;
    
    if(x<=node[node[k].lson].num)  
        return query_num(node[k].lson,x);  
    else if(x>node[node[k].lson].num+node[k].frg)  
        return query_num( node[k].rson, x-node[node[k].lson].num-node[k].frg);  
    else 
	    return node[k].data;  
}  

int main()  
{  

    char opt[4];  
    int n,x;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%s",opt);  
        if(opt[0] == 'J')//in  
        {  
            scanf("%d",&x);  
            insert(root,x);  
        }  
        else if(opt[0] == 'X')//out  
        {  
            scanf("%d",&x);  
            del(root,x);  
        }  
        else if(opt[0] == 'W')//output position  
        {             
            scanf("%d",&x);  
            printf("%d\n",query_num(root,x));  
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
*/
