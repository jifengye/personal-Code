//算法7 Bellman-Ford算法实现(有向  负权) 
//2016.11.23
//打印各点到源点最短路径 
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 0x3f3f3f3f
#define N 1010

struct Edge //边
{
	int u, v;
	int cost;
}edge[N];
int nodenum; //顶点数 
int edgenum; //边数 
int original; //起点
int dis[N]; //其他点到源点最短距离 
int pre[N];

bool Bellman_Ford()
{
	int i,j;
	for(i=1; i<=nodenum; ++i)  //初始化距离为最大值 
		dis[i]=(i==original? 0:MAX);

	for(i=1; i<=nodenum-1; ++i) //最坏情况下每次循环至少一个点找到最优路径,除去源点要循环nodenum-1次 
		for(j=1; j<=edgenum; ++j) //要尝试每条边, 
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].cost) //其他点到源点距离一步步的收敛 
			{
				dis[edge[j].v]=dis[edge[j].u]+edge[j].cost;
				pre[edge[j].v]=edge[j].u;
			}
//若没有负权值，这种一步步收敛是多此一举，针对此化简后就是Dijkstar算法 
//a->b距离等于a->c,问a->c最短距离不用考虑借助b，除非b->c距离是负值 
	
	bool flag = 1; //判断是否含有负权回路
	for(i=1; i<=edgenum; ++i)
	   if(dis[edge[i].v] > dis[edge[i].u]+edge[i].cost)
	   {
	       flag = 0;
		   break;
	   }
	return flag;
}

void print_path(int root) //打印最短路的路径（反向）
{
	while(root != pre[root]) //前驱
	{
		printf("%d-->", root);
		root = pre[root];
	}
	if(root == pre[root])
		printf("%d\n", root);
}

int main()
{
	scanf("%d%d%d", &nodenum, &edgenum, &original);
	pre[original] = original;
	for(int i = 1; i <= edgenum; ++i)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
	
	if(Bellman_Ford())
		for(int i = 1; i <= nodenum; ++i) //每个点最短路
		{
			printf("%d\n", dis[i]);
			printf("Path:");
			print_path(i);
		}
	else
		printf("have negative circle\n");
	return 0;
}
/*
5 5 1
1 2 10
2 3 -7
3 4 8
4 5 6
5 1 -5
*/
