#include<stdio.h>
int main()  
{  int n,a[100005]={0},temp,p1,p2;
    __int64 sum,Msum=0;
    scanf("%d",&n);
   for(int z=1;z<=n;z++)    scanf("%d",&a[z]);
   for(int i=1;i<=n;i++)
   {    if(a[i]==a[i-1])   continue;
         temp=a[i];
         p1=i;p2=i+1;
         sum=0;
         while(p1>=1&&a[p1]>=temp)
                sum+=a[p1--];
         while(p2<=n&&a[p2]>=temp)
                sum+=a[p2++];
          sum*=temp;
          if(Msum<sum)   Msum=sum;
   }
   printf("%I64d",Msum);
   return 0;
}
//贪心算法，节约时间