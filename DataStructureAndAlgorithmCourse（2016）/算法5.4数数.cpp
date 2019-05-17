#include<iostream>
using namespace std;
int a[200003],N;

void quicksort(int left,int right)
{  int i,j,t,temp;
   if(left>right) return;//递归结束标志 
   
   temp=a[left];//temp存基准数
    
   i=left;//调换基准数 
   j=right;
   while(i!=j)
   {   while(a[j]>=temp && i<j)  j--;
       while(a[i]<=temp && i<j)  i++; 
	   if(i<j)
	   {   t=a[j];
	       a[j]=a[i];
	       a[i]=t;
		}
	}
	
	a[left]=a[i];//基准数归位 
	a[i]=temp;
   
   quicksort(left,i-1);
   quicksort(i+1,right);
}

int main()
{   cin>>N;
    int i,count;
    for(i=0;i<N;i++)   cin>>a[i];
	
	quicksort(0,N-1);
	
	for(i=count=1,a[N]=-1;i<=N;i++)
	{   if(a[i-1]==a[i])   {count++;continue;}
	    cout<<a[i-1]<<' '<<count<<endl;	    
		count=1;
	}
	return 0;
}

/*
intput
8
2 4 2 4 5 100 2 100
output
2 3
4 2
5 1
100 2
*/
