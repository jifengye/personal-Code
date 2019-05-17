//�㷨11.4Fresh Meat 
#include<iostream> 
#include<cstdio>
using namespace std;
const int N=10001;
typedef int SetItem;

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
	if(H->last==H->maxsize) return -1; //������ 
	
	H->last++; //�Ѵ�С�� 1 
	int p=H->last; //�Ӷѵ���ǰ���� 
	while(p!=1 && x>H->heap[p/2])
	{
	    H->heap[p]=H->heap[p/2];
	    p/=2;
	} 
	H->heap[p]=x;
	return p; 
}

SetItem DeleteMin(Heap H) //ɾ����H�ĶѶ� 
{
	if(H->last==0) return -1; //���ѿ� 
	
	SetItem x=H->heap[1],  y=H->heap[H->last]; //�öѵ�y�ɾ���Ѷ�x���ֵĿ�ȱ 
	H->last--; //�Ѵ�С�� 1 
	int ps=2;
	while(ps<=H->last)  
	{
		if(ps<H->last && H->heap[ps+1]>H->heap[ps]) ps+=1; 
		    
		if(y>H->heap[ps]) break;
		H->heap[ps/2]=H->heap[ps];  
		ps*=2; 
	}
	H->heap[ps/2]=y;
	return x;
}

int main()
{
	int i,n,sum,a,count=0;
	Heap H=MinHeapInit(N);
	scanf("%d%d",&n,&sum);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a);
		sum-=a;
		HeapInsert(a,H);
		while(sum<=0)
		{
			sum+=DeleteMin(H)*2;
			count++;			
		}
	}
	printf("%d\n",count);
	return 0;
}
/*
7 8
5 2 3 3 1 4 6
*/ 
