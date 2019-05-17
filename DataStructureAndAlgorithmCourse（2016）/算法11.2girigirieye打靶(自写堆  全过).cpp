//�㷨11.2girigirieye���(��д��  ȫ��)
#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000001;
typedef int SetItem;
struct Target
{
	int time;
	int value;
}tar[N];

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
	if(H->last==0) return 0; //���ѿ� 
	
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

bool cmp(const Target &a,const Target &b)
{
	return a.time>b.time;
}

int main()
{
	int i,n;
    scanf("%d",&n);
	for(i=1; i<=n; i++)
	   scanf("%d %d",&tar[i].time,&tar[i].value);
	
    sort(tar+1, tar+n+1, cmp);
    
    int j=1,sum=0;
    Heap H=MinHeapInit(n);
    for(i=tar[1].time; i>=1; i--) 
    {
    	for(; j<=n && tar[j].time==i; j++) 
    	{
    		 HeapInsert(tar[j].value,H); 
		}
    	sum+=DeleteMin(H);
	}
	printf("%d\n",sum);
	return 0;
}
/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1

*/

