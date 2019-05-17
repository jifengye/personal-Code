#include<iostream>
using namespace std;

struct treenode
{   int left;
    int right;
}node[10003];

void preorder(int p)
{    cout<<p<<' ';
     if(node[p].left)   preorder(node[p].left);
     if(node[p].right) preorder(node[p].right);
}

void posorder(int p)
{    if(node[p].left)   posorder(node[p].left);
     if(node[p].right) posorder(node[p].right);
     cout<<p<<' ';
}

int main( )
{  int i,n,point[10003],temp;
   memset(node,0,sizeof(treenode));
   cin>>n;
   for(i=1;i<=n;i++)
   {    cin>>temp;
        if(!node[temp].left) node[temp].left=i;
        else                           node[temp].right=i;
   }
   for(i=1;i<=n;i++)  {cin>>temp;point[temp]=i;}
   for(i=1,point[0]=0;i<=n;i++)
   {    if(point[node[i].left]>point[i])
         {    temp=node[i].left;
               node[i].left=node[i].right;
               node[i].right=temp;
         }
   }
   preorder(node[0].left);
   cout<<endl;
   posorder(node[0].left);
   cout<<endl;
   return 0;
}
/*
input
10
0 7 2 2 9 1 8 1 6 8
9 5 6 1 10 8 7 3 2 4
output
1 6 9 5 8 10 7 2 3 4
5 9 6 10 3 4 2 7 8 1

input
7
0 1 1 2 2 3 3
4 2 5 1 6 3 7

input
12
0 1 1 2 2 3 3 4 4 5 5 6
8 4 9 2 10 5 11 1 12 6 3 7
*/
   