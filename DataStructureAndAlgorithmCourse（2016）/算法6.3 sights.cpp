#include<iostream>
#include<cstdio>
using namespace std;

struct  Road
{  int start;
   int end;
   int fee;
}R[100003];
int  p1,p2;
__int64 cost;

int main( )
{   int n,m,i;
    cin>>n;
    for(i=0;i<n-1;i++)
        cin>>R[i].start>>R[i].end>>R[i].fee;
    cin>>m;
    while(m--)
    {    cin>>p1>>cost>>p2;
         for(i=0; p1!=1&&p2!=1; i=(i+1)%(n-1))
         {    if(R[i].end==p1&&p1!=1)
              {   p1=R[i].start;
                  cost-=R[i].fee;
              }
              if(R[i].end==p2&&p2!=1)
              {   p2=R[i].start;
                  cost+=R[i].fee;
              }
         }
         printf("%I64d\n",cost%707063423);
    }
    return 0;
}
/*
4
2 4 4000000
1 3 3000000
1 2 5000000
2
3 50 2
4 50 1
*/
