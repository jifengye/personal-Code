//算法11.2girigirieye打靶
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
typedef struct minheap //堆的大小，上限，放元素数组的地址 
{
	int last,maxsize;
	SetItem *heap;
}Minheap;

Heap MinHeapInit(int HeapSize) //创建上限HeapSiae的空堆(开空间)
{
	Heap H=new struct minheap;
	H->maxsize=HeapSize;
	H->heap=new SetItem[H->maxsize]; //开maxsize大小的连续的空间，作为数组 
	H->last=0;
	return H;
}

int HeapInsert(SetItem x, Heap H) //在堆H中插入元素x 
{
	if(H->last==H->maxsize) return -1; //堆已满 
	
	H->last++; //堆大小加 1 
	int p=H->last; //从堆底往前搜索 
	while(p!=1 && x>H->heap[p/2])
	{
	    H->heap[p]=H->heap[p/2];
	    p/=2;
	} 
	H->heap[p]=x;
	return p; 
}

SetItem DeleteMin(Heap H) //删除堆H的堆顶 
{
	if(H->last==0) return 0; //堆已空 
	
	SetItem x=H->heap[1],  y=H->heap[H->last]; //用堆底y填补删除堆顶x出现的空缺 
	H->last--; //堆大小减 1 
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