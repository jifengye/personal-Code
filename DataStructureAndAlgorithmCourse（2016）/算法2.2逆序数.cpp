#include<stdio.h>
int a[505],n;

int del(int k)//反回并删除下标为k的元素
{      int book=a[k];
       for(int i=k;i<n;i++)   a[i]=a[i+1];
       return book;
}

int main()
{   int temp,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)  a[i]=i+1;
    while(n--)
    {    scanf("%d",&temp);
         printf("%d",del(temp));
         if(n)  printf(" ");
    }
    printf("\n");
    return 0;
}