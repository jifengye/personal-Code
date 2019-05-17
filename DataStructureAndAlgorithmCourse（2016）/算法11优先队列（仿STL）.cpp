//�㷨11���ȶ���(�ѵ�ʵ��)
#include<iostream> 
#include<cstdio>
using namespace std;
struct Node
{
	int p,d;
}; 

/****************************/
typedef Node SetItem;
const int MAX=999999;
//�ṹ��ĸ��Ʋ�������
bool MinHeapcmp(const SetItem &a,const SetItem &b) //��С�� 
{
	return a.p<b.p;
}
class MinHeap
{
public:
	int last,maxsize;
	SetItem *heap;
	
	MinHeap() {last=0;maxsize=MAX;heap=new SetItem[MAX];}
	MinHeap(int size) {last=0;maxsize=size;heap=new SetItem[size];}
	int insert(SetItem x);   //�ڶ�H�в���Ԫ��x 
	SetItem del( );  //ɾ����H�ĶѶ�
	bool emp() {return last==0;}
};
int MinHeap::insert(SetItem x) 
{
	if(last==maxsize)  exit(0); //������ 
	int p=++last; //�Ѵ�С�� 1���Ӷѵ���ǰ���� 
	while(p!=1 && MinHeapcmp(x,heap[p/2]))
	{
	    heap[p]=heap[p/2];
	    p/=2;
	} 
	heap[p]=x;
	return p; 
}
SetItem MinHeap::del( )  
{
	if(last==0) exit(0); //���ѿ� 
	SetItem x=heap[1],  y=heap[last--]; //�öѵ�y�ɾ���Ѷ�x���ֵĿ�ȱ���Ѵ�С�� 1 
	int ps=2;
	while(ps<=last) //��������Ѱ�Ҳ���y�ĺ���λ��p(Ҫ��y��p���������Ӷ�С��pû����) 
	{
		if(ps<last && MinHeapcmp(heap[ps+1],heap[ps])) ps+=1; //ѡ��p��С����;
		    
		if(MinHeapcmp(y,heap[ps])) break;
		heap[ps/2]=heap[ps];  
		ps*=2; 
	}
	heap[ps/2]=y;//pλ��Ԫ�ػḲ�ǵ��丸���ϣ�����ʹpλ��Ԫ��ɥʧ
	return x;
}


bool MaxHeapcmp(const SetItem &a,const SetItem &b) //���� 
{
	return a.p>b.p;
}
class MaxHeap
{
public:
	int last,maxsize;
	SetItem *heap;
	
	MaxHeap() {last=0;maxsize=MAX;heap=new SetItem[MAX];}
	MaxHeap(int size) {last=0;maxsize=size;heap=new SetItem[size];}
	int insert(SetItem x);   //�ڶ�H�в���Ԫ��x 
	SetItem del( );  //ɾ����H�ĶѶ�
	bool emp() {return last==0;}
};
int MaxHeap::insert(SetItem x) 
{
	if(last==maxsize)  exit(0); //������ 
	int p=++last; //�Ѵ�С�� 1���Ӷѵ���ǰ���� 
	while(p!=1 && MaxHeapcmp(x,heap[p/2]))
	{
	    heap[p]=heap[p/2];
	    p/=2;
	} 
	heap[p]=x;
	return p; 
}
SetItem MaxHeap::del( )  
{
	if(last==0) exit(0); //���ѿ� 
	SetItem x=heap[1],  y=heap[last--]; //�öѵ�y�ɾ���Ѷ�x���ֵĿ�ȱ���Ѵ�С�� 1 
	int ps=2;
	while(ps<=last) //��������Ѱ�Ҳ���y�ĺ���λ��p(Ҫ��y��p���������Ӷ�С��pû����) 
	{
		if(ps<last && MaxHeapcmp(heap[ps+1],heap[ps])) ps+=1; //ѡ��p��С����;
		    
		if(MaxHeapcmp(y,heap[ps])) break;
		heap[ps/2]=heap[ps];  
		ps*=2; 
	}
	heap[ps/2]=y;//pλ��Ԫ�ػḲ�ǵ��丸���ϣ�����ʹpλ��Ԫ��ɥʧ
	return x;
}
/*********************************/

int main()//������� 
{
	MinHeap minh;
	MaxHeap maxh; 
	Node a;
	int i,n;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{   
	    scanf("%d %d",&a.p,&a.d);
	    minh.insert(a);
	    maxh.insert(a);
	}
	for(i=1; i<=n; i++)
	{
		a=minh.del();
		printf("%d %d\n",a.p,a.d);
	}
	for(i=1; i<=n; i++)
	{
		a=maxh.del();
		printf("%d %d\n",a.p,a.d);
	}
	return 0;
}
