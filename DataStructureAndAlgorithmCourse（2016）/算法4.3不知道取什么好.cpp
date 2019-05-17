#include <iostream>
using namespace std;
int A[1005],B[1005];

void merge(int low, int mid, int top)
{   int i,j,k;
    for(i=mid+1;i>low;i--)    B[i-1]=A[i-1];
    for(j=mid;j<top;j++)       B[top+mid-j]=A[j+1];
    for(k=low;k<=top;k++)       
           if(B[i]>=B[j])      A[k]=B[i++];
            else                  A[k]=B[j--];
}

void mergesort(int low,int top)
{   if(low+1>=top)    //小序列直接交换
    {     if(A[low]<A[top])
          {      int temp=A[low];
                 A[low]=A[top];
                 A[top]=temp;
          }
    }
    else                       //大序列递归
    {     int mid=(low+top)/2;
          mergesort(low,mid);    
          mergesort(mid+1,top);     
          merge(low,mid,top);
    }
}

int main()
{   int a[1005],n,m,i,j,count=0;
     cin>>n>>m;
     for(i=0;i<n;i++)  {cin>>a[i];A[i]=a[i];}
     mergesort(0,n-1);   
     for(i=j=0;i<n;i++)
     {     while(A[i]!=a[j])    j=(j+1)%n;
           a[j]==0;
           count++;
           if(j==m-1)   
                 {cout<<count<<endl;return 0;}
           j=(j+1)%n;
     }
     return 0;
}

/*
input
5 2
1 2 3 4 5
output
4

input
6 1
2 2 8 2 2 2
output
5
*/