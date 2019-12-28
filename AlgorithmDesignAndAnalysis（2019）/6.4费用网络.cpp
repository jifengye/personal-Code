/*
算法设计与分析 费用网络

★题目描述
有一个N个点M条边的有向无环图，每条边有容量和其单位容量的花费
请求出从起点1到终点N的最大流量及其最小花费

★输入格式
输入的第一行两个数字N,M(1<=N,M<=100,1<=K<=100)$，表示点数、边数。

接下来M行每行三个数字a,b,c,d(1<=a,b<=N,1<=c<=100,1<=d<=100)代表节点a到b有一条容量为c的边且该边每单位流量需要花费d费用。

★输出格式
输出最大流量及其最小费用。

★样例输入
2 1
1 2 3 4

★样例输出
3 12
*/
/*

https://www.cnblogs.com/-citywall123/p/11329508.html

一、概念部分
	每条边的流量：flow(u,v)
	每条边的容量：cap(u,v)
	
	
	可行流:在容量网络G中满足以下条件的网络流f,称为可行流.
	a.弧流量限制条件:0<=f(u,v)<=c(u,v);
	b:平衡条件:即流入一个点的流量要等于流出这个点的流量,(源点和汇点除外).

	增广路：如果一个可行流不是最大流，那么当前网络中一定存在一条增广路
	什么是增广路？设f是一个容量网络G中的一个可行流,P是从Vs到Vt 的一条链,若P满足以下条件:
	a.P中所有前向弧(方向与链的正方向一致的弧)都是非饱和弧, f<c 
	b.P中所有后向弧(方向与链的正方向相反的弧)都是非零弧. f>0
	则称P为关于可行流f 的一条增广路.

	残余网络： 
	在一个网络流图上，找到一条源到汇的路径后，对该条路径上所有的边，其容量都减去此次找到的量，
	对路径上所有的边，都添加一条反向边，其容量等于此次找到的最小流量，这样得到的新图，就称为原图的“残余网络”

	费用流：cost*flow
	
	最大流等于小于最小容量 
	

二、算法的精华部分，利用反向边，使程序有了一个后悔和改正的机会

	那么我们刚刚的算法问题在哪里呢？
	问题就在于我们没有给程序一个”后悔”的机会，应该有一个不走(2-3-4)而改走(2-4)的机制。
	那么如何解决这个问题呢？回溯搜索吗？那么我们的效率就上升到指数级了。
	
	这时再找增广路的时候，就会找到1-3-2-4这条可增广量，即delta值为1的可增广路。将这条路增广之后，得到了最大流2。


三、找最大流的步骤
	step1 找到一条源到汇的增广路径。0<f<c 
	step2 使用该增广路径，构建残余网络。这条增广路径上容量改为剩余容量，而图中所有边都添加一条反向边，其容量等于此次找到的最小流量
	step3 在残余网络上寻找新的增广路径，使总流量增加。回到step2
	step4 直到残余网络上找不到从源到汇的增广路径为止，最大流就算出来了。
 

四、常用的查找最大流的算法
	在每次增广的时候，选择从源到汇的具有最少边数的增广路径。
	也就是说！不是通过dfs寻找增广路径，而是通过bfs寻找增广路径。 
	这就是Edmonds-Karp 最短增广路算法 已经证明这种算法的复杂度上限为nm2 (n是点数，m是边数）
*/


