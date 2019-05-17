//�㷨11.3ɽ�εĻ�Լ
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
//������丳ֵ�������ⶨ��
/**********************************/

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
	H->last++; //�Ѵ�С�� 1 
	int p=H->last; //�Ӷѵ���ǰ���� 
	while(p!=1 && cmp(x,H->heap[p/2]))
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
		if(ps<H->last && cmp(H->heap[ps+1],H->heap[ps])) ps+=1; //ѡ��p��С����;
		    
		if(cmp(y,H->heap[ps])) break;
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
			if(ps<H->last && cmp(H->heap[ps+1],H->heap[ps])) ps+=1; //ѡ��p��С����;
		    
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
ע����Ŀ:��λ��һ��ʱ�ǱȽϳ�ʼλ��,�����ǱȽ���һ��λ�� 
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

