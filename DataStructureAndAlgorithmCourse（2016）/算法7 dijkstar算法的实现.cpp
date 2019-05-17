//�㷨7 dijkstar�㷨��ʵ�� 
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=101;
const int Max=1000000000;

int map[N][N];
int dis[N]; 
bool visit[N];

void mapinit(int n)//map[]��ʼ�� 
{
	int i,j;
	for(i=1;i<=n;++i) //map[]��ʼ��
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
    for(i=1; i<=n; i++) //dis[]��ʼ�� 
    {
        dis[i] = map[s][i];
    }
    for(i=1;i<=n;++i)  
    {
        for(j=1,k=s,min=Max; j<=n; ++j) //ѡ������·��k���뼯�� 
        { 
            if(!visit[j]&&min>dis[j])
			{ 
			     min=dis[j];
				 k=j;
			}
        } 
        visit[k]=1;
        
        for(j=1; j<=n; ++j)  //k���뼯�Ϻ�,�������� 
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
	 	
	mapinit(n);//map[]��ʼ�� 
    
	for(i=1;i<=m;++i) //map[]���뽨�� 
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<map[u][v])            //�����ж���·��ֻ��¼��̵�
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
