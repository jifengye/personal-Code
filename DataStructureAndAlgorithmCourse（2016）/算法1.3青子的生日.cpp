#include<stdio.h>
int n,ts[105]={0},te[105]={0},Mtime=1;
int select(int i,int time)
{   int j=1;
 for(j=1;i+j<=n;j++)
     {    if(te[i]<=ts[i+j])
               select(j+i,time+1);
          else  if(Mtime<time) Mtime=time;
     }
 return  Mtime;
}
int main()
{    int i,j,temp,m=1;
     scanf("%d",&n);
     for(i=0;i<n;i++)  scanf("%d %d",&ts[i],&te[i]);
     for(i=0;i<n;i++)
         for(j=i;j<n;j++)
             if(ts[i]>ts[j])
             {     temp=ts[i];ts[i]=ts[j];ts[j]=temp;
                   temp=te[i];te[i]=te[j];te[j]=temp;
             }
      for(i=0;i<n;i++) 
      {    temp=select(i,1);
           if(m<temp) m=temp;
      }
      printf("%d\n",m);
      return 0;
}
