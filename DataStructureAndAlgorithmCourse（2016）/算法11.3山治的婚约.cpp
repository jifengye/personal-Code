//算法11.3山治的婚约
#include<iostream>
#include<cstdio>
using namespace std;
const int N=10001;
const int Max=100000000;

struct Monkey
{
	int point;
	int dis;
	int init;
}M[N];

typedef Monkey SetItem;

/**********************************/
bool cmp(const Monkey &a, const Monkey &b)
{
	if(a.point==b.point) return a.init<b.init;
	return a.point<b.point;
}
//构造体间赋值不用另外定义
/**********************************/

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
	H->last++; //堆大小加 1 
	int p=H->last; //从堆底往前搜索 
	while(p!=1 && cmp(x,H->heap[p/2]))
	{
	    H->heap[p]=H->heap[p/2];
	    p/=2;
	} 
	H->heap[p]=x;
	return p; 
}

SetItem DeleteMin(Heap H) //删除堆H的堆顶 
{
	if(H->last==0) exit(0); //堆已空 
	
	SetItem x=H->heap[1],  y=H->heap[H->last]; //用堆底y填补删除堆顶x出现的空缺 
	H->last--; //堆大小减 1 
	int ps=2;
	while(ps<=H->last) //从上往下寻找插入y的合适位置p(要求y比p的两个儿子都小或p没儿子) 
	{
		if(ps<H->last && cmp(H->heap[ps+1],H->heap[ps])) ps+=1; //选出p最小儿子;
		    
		if(cmp(y,H->heap[ps])) break;
		H->heap[ps/2]=H->heap[ps];  
		ps*=2; 
	}
	H->heap[ps/2]=y;//p位置元素会覆盖到其父亲上，不会使p位置元素丧失
	return x;
}

Heap BuildHeap(SetItem a[], int size, int arraysize) //将上限arraysize，大小size的数组a[]调整成堆 
{
	Heap H=MinHeapInit(arraysize);
	H->heap=a; //用数组对堆赋值 
	H->last=size; //赋值后堆大小是数组大小size 

	int p,ps;
	SetItem y;
	for(p=H->last/2; p>=1; p--) //从堆倒数第二层往前(先把最小分支调成堆，一步步扩大分支) 
	{
		y=H->heap[p];
		
		ps=2*p;
		while(ps<=H->last)
		{
			if(ps<H->last && cmp(H->heap[ps+1],H->heap[ps])) ps+=1; //选出p最小儿子;
		    
		    if(cmp(y,H->heap[ps])) break;
		    H->heap[ps/2]=H->heap[ps];  
		    ps*=2;
		}
	    H->heap[ps/2]=y; 
	}	
	return H;
} 

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
	    scanf("%d%d",&M[i].point, &M[i].dis);
	    M[i].init=M[i].point;
	}
	Heap H=BuildHeap(M,n,n);
	
   int sum=0;
   for(i=1; i<n; i++)
   {
   	    DeleteMin(H);
   	    SetItem x=DeleteMin(H);
   	    x.point+=x.dis;
   	    HeapInsert(x,H);
   }
   printf("%d\n",DeleteMin(H).point);
   return 0;
}

/*
注意题目:当位置一样时是比较初始位置,而不是比较上一个位置 
*/

/*
8
1 1
2 2
6 6
3 3
5 5
4 4
7 7
8 8
output 24
*/ 

