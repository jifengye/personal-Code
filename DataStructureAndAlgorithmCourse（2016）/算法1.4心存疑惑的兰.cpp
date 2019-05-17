#include<stdio.h>
int main()
{  int n,i,j;
   long a[1000],temp;
   scanf("%d",&n);
   for(i=0;i<n;i++)  scanf("%d",&a[i]);
   for(i=0;i<n;i++)
     for(j=i;j<n;j++)
       if(a[i]>a[j]) 
	   {   temp=a[i];
	       a[i]=a[j];
	       a[j]=temp;
	   }
   for(i=1;i<=n;i++)
     if(i!=a[i-1])  break;
   printf("%d",i);
   return 0;	   
}
