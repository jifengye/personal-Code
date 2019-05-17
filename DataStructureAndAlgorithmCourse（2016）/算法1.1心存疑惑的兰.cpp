#include<stdio.h>  
int main()  
{  
    int n,i,r,a[1000];
    scanf("%d",&n);  
    for(i=0;i<n;i++)   scanf("%d",&a[i]);
    for(r=1;r>0;r++)  
    {  
        for(i=0;i<n;i++)  
               if(r==a[i])  break;  
        if(i==n)  break;  
    }  
    printf("%d",r);  
    return 0;  
}  