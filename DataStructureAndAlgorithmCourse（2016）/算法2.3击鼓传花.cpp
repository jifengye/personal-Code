#include <stdio.h>
int main()
{
    int i,a[500]={0},n,m,k=0,out=1;
    scanf("%d %d", &n, &m);
    for(i=2;i<=n;i++)  a[i]=i;//给选手排序
    for(i=1;out<n-1;i++) 
    {   if(a[i])   k++;
         if(k==m)  {a[i]=0;k=0;out++;}
         if(i==n)  i=1;
     }
    for(i=1;a[i]==0;i++)  ;
    printf("%d\n",a[i]);
    return 0;
}