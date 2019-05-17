#include<stdio.h>  
int main()
{   int p=1,n=1,m=1,i,temp,sum,Msum;  
    scanf("%d",&temp);
    Msum=sum=temp;
    for(i=2;i<=7;i++)
    {    scanf("%d",&temp);
         sum+=temp;  
         if(sum>Msum)  {Msum=sum;n=p;m=i;}
         if(sum<=0)  {sum=0;p=i+1;}
    }
    if(Msum<=0)  printf("won't buy!");
    else printf("%d %d %d",Msum,n,m);
    return 0;
}  