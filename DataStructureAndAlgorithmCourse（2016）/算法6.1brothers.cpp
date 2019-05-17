#include<iostream>
using namespace std;
struct Tree
{   int left;
    int right;
    int high;
}T[100001];
int num[100001]={0};//第i层的元素个数
int bro[100001]={0};//i的亲兄弟

void fbrother(int p,int h)
{    if(p)
     {    T[p].high=h;
           num[h]++;
           fbrother(T[p].left,h+1);
           fbrother(T[p].right,h+1);
     }
}

int main( )
{    int n,i;
     cin>>n;
     for(i=1;i<=n;i++)
     {    cin>>T[i].left>>T[i].right;
           bro[T[i].left]=T[i].right;
           bro[T[i].right]=T[i].left;
     }
     
     fbrother(1,0);
   
     int m,p,t;
     cin>>m;
     while(m--)
     {    cin>>p;
          if(bro[p])  t=1;else t=0;
          cout<<t<<' '<<num[T[p].high]-t-1<<endl;
      }
     return 0;
}
/*
input
8
2 3
4 0
5 7
0 8
6 0
0 0
0 0
0 0
3
4
5
6
output
0 2
1 1
0 1

input
15
2 3
4 5
6 7
8 9
10 11
12 13
14 15
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
15
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
*/