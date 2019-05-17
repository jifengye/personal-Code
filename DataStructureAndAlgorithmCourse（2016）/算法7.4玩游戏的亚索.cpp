//算法7.4玩游戏的亚索 (kruskal算法) 
#include<cstdio>
#include<algorithm>
using namespace std; 
const int MAX=500001;

struct Rode
{
    int a,b,d;
}R[MAX];
int f[MAX]; //用于并查集，若以用最短路径连接归并到一个集合内 

int root(int x)
{
	if(x!=f[x])  f[x]=root(f[x]);//压缩路径 
	return f[x];
}

int cmp(Rode x,Rode y)
{
    return x.d<y.d;
}

int main( )
{
	int n,m,i;
	scanf("%d%d",&n, &m);
	for(i=0; i<=n; i++) f[i]=i; //初始化，n个点分成n个集合 
	for(i=0; i<m;  i++)
		scanf("%d%d%d",&R[i].a, &R[i].b, &R[i].d);
		
	sort(R, R+m, cmp); //按距离，从小到大排序 
	
	int aroot,broot,sum=0,time=0; 
	for(i=0; i<m; i++)
    {
    	aroot=root(R[i].a); //含a点集合的首领 
    	broot=root(R[i].b);

    	if(aroot==broot) continue; //a b在一个集合说明已经有最短路径相连或间接相连 
		
		sum+=R[i].d; time++;  //a b不在一个集合， 
		f[aroot]=broot;
    }
    printf("%d\n",sum);
    return 0;
}
/*
5 6
1 2 1
2 3 2 
1 3 3 
2 4 3
3 4 5
1 4 4
*/ 
