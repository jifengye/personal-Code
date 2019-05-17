#include<iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{ 
    int left;
    int right;
}home[10001];

int maxh,a=0,flag=0;
void order(int p,int t)
{  
    if (p!=-1)
    {   
        maxh=max(maxh,t);
        order(home[p].left,t+1);
        //cout<<a<<'&'<<p<<' ';
        if(a>p) flag=1;a=p;
        order(home[p].right,t+1);
    }
}

int main( )
{   
     int i,n,l,o,r,book[10001]={0};
     cin>>n;
     for(i=0;i<n;i++)
     {   
          cin>>l>>o>>r;
          home[o].left=l;home[o].right=r;
          if(l>0) book[l]=1;
          if(r>0) book[r]=1;
      }
      for(i=1;i<=n;i++) {if(book[i]==0)  break;} //ур╦Ы╫з╣Ц 
      order(i,1);    
      if(flag) cout<<-1<<endl;
      else     cout<<maxh<<endl;
      return 0;
}
/*
input
5
-1 1 -1
1 2 3
-1 3 -1
2 4 5
-1 5 -1
output
3

input
5
-1 1 -1
1 2  3
-1 3 -1
2 4 5
-1 5 -1

input
16
-1 1 -1
1 2 3
-1 3 -1
2 4 6
-1 5 -1
5 6 7
-1 7 -1
4 8 10
-1 9 -1
9 10 12
-1 11 -1
11 12 13
-1 13 -1
8 14 15
-1 16 -1
16 15 -1

*/
