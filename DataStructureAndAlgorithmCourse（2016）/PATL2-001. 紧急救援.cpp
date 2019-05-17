#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int N=501;
const int Max=1000000000;

int map[N][N];
int edgenum[N][N]={0};
int dis[N];
int pre[505]; //��¼·�� 
int car[505], totcar[505]; //car�Ǹ����Ԯ������ totcar�����s���õ��Ԯ���� 
int pathnum[505]; //���s���õ�����·������ 
bool visit[505];

int main( )
{
    int n, m, s, e, u, v, w, i, j;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=0; i<n; i++) scanf("%d",&car[i]);
    
    for(i=0;i<n;++i) //map[]��ʼ��
    {
        map[i][i]=0;
        for(j=0;j<i;++j)
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
    totcar[s] = car[s];
    pathnum[s] = 1;
    for(i=0; i<n; i++)
    {
        dis[i] = map[s][i];
        if(map[s][i] != Max && i!=s) //�е�·���Ҳ��ػظõ� 
        {
            pre[i] = s;
            totcar[i] = car[s] + car[i];
            pathnum[i] = edgenum[s][i];
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=0,k=s,min=Max; j<n; ++j) 
        { 
            if(!visit[j]&&min>dis[j])
			{ 
			     min=dis[j];
				 k=j;
			}
        } 
        if(k==e) break;
        visit[k]=1;
        
        for(j=0; j<n; ++j)
        {
            if(!visit[j])
            {
                if(dis[j] > dis[k]+map[k][j])
                {
				    dis[j]=dis[k]+map[k][j];
                    pathnum[j] = pathnum[k]*edgenum[k][j];
                    pre[j]=k;  //��(δ�߹� )j���ϼ���ΪK 
                    totcar[j] = totcar[k]+car[j];
                }
                else if(dis[j] == dis[k]+map[k][j]  ) //���� ����·��
                {
                    pathnum[j] += (pathnum[k]*edgenum[k][j]);
                    if(totcar[j] < totcar[k]+car[j]) //·��ͬ�������±ȽϾ�Ԯ���� 
                    {
                        totcar[j] = totcar[k]+car[j];
                        pre[j] = k;
                    }
                }
            }
        }
    }
    
    printf("%d %d\n", pathnum[e], totcar[e]);
    
    stack<int>q;
    for(i=e; i!=s; i=pre[i])
    {
        q.push(i);
    }
    q.push(s);
    
    while(q.size()>1)
    {
	    printf("%d ", q.top());
	    q.pop();
	}
	printf("%d\n",q.top());
    return 0;
}