/*
找最大流算法 EK 
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//queue <int> q;
//int n, m, s, t;
//int g[201][201],pre[201],flow[201];
//int maxflow; 
//
////用广度优先算法BFS查找最短增广路径 
//inline int bfs(int s,int t){
//    q = queue<int>();
//    memset(pre, -1, sizeof(pre));
//    pre[s]=0;
//    q.push(s); 
//    flow[s]=0x3ffffff;
//    
//    while(!q.empty()) {
//        int x=q.front(); q.pop();
//        if(x==t) break;//EK一次只找一个增广路 
//        for(int i=1; i<=n; i++)
//			if (g[x][i]>0 && pre[i]==-1) { //这条边还有余量，且没有走过 
//				pre[i]=x;
//				flow[i]=min(flow[x],g[x][i]); //最小割最大流原理，最大流等于小于最小容量
//				q.push(i);
//			}
//    }
//    if(pre[t]==-1) return -1; //没有找到增广路径，结束 
//    return flow[t];
//}
//
//void EK(int s,int t) {
//    int increase=0;
//    while ((increase=bfs(s,t))!=-1) { //迭代 
//        int k=t;
//        while (k!=s) {
//            int last=pre[k];//从后往前找路径
//            g[last][k]-=increase;
//            g[k][last]+=increase;
//            k=last;
//        }
//        maxflow+=increase;
//    }
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    
//    int u, v, c;
//    for(int i=1; i<=m; i++) {
//        scanf("%d%d%d",&u,&v,&c);
//        g[u][v]+=c;//此处不可直接输入，要+= 。然道是一条边会多次输入吗 
//    }
//    
//    EK(1,n);
//    
//	printf("%d\n",maxflow);
//	return 0;
//}

/*
4 5
2 4 100
3 4 100 
1 2 100
1 3 100
2 3 1
*/ 

/*
算法改进 
前面的EK网络流算法，每进行一次增广，都要做 一遍BFS，十分浪费。
能否少做几次BFS? 这就是Dinic算法要解决的问题 
*/


/*
费用流算法
边的费用相当于它的单位费用乘上它的流量，我们要保持最大流的同时，还要保持边权最小，这就是最小费用最大流问题。
因为在一个网络流图中，最大流量只有一个，但是不同的流法所经过的边不同因此费用也就不同，
总增广的费用就是*最短路总流量** 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=210;

bool vis[maxn];
int n,m;
int dis[maxn],pre[maxn],last[maxn],flow[maxn];//dis最小花费;pre每个点的前驱；last每个点的所连的前一条边；flow源点到此处的流量 
int maxflow,mincost;

struct Edge{
    int to,next,flow,dis;//flow流量 dis花费 
}edge[maxn]; //保存的数据是边 
queue <int> q; //保存的数据是点（从起点到终点） 

int head[maxn],num_edge;
void add_edge(int from, int to, int flow, int dis){
    ++num_edge;
    edge[num_edge].to=to; //边的端点 
	edge[num_edge].next=head[from]; 
    head[from]=num_edge; //邻接表 
    edge[num_edge].flow=flow;
    edge[num_edge].dis=dis;
}

//使用深度优先DFS方法查找所有的增广路径 
int spfa(int s,int t){
    memset(dis,0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis,0,sizeof(vis));
    q.push(s); vis[s]=1; dis[s]=0; pre[t]=-1;

    while (!q.empty()) {
        int now=q.front(); q.pop();
        vis[now]=0; 
        for(int i=head[now]; i!=-1; i=edge[i].next) {//从前端点now出发连着很多的后端点i 
            if(edge[i].flow>0 && dis[edge[i].to]>dis[now]+edge[i].dis) { //第i条边还有余量，且会使费用更小 
                dis[edge[i].to]=dis[now]+edge[i].dis;
                pre[edge[i].to]=now; //每个点所连的前端点是now 
                last[edge[i].to]=i; //每个点的所连的前一条边 
                flow[edge[i].to]=min(flow[now],edge[i].flow);//最大流量取决于最小容量 
                if(!vis[edge[i].to]) {
                    vis[edge[i].to]=1;
                    q.push(edge[i].to);
                }
            }
        }
    }
    return pre[n];
}

 
int main(){
    scanf("%d%d",&n,&m);
    
    int a, b, c, d; 
    memset(head,-1,sizeof(head)), num_edge=-1; 
    for (int i=1; i<=m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add_edge(a,b,c,d); 
		add_edge(b,a,0,-d); //反边的流量为0，花费是相反数 
    }
    
    while(spfa(1,n)!=-1) {  //迭代，不断的更新网络 
        maxflow+=flow[n];
        mincost+=flow[n]*dis[n];
        int now=n;
        while(now!=1) {//从源点一直回溯到汇点 
            edge[last[now]].flow-=flow[n];//flow和dis容易搞混 
            edge[last[now]^1].flow+=flow[n];
            now=pre[now];
        }
    }
    
    printf("%d %d",maxflow, mincost);
    return 0;
} 
