//�㷨7.3��Gank������ 
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=101;
const int Max=1000000000;

int map[N][N];
int edgenum[N][N]={0};
int dis[N];
int pathnum[N]; //���s���õ�����·������ 
bool visit[N];

int main( )
{
    int n, m, s, e;
	int u, v, w, i, j;
    scanf("%d%d%d%d",&n,&m,&s,&e);	
	
    for(i=1;i<=n;++i) //map[]��ʼ��
    {
        map[i][i]=0;
        for(j=1;j<i;++j)
            map[i][j]=map[j][i]=Max;
    }
    
    for(i=1;i<=m;++i)  //���� 
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<map[u][v])            //�����ж���·��ֻ��¼��̵�
        {
		    map[u][v]=map[v][u]=w;
		    edgenum[u][v]=edgenum[v][u]=1;
		}
        else if(w==map[u][v])
        {
        	edgenum[u][v]++;
        	edgenum[v][u]++;
        }    
    }
    
    int k, min;
    visit[s] = 1;
    pathnum[s] = 1;
    for(i=1; i<=n; i++)
    {
        dis[i] = map[s][i];
        if(map[s][i] != Max && i!=s) //�е�·���Ҳ��ػظõ� 
            pathnum[i] = edgenum[s][i];
    }

    for(i=1;i<=n;i++)  
    {
        for(j=1,k=s,min=Max; j<=n; ++j) //ѡ������·��k���뼯�� 
        { 
            if(!visit[j]&&min>dis[j])
			{ 
			     min=dis[j];
				 k=j;
			}
        } 
        if(k==e) break;
        visit[k]=1;
        
        for(j=1; j<=n; ++j)  //k���뼯�Ϻ�,�������� 
        {
            if(!visit[j])
            {
                if(dis[j] > dis[k]+map[k][j])
                {
				    dis[j]=dis[k]+map[k][j];
                    pathnum[j] = pathnum[k]*edgenum[k][j];
                }
                else if(dis[j] == dis[k]+map[k][j]  ) //�ж�������·��
                {
                    pathnum[j] += pathnum[k]*edgenum[k][j];
                }
            }
        }
    }
    
    printf("%d %d\n", dis[e], pathnum[e]);

    return 0;
}
/*
input 
5 6 1 5
1 2 5
2 5 5
1 3 3
3 5 7
1 4 1
4 5 9
output
10 3

input
4 5 1 4 
1 2 1
2 4 2
1 4 3
1 3 2
3 4 2
output
3 2 

input
4 5 1 4
1 2 5
2 3 5
3 4 5
1 3 10
3 2 6
*/ 
