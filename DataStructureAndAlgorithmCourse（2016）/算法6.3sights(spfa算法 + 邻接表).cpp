//算法6.3sights(spfa算法 + 邻接表) 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

const int MAXN=100010; 
const int mod=707063423;
const int MAX=99999999;

struct Edge
{
	int to,w;
	int next;
}edge[MAXN*2];
__int64 dis[MAXN];

int place=1;
int head[MAXN]={0};

void creat(int a,int b,int c)
{
	edge[place].to=b;edge[place].w=c;	
	edge[place].next=head[a];
	
	head[a]=place;
	place++;
}

void spfa(int n,int s)
{
	queue<int>q;
	bool vis[MAXN]={0}; //vis[i]用于判断i是否在队列q中 
	
	int a,i;
	for(i=0;i<=n; i++)  dis[i]=MAX;
	dis[s]=0;
	q.push(s);
	vis[s]=1;

	while(!q.empty())
	{
		a=q.front();
		q.pop();
		vis[i]=0;
		for(i=head[a]; i!=0; i=edge[i].next)
		{
			if(dis[edge[i].to]>dis[a]+edge[i].w)
			{
				dis[edge[i].to]=dis[a]+edge[i].w; 
				if(!vis[edge[i].to])
				{
					q.push(edge[i].to);
					vis[edge[i].to]=1;
				}
			}
		}
	}
}

int main()
{
    int n,a,b,c,i;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
	{
    	scanf("%d%d%d",&a,&b,&c);
    	creat(a,b,c);
    	creat(b,a,c);
	}
	
	spfa(n,1);
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&a,&c,&b);
		printf("%I64d\n",(c-dis[a]+dis[b]+mod)%mod );
	}
    return 0;
}
