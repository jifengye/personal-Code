#include<iostream>
using namespace std;
int main( )
{    int  n,out=1,i,k=0,a[1005]={0};
     cin>>n;
     for(i=0;i<=n;i++)  a[i]=i;
     cout<<a[1];
     for(i=2;out<n-1;i++) 
    {   if(a[i])   k++;
         if(k==2)    
         {      cout<<' '<<a[i];
                 a[i]=0;k=0;
                 out++;
          }
         if(i==n)  i=1;
     }
    cout<<endl;
    if(n>1)
    {    for(i=2;a[i]==0;i++)  ;
          cout<<a[i]<<endl;
    }
    return 0;
}