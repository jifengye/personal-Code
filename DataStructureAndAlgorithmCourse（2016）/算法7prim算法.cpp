#include<iostream>
#include<fstream>
using  namespace std;

#define N 100
#define MAX 0x7fffffff

int map[N][N];
int closest[N];//closet[a]值是与a最近的点 
int lowcost[N];//lowcost[i]是k到i距离 
bool visit[N];

void mapinit(int n)//map[]初始化 
{
	int i,j;
	for(i=1;i<=n;++i) //map[]初始化
    {
        map[i][i]=0;
        for(j=1;j<i;++j)
            map[i][j]=map[j][i]=MAX;
    } 
}

int prim(int n)
{	
	int i, j, min, k, sum=0;
	for(i=2; i<=n; i++)
	{
		lowcost[i]=map[1][i];
		closest[i]=1;
		visit[i]=0;
	}
	closest[1] = 0;
	visit[1]=1;
	
	for(i=2; i<=n; i++)
	{
		for(j=2, k=0, min=MAX; j<=n; j++)
		{
			if(lowcost[j]<min && !visit[j])
			{
				min=lowcost[j];
				k=j;
			}
		}
		visit[k]=1;
		sum += min;
		cout << "V" << closest[k] << "-V" <<k<< "=" << min << endl;
		
		for(j=2; j<=n; j++)
		{
			if(!visit[j] && map[k][j]<lowcost[j])
			{
				lowcost[j]=map[k][j];
				closest[j]=k;
			}
		}
	}
	return sum;
}

int main()
{
	int i, m, n, u, v, w;
	scanf("%d%d",&n,&m);
	 	
	mapinit(n);//map[]初始化

	for(i=1;i<=m;++i) //map[]输入建立 
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<map[u][v])            //可能有多条路，只记录最短的
            map[u][v]=map[v][u]=w;
    }
    
	int cost=prim(n);

	cout << "最小权值和=" << cost << endl;
	return 0;
}
/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
out
V1-V3=1
V3-V6=4
V6-V4=2
V3-V2=5
V2-V5=3
最小权值和=15
*/
