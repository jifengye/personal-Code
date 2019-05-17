#include<iostream>
#include<cstdio>
#define Swap(a,b) a+=b; b=a-b; a-=b
using namespace std;


void insertnode(int *A,int p)//(在p位置放入新元素后)调整成堆(从下往上)；
{   int pp=p/2;
    while(pp!=0 && A[pp]>A[p])
    {   
	    Swap(A[pp],A[p]);
        p=pp;pp/=2;
    }
}


void delnode(int *A,int n)//删除头节点并调整成堆(从上往下)，n是数组A的大小 
{   
    A[1]=A[n];n--;//删除头节点； 

    int  p=1,left=2,right=3,ps;//调整成堆； 
    while(left<=n)
    {   
	    if(right<=n && A[left]>A[right]) ps=right; //选出p最小儿子;
        else                             ps=left;
        
        if(A[p]>A[ps])
        {    
		     Swap(A[p],A[ps]);
             p=ps;left=2*p;right=2*p+1;
        }
		else break;
    }
}


int main()
{
    int i,N,mons[10010]={0};
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>mons[i];
        insertnode(mons,i);
    }
    
    int tempk=0,k=0;
    while(N>1)
    {
        tempk=mons[1];
        delnode(mons,N);N--;
        tempk+=mons[1];
        delnode(mons,N);
        
        mons[N]=tempk;
        insertnode(mons,N);
        
        k+=tempk;
    }
    cout<<k<<endl;
    return 0;
}
