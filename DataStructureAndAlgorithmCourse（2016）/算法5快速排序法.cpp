#include<stdio.h>
int a[101],n;

void quicksort(int left,int right)
{  
   int i,j,t,temp;
   if(left>right) return;//递归结束标志 
   
   temp=a[left];//temp存基准数
   i=left;j=right;//左右指针 
   while(i!=j)
   {   while(a[j]>=temp && i<j)  j--;
       while(a[i]<=temp && i<j)  i++; 
	   if(i<j) {t=a[j];a[j]=a[i];a[i]=t;}
   }
   a[left]=a[i];a[i]=temp;//基准数归位 
   
   quicksort(left,i-1);
   quicksort(i+1,right);
}

int main()
{  int i,j,t;
   
   scanf("%d",&n);
   for(i=1;i<=n;i++) scanf("%d",&a[i]);
   
   quicksort(1,n);
   
   for(i=1;i<=n;i++) printf("%d ",a[i]);
   return 0;
}
