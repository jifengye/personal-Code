#include<stdio.h>
int main()
{   int i,j,k,n,a[10001],t=1;
    for(i=1;i<10000;i++) a[i]=i+1;
    scanf("%d",&n);
     while(t<=n)
    { for(j=t+a[t];j<10000;j+=a[t])  a[j]=0;
      for(j=1,k=0;a[j]<10000;j++)
               if(a[j])  a[++k]=a[j];
      t++;
    }
    printf("%d\n",a[n]);
    return 0;
}