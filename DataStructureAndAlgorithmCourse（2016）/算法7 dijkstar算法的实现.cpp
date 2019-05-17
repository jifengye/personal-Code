//算法7 dijkstar算法的实现 
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=101;
const int Max=1000000000;

int map[N][N];
int dis[N]; 
bool visit[N];

void mapinit(int n)//map[]初始化 
{
	int i,j;
	for(i=1;i<=n;++i) //map[]初始化
    {
        map[i][i]=0;
        for(j=1;j<i;++j)
            map[i][j]=map[j][i]=Max;
    } 
}

void dijkstar(int n,int m,int s)
{  
    int k, min, i, j;
    visit[s] = 1;
    for(i=1; i<=n; i++) //dis[]初始化 
    {
        dis[i] = map[s][i];
    }
    for(i=1;i<=n;++i)  
    {
        for(j=1,k=s,min=Max; j<=n; ++j) //选出最优路，k并入集合 
        { 
            if(!visit[j]&&min>dis[j])
			{ 
			     min=dis[j];
				 k=j;
			}
        } 
        visit[k]=1;
        
        for(j=1; j<=n; ++j)  //k并入集合后,更新数据 
        {
            if(!visit[j] && dis[j]>dis[k]+map[k][j])
				 dis[j]=dis[k]+map[k][j];
        }
    }
}
	
int main( )
{
    int n, m, s, e;
	int u, v, w, i;
    scanf("%d%d%d%d",&n,&m,&s,&e);
	 	
	mapinit(n);//map[]初始化 
    
	for(i=1;i<=m;++i) //map[]输入建立 
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<map[u][v])            //可能有多条路，只记录最短的
            map[u][v]=map[v][u]=w;
    }
    
    dijkstar(n,m,s);
    
    printf("%d\n", dis[e]);

    return 0;
}
/*
4 6 3 4
1 4 1
1 3 1
1 2 1
2 3 1
2 4 1
1 2 5
*/
