#include <iostream>
using namespace std;

void merge(int *A,int low, int mid, int top)
{   int i,j,k,B[top-low+2];
    for(i=mid+1;i>low;i--)    B[i-1]=A[i-1];
    for(j=mid;j<top;j++)       B[top+mid-j]=A[j+1];
    for(k=low;k<=top;k++)       
           if(B[i]<=B[j])      A[k]=B[i++];
            else                  A[k]=B[j--];
}

void mergesort(int *A,int low,int top)
{   if(low+1>=top)    //小序列直接交换
    {     if(A[low]>A[top])
          {      int temp=A[low];
                 A[low]=A[top];
                 A[top]=temp;
          }
    }
    else                       //大序列递归
    {     int mid=(low+top)/2;
          mergesort(A,low,mid);    
          mergesort(A,mid+1,top);     
          merge(A,low,mid,top);
    }
}

int main()
{   int A[500],n,i;
     cin>>n;
     for(i=1;i<=n;i++)  cin>>A[i];   
     mergesort(A,1,n);   
     for(i=1;i<=n;i++)  cout<<A[i]<<' ';    
     return 0;
}

/*
input
10
5 6 7 4 1 3 2 9 8 10
*/