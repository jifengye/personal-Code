//算法12.1 列王的纷争 
#include<cstdio>
#include<iostream>
using namespace std;
const int N=10001;
int f[N];

int root(int a)
{
	while(f[a]!=a) a=f[a];
	return f[a];
}

int main()
{
	int T,x,n,k,i,a,b;
	char opt;
	scanf("%d",&T);
	for(x=1; x<=T; x++)
	{
		scanf("%d %d",&n,&k);
		for(i=1; i<=n; i++)
		{
			scanf("%d",&f[i]);
			if(f[i]==0)  f[i]=i;
		}
		
		printf("Case #%d:\n",x);
		
		for(i=1; i<=k; i++)
		{
			cin>>opt>>a;
			if(opt=='C')
			{
				f[a]=a;
			}
			if(opt=='Q')
			{
				cin>>b;
				if( root(a)==root(b) )  printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}
/*
3
7 4
0 1 1 2 2 2 3
Q 5 7
C 2
Q 5 7
Q 4 6
4 4
2 0 2 3
C 3
Q 1 2
C 1
Q 1 2
3 5
0 3 1
C 3
Q 1 2
Q 2 3
C 2
Q 2 3
*/
