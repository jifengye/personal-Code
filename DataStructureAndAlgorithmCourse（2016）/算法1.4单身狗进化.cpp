#include<stdio.h>
int main()
{  int n,i=1;
   double sum=1;
   scanf("%d",&n);
   while(n)
   {  sum*=n;
      while(sum>=10.0)
      {  i++;
         sum/=10.0;
      }
      n--;
   }
   printf("%d",i);
   return 0;
}
