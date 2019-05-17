#include<stdio.h>
int main()  
{  int n,a[100000],sum,Msum;  
   scanf("%d",&n);  
   for(int z=0;z<n;z++)    scanf("%d",&a[z]);
   Msum=a[0];
   for(int i=0;i<n;i++)  
       for(int j=i;j<n;j++)  
       {     sum=0;  
             for(int k=i;k<=j;k++)  sum+=a[k];  
             if(Msum<sum)  Msum=sum;  
       }  
   printf("%d",Msum);  
   return 0;  
}  