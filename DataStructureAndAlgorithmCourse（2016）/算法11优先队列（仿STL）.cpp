//算法11优先队列(堆的实现)
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
//结构体的复制不用重载
bool MinHeapcmp(const SetItem &a,const SetItem &b) //最小堆 
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
	int insert(SetItem x);   //在堆H中插入元素x 
	SetItem del( );  //删除堆H的堆顶
	bool emp() {return last==0;}
};
int MinHeap::insert(SetItem x) 
{
	if(last==maxsize)  exit(0); //堆已满 
	int p=++last; //堆大小加 1并从堆底往前搜索 
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
	if(last==0) exit(0); //堆已空 
	SetItem x=heap[1],  y=heap[last--]; //用堆底y填补删除堆顶x出现的空缺并堆大小减 1 
	int ps=2;
	while(ps<=last) //从上往下寻找插入y的合适位置p(要求y比p的两个儿子都小或p没儿子) 
	{
		if(ps<last && MinHeapcmp(heap[ps+1],heap[ps])) ps+=1; //选出p最小儿子;
		    
		if(MinHeapcmp(y,heap[ps])) break;
		heap[ps/2]=heap[ps];  
		ps*=2; 
	}
	heap[ps/2]=y;//p位置元素会覆盖到其父亲上，不会使p位置元素丧失
	return x;
}


bool MaxHeapcmp(const SetItem &a,const SetItem &b) //最大堆 
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
	int insert(SetItem x);   //在堆H中插入元素x 
	SetItem del( );  //删除堆H的堆顶
	bool emp() {return last==0;}
};
int MaxHeap::insert(SetItem x) 
{
	if(last==maxsize)  exit(0); //堆已满 
	int p=++last; //堆大小加 1并从堆底往前搜索 
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
	if(last==0) exit(0); //堆已空 
	SetItem x=heap[1],  y=heap[last--]; //用堆底y填补删除堆顶x出现的空缺并堆大小减 1 
	int ps=2;
	while(ps<=last) //从上往下寻找插入y的合适位置p(要求y比p的两个儿子都小或p没儿子) 
	{
		if(ps<last && MaxHeapcmp(heap[ps+1],heap[ps])) ps+=1; //选出p最小儿子;
		    
		if(MaxHeapcmp(y,heap[ps])) break;
		heap[ps/2]=heap[ps];  
		ps*=2; 
	}
	heap[ps/2]=y;//p位置元素会覆盖到其父亲上，不会使p位置元素丧失
	return x;
}
/*********************************/

int main()//排序输出 
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
