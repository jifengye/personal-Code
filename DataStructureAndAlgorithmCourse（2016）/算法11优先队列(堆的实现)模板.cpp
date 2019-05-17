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
#define key(a)  a.p
#define less(a,b)  key(a)<key(b)  //����a.p<b.p 
#define lessequ(a,b)  key(a)<=key(b)
//�ṹ��ĸ��Ʋ�������
 
typedef struct minheap* Heap;
typedef struct minheap //�ѵĴ�С�����ޣ���Ԫ������ĵ�ַ 
{
	int last,maxsize;
	SetItem *heap;
}Minheap;

Heap MinHeapInit(int HeapSize) //��������HeapSiae�Ŀն�(���ռ�)
{
	Heap H=new struct minheap;
	H->maxsize=HeapSize;
	H->heap=new SetItem[H->maxsize]; //��maxsize��С�������Ŀռ䣬��Ϊ���� 
	H->last=0;
	return H;
}

int HeapInsert(SetItem x, Heap H) //�ڶ�H�в���Ԫ��x 
{
	if(H->last==H->maxsize)  exit(0); //������ 
	
	H->last++; //�Ѵ�С�� 1 
	int p=H->last; //�Ӷѵ���ǰ���� 
	while(p!=1 && less(x,H->heap[p/2]))
	{
	    H->heap[p]=H->heap[p/2];
	    p/=2;
	} 
	H->heap[p]=x;
	return p; 
}

SetItem DeleteMin(Heap H) //ɾ����H�ĶѶ� 
{
	if(H->last==0) exit(0); //���ѿ� 
	
	SetItem x=H->heap[1],  y=H->heap[H->last]; //�öѵ�y�ɾ���Ѷ�x���ֵĿ�ȱ 
	H->last--; //�Ѵ�С�� 1 
	int ps=2;
	while(ps<=H->last) //��������Ѱ�Ҳ���y�ĺ���λ��p(Ҫ��y��p���������Ӷ�С��pû����) 
	{
		if(ps<H->last && less(H->heap[ps+1],H->heap[ps])) ps+=1; //ѡ��p��С����;
		    
		if(less(y,H->heap[ps])) break;
		H->heap[ps/2]=H->heap[ps];  
		ps*=2; 
	}
	H->heap[ps/2]=y;//pλ��Ԫ�ػḲ�ǵ��丸���ϣ�����ʹpλ��Ԫ��ɥʧ
	return x;
}

Heap BuildHeap(SetItem a[], int size, int arraysize) //������arraysize����Сsize������a[]�����ɶ� 
{
	Heap H=MinHeapInit(arraysize);
	H->heap=a; //������ԶѸ�ֵ 
	H->last=size; //��ֵ��Ѵ�С�������Сsize 
    
	int p,ps;
	SetItem y;
	for(p=H->last/2; p>=1; p--) //�Ӷѵ����ڶ�����ǰ(�Ȱ���С��֧���ɶѣ�һ���������֧) 
	{
		y=H->heap[p];
		
		ps=2*p;
		while(ps<=H->last)
		{
			if(ps<H->last && less(H->heap[ps+1],H->heap[ps])) ps+=1; //ѡ��p��С����;
		    
		    if(less(y,H->heap[ps])) break;
		    H->heap[ps/2]=H->heap[ps];  
		    ps*=2;
		}
	    H->heap[ps/2]=y; 
	}	
	return H;
} 
/*********************************/


int main()//������� 
{
	Heap H;
	Node a[10];
	int i,n;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	   scanf("%d %d",&a[i].p,&a[i].d);
	BuildHeap(a,n,10);
	for(i=1; i<=n; i++)
	   printf("%d %d\n",a[i].p,a[i].d);
	return 0;
}
