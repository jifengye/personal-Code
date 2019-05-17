//并查集的删除
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=100000;

int parent[2*N];
int shell[N];//下标1~n是编号，通过外壳shell调用parent。通俗地说shell[a]是a对外的身份 
int place;

void init(int n) //初始化 
{
	for(int i=0;i<=n;i++)
	    parent[i]=shell[i]=i;
	place=n+1;
}

int root(int x) //找首领 
{
    if(x!= parent[x])
	     parent[x]=root(parent[x]);
    return parent[x];
}

int main()
{
	int n,m,a,b;
	char c;
	scanf("%d%d",&n,&m);
	init(n);
	
	while(m--)
	{
		scanf("%c",&c);
		if(c=='M')
		{
			scanf("%d%d",&a,&b);
			if( root( shell[a] )!=root( shell[b] ) )
			   parent[root(shell[a])]= root(shell[b]);
		}
		else if(c=='I')
		{
			scanf("%d",&a);
			shell[a]=place;
			parent[place]=place;
			place++;
		}
		else if(c=='Q')
		{
			scanf("%d%d",&a,&b);
			if(root(shell[a])==root(shell[b]))
			     printf("Yes\n");
		    else
		         printf("No\n");
		}
	}
	return 0;
}
/*
10 100
M 1 2
M 2 3
M 2 4
Q 2 4
I 4
Q 2 4
M 5 6
M 8 6
M 7 5
I 6
Q 6 5
M 4 5
Q 4 6

*/

