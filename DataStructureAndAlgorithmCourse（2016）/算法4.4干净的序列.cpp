#include<iostream>
using namespace std;
#define MAX(a,b) (a>b?a:b)
int main()  
{  int n,a[10005],k,m,temp,p1,p2,count=0,i;
    memset(a,0,sizeof(a));//数组a初始化
    cin>>n>>k>>m;
    for(i=1;i<=n;i++)    cin>>a[i];
    
    for(i=1;i<=n;i++)
    {     temp=a[i];
          p1=i-1;p2=i+1;
    while(p1>=1&&a[i]<=a[p1]&&a[p1]<=a[i]+m)
         {      temp=MAX(a[p1],temp);
                 p1--;
         }
    while(p2<=n&&a[i]<=a[p2]&&a[p2]<=a[i]+m) 
         {      temp=MAX(a[p2],temp);
         	    p2++;
         }
       if(temp>=a[i]+k)
             count=MAX(count,p2-p1-1);
   }
   
   cout<<count<<endl;
   return 0;
}
/*
input
5 0 0
1 1 1 1 1
output
5

input
6 0 3
3 1 2 3 4 5
output
5

input
6 2 5
7 5 8 6 3 2
output
5
*/