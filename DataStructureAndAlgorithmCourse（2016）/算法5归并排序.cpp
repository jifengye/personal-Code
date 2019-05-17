#include <iostream>
using namespace std;
int A[100005],B[100005];

void merge(int low, int mid, int top)
{   
    int i=low, j=mid+1, k=low;
    while(i<=mid && j<=top)
       if(A[i]>A[j])  B[k++]=A[j++];
       else           B[k++]=A[i++];
    while(i<=mid)   B[k++]=A[i++];
    while(j<=top)   B[k++]=A[j++];
    for(i=low;i<=top;i++)   A[i]=B[i];
}

void mergesort(int low,int top)
{   
    if(low<top)
    {     int mid=(low+top)/2;
          mergesort(low,mid);    
          mergesort(mid+1,top);     
          merge(low,mid,top);
    }
}

int main()
{   int n,i;
    cin>>n;
    for(i=1;i<=n;i++)  cin>>A[i];
	   
    mergesort(1,n); 
	  
	for(i=1;i<=n;i++)  cout<<A[i]<<' ';  
    return 0;
}
