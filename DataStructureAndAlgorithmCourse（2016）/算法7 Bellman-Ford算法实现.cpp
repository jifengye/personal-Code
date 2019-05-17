//�㷨7 Bellman-Ford�㷨ʵ��(����  ��Ȩ) 
//2016.11.23
//��ӡ���㵽Դ�����·�� 
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 0x3f3f3f3f
#define N 1010

struct Edge //��
{
	int u, v;
	int cost;
}edge[N];
int nodenum; //������ 
int edgenum; //���� 
int original; //���
int dis[N]; //�����㵽Դ����̾��� 
int pre[N];

bool Bellman_Ford()
{
	int i,j;
	for(i=1; i<=nodenum; ++i)  //��ʼ������Ϊ���ֵ 
		dis[i]=(i==original? 0:MAX);

	for(i=1; i<=nodenum-1; ++i) //������ÿ��ѭ������һ�����ҵ�����·��,��ȥԴ��Ҫѭ��nodenum-1�� 
		for(j=1; j<=edgenum; ++j) //Ҫ����ÿ����, 
			if(dis[edge[j].v] > dis[edge[j].u]+edge[j].cost) //�����㵽Դ�����һ���������� 
			{
				dis[edge[j].v]=dis[edge[j].u]+edge[j].cost;
				pre[edge[j].v]=edge[j].u;
			}
//��û�и�Ȩֵ������һ���������Ƕ��һ�٣���Դ˻�������Dijkstar�㷨 
//a->b�������a->c,��a->c��̾��벻�ÿ��ǽ���b������b->c�����Ǹ�ֵ 
	
	bool flag = 1; //�ж��Ƿ��и�Ȩ��·
	for(i=1; i<=edgenum; ++i)
	   if(dis[edge[i].v] > dis[edge[i].u]+edge[i].cost)
	   {
	       flag = 0;
		   break;
	   }
	return flag;
}

void print_path(int root) //��ӡ���·��·��������
{
	while(root != pre[root]) //ǰ��
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
		for(int i = 1; i <= nodenum; ++i) //ÿ�������·
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
