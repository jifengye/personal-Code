#include<iostream>
using namespace std;
int main()  
{  int n,a[100005],sum,MAXsum=0,t;  
   cin>>n;  
   for(int z=1;z<=n;z++)    cin>>a[z];
   for(int i=1;i<=n;i++)  
       for(int j=2;j<=n;j++)
       {     sum=0;
             t=i;
             for(int k=i;k<=j;k++)//i~j就是这几天
            {   sum+=a[k];
                 if(a[t]>a[k])   t=k; //寻找这几天刷题数最小值
             }
            sum*=a[t];
            if(MAXsum<sum)  MAXsum=sum;  
       }  
       cout<<MAXsum<<endl;  
       return 0;  
}
//问题花费时间太长同时int型数据不够大