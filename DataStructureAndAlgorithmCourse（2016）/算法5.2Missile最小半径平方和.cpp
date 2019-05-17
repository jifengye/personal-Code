#include<iostream>
using namespace std;
int a[100005],b[100005];

#define MAX(a,b)  (a>b?a:b)
#define MIN(a,b)   (a<b?a:b)
void quicksort(int left,int right)//快速排序
{     int i,j,t,temp;
      if(left>right) return;//递归结束标志 
   
      temp=a[left];//temp存基准数
    
       i=left;//调换基准数 
       j=right;
      while(i!=j)
      {    while(a[j]>=temp && i<j)  j--;
            while(a[i]<=temp && i<j)  i++; 
            if(i<j)
           {     t=a[j]; a[j]=a[i]; a[i]=t;
                  t=b[j]; b[j]=b[i]; b[i]=t;
            }
        }
 
      a[left]=a[i];//基准数归位 
      a[i]=temp;
      temp=b[left];b[left]=b[i];b[i]=temp;
   
      quicksort(left,i-1);
      quicksort(i+1,right);
}
   
int main()
{    int x1,y1,x2,y2,n;
     cin>>x1>>y1>>x2>>y2>>n;
     int x,y,i,maxb=0,minr;
     for(i=1;i<=n;i++)
     {     cin>>x>>y;
           a[i]=(x-x1)*(x-x1)+(y-y1)*(y-y1);
           b[i]=(x-x2)*(x-x2)+(y-y2)*(y-y2);
     }
     quicksort(1,n);
     for(i=n-1,a[0]=0,minr=a[n];i>=0;i--)
     {     maxb=MAX(maxb,b[i+1]);
            minr=MIN(minr,a[i]+maxb);
     }
     cout<<minr<<endl;
     return 0;
}

/*
input
0 0 6 0
5
-4 -2
-2 3
4 0
6 -2
9 1
output
30

input
0 0 100 0
3
-1 0
49 0
51 0
output
2601
*/