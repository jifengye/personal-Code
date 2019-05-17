//6.3sights(���ռ�7�㣩 
//�������������ͼ
//�������ֻ��һ����·�����ظ��߹��� 
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000;
const int Max=99999999;
const int mod=707063423;
int map[N][N]; 
__int64 dis[N];
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

void dijkstar(int n,int s)
{
    int k, min,i ,j;
    visit[s] = 1;
    for(i=1; i<=n; i++)
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
            if(!visit[j]&&dis[j] > dis[k]+map[k][j])
				 dis[j]=dis[k]+map[k][j];
        }
    }
}
    

int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	
	mapinit(n);
	
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=map[b][a]=c;
	}
	
	dijkstar(n,1);
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&c,&b);
		printf("%I64d\n",(mod+c-dis[a]+dis[b])%mod);
	}
	return 0;
}
/*
4
1 2 5
1 3 6
2 4 4
2
2 8 4
3 6 2
output
12
5
*/
