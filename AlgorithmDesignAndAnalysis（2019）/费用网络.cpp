#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
 
int H[maxn],num_edge;
struct Edge{
    int end, next, flow, dis;//flow流量 dis花费 
}E[maxn]; //保存的数据是边 

int idx = -1; 
void AddEdge(int s, int e, int flow, int dis){ //用邻接表记录稀疏图 
    ++idx;
    E[idx].end=e; //边的端点 
	E[idx].next=H[s]; 
    E[idx].flow=flow;
    E[idx].dis=dis;
    H[s]=idx; //邻接表 
}


queue<int> Q; //用深度优先遍历 
int dis[maxn],pre[maxn],last[maxn],flow[maxn];//dis最小花费;pre每个点的前驱；last每个点的所连的前一条边；flow源点到此处的流量 
int vis[maxn];//判重 

int spfa(int s, int t){//使用深度优先DFS方法查找所有的增广路径 
    memset(dis, 0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis, 0,   sizeof(vis));
	vis[s]=1, dis[s]=0, pre[t]=-1;
    Q.push(s); 

    while(!Q.empty()) {
        int now=Q.front(); Q.pop(); vis[now]=0; 
        for(int i=H[now]; i!=-1; i=E[i].next) {
            if(E[i].flow>0 && dis[E[i].end]>dis[now]+E[i].dis) { //第i条边还有余量，且会使费用更小 
                dis[E[i].end]=dis[now]+E[i].dis;
                pre[E[i].end]=now; //每个点所连的前端点是now 
                last[E[i].end]=i; //每个点的所连的前一条边 
                flow[E[i].end]=min(flow[now],E[i].flow);//最大流量取决于最小容量 
                if(vis[E[i].end]==0) {
                    vis[E[i].end]=1;
                    Q.push(E[i].end);
                }
            }
        }
    }
    return pre[t];
}

 
int main(){
	int n, m, s, t;
//    scanf("%d%d%d%d",&n, &m, &s, &t);
    scanf("%d%d",&n, &m); s=1,t=n;
    
    int a, b, c, d; 
    memset(H, -1, sizeof(H)); 
    while(m--){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        AddEdge(a, b, c,  d); 
		AddEdge(b, a, 0, -d); //反边的流量为0，花费是相反数 
    }
    
    int maxflow=0, mincost=0;
    while(spfa(s, t)!=-1) {  //迭代，不断的更新网络 
        maxflow+=flow[t];
        mincost+=flow[t]*dis[t];
        int now=t;
        while(now!=s) {//从源点一直回溯到汇点 
            E[last[now]].flow-=flow[t]; 
            E[last[now]^1].flow+=flow[t];
            now=pre[now];
        }
    }
    
    printf("%d %d\n", maxflow, mincost);
    return 0;
} 
/*
2 1
1 2 3 4

*/
