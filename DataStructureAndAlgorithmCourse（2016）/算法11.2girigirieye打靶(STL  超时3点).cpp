//算法11.2girigirieye打靶(STL  超时3点) 
#include<iostream>
#include<queue>
#include<algorithm>
#define MAX(a,b) (a>b?a:b)
using namespace std;

struct Node
{
	int d,w;
}node[1000001];

bool cmp(Node a,Node b)
{
	return a.d>b.d;
}

int main()
{
	priority_queue<int>q;
	int n,i,j=1,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>node[i].d>>node[i].w;
	}
	
	sort(node+1,node+n+1,cmp);
	
    for(i=node[1].d; i>=1; i--) //寻找i时刻要打的靶子 
    {
    	for(; j<=n && node[j].d==i; j++) 
    	{
    		 q.push(node[j].w); 
		}
		if(!q.empty())
		{
    	    ans+=q.top();
    	    q.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
*/
