#include<stdio.h>  
int main()  
{  int n,a[100000],sum,Msum=0;  
   scanf("%d",&n);  
   for(int i=0;i<n;i++)  
      scanf("%d",&a[i]);  
   for(int i=0;i<n;i++)  
       for(int j=i;j<n;j++)  
       {     sum=0;  
             for(int k=i;k<=j;k++)  sum+=a[k];  
             if(Msum<sum)  Msum=sum;  
       } 
   printf("%d",Msum);  
   return 0;  
} 

