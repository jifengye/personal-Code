/*
�㷨�������� ��������

����Ŀ����
��һ��N����M���ߵ������޻�ͼ��ÿ�������������䵥λ�����Ļ���
����������1���յ�N���������������С����

�������ʽ
����ĵ�һ����������N,M(1<=N,M<=100,1<=K<=100)$����ʾ������������

������M��ÿ����������a,b,c,d(1<=a,b<=N,1<=c<=100,1<=d<=100)����ڵ�a��b��һ������Ϊc�ı��Ҹñ�ÿ��λ������Ҫ����d���á�

�������ʽ
����������������С���á�

����������
2 1
1 2 3 4

���������
3 12
*/
/*

https://www.cnblogs.com/-citywall123/p/11329508.html

һ�������
	ÿ���ߵ�������flow(u,v)
	ÿ���ߵ�������cap(u,v)
	
	
	������:����������G����������������������f,��Ϊ������.
	a.��������������:0<=f(u,v)<=c(u,v);
	b:ƽ������:������һ���������Ҫ������������������,(Դ��ͻ�����).

	����·�����һ���������������������ô��ǰ������һ������һ������·
	ʲô������·����f��һ����������G�е�һ��������,P�Ǵ�Vs��Vt ��һ����,��P������������:
	a.P������ǰ��(����������������һ�µĻ�)���ǷǱ��ͻ�, f<c 
	b.P�����к���(�����������������෴�Ļ�)���Ƿ��㻡. f>0
	���PΪ���ڿ�����f ��һ������·.

	�������磺 
	��һ��������ͼ�ϣ��ҵ�һ��Դ�����·���󣬶Ը���·�������еıߣ�����������ȥ�˴��ҵ�������
	��·�������еıߣ������һ������ߣ����������ڴ˴��ҵ�����С�����������õ�����ͼ���ͳ�Ϊԭͼ�ġ��������硱

	��������cost*flow
	
	���������С����С���� 
	

�����㷨�ľ������֣����÷���ߣ�ʹ��������һ����ں͸����Ļ���

	��ô���Ǹոյ��㷨�����������أ�
	�������������û�и�����һ������ڡ��Ļ��ᣬӦ����һ������(2-3-4)������(2-4)�Ļ��ơ�
	��ô��ν����������أ�������������ô���ǵ�Ч�ʾ�������ָ�����ˡ�
	
	��ʱ��������·��ʱ�򣬾ͻ��ҵ�1-3-2-4����������������deltaֵΪ1�Ŀ�����·��������·����֮�󣬵õ��������2��


������������Ĳ���
	step1 �ҵ�һ��Դ���������·����0<f<c 
	step2 ʹ�ø�����·���������������硣��������·����������Ϊʣ����������ͼ�����б߶����һ������ߣ����������ڴ˴��ҵ�����С����
	step3 �ڲ���������Ѱ���µ�����·����ʹ���������ӡ��ص�step2
	step4 ֱ�������������Ҳ�����Դ���������·��Ϊֹ���������������ˡ�
 

�ġ����õĲ�����������㷨
	��ÿ�������ʱ��ѡ���Դ����ľ������ٱ���������·����
	Ҳ����˵������ͨ��dfsѰ������·��������ͨ��bfsѰ������·���� 
	�����Edmonds-Karp �������·�㷨 �Ѿ�֤�������㷨�ĸ��Ӷ�����Ϊnm2 (n�ǵ�����m�Ǳ�����
*/


/*
��������㷨 EK 
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//queue <int> q;
//int n, m, s, t;
//int g[201][201],pre[201],flow[201];
//int maxflow; 
//
////�ù�������㷨BFS�����������·�� 
//inline int bfs(int s,int t){
//    q = queue<int>();
//    memset(pre, -1, sizeof(pre));
//    pre[s]=0;
//    q.push(s); 
//    flow[s]=0x3ffffff;
//    
//    while(!q.empty()) {
//        int x=q.front(); q.pop();
//        if(x==t) break;//EKһ��ֻ��һ������· 
//        for(int i=1; i<=n; i++)
//			if (g[x][i]>0 && pre[i]==-1) { //�����߻�����������û���߹� 
//				pre[i]=x;
//				flow[i]=min(flow[x],g[x][i]); //��С�������ԭ�����������С����С����
//				q.push(i);
//			}
//    }
//    if(pre[t]==-1) return -1; //û���ҵ�����·�������� 
//    return flow[t];
//}
//
//void EK(int s,int t) {
//    int increase=0;
//    while ((increase=bfs(s,t))!=-1) { //���� 
//        int k=t;
//        while (k!=s) {
//            int last=pre[k];//�Ӻ���ǰ��·��
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
//        g[u][v]+=c;//�˴�����ֱ�����룬Ҫ+= ��Ȼ����һ���߻��������� 
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
�㷨�Ľ� 
ǰ���EK�������㷨��ÿ����һ�����㣬��Ҫ�� һ��BFS��ʮ���˷ѡ�
�ܷ���������BFS? �����Dinic�㷨Ҫ��������� 
*/


/*
�������㷨
�ߵķ����൱�����ĵ�λ���ó�����������������Ҫ�����������ͬʱ����Ҫ���ֱ�Ȩ��С���������С������������⡣
��Ϊ��һ��������ͼ�У��������ֻ��һ�������ǲ�ͬ�������������ı߲�ͬ��˷���Ҳ�Ͳ�ͬ��
������ķ��þ���*���·������** 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=210;

bool vis[maxn];
int n,m;
int dis[maxn],pre[maxn],last[maxn],flow[maxn];//dis��С����;preÿ�����ǰ����lastÿ�����������ǰһ���ߣ�flowԴ�㵽�˴������� 
int maxflow,mincost;

struct Edge{
    int to,next,flow,dis;//flow���� dis���� 
}edge[maxn]; //����������Ǳ� 
queue <int> q; //����������ǵ㣨����㵽�յ㣩 

int head[maxn],num_edge;
void add_edge(int from, int to, int flow, int dis){
    ++num_edge;
    edge[num_edge].to=to; //�ߵĶ˵� 
	edge[num_edge].next=head[from]; 
    head[from]=num_edge; //�ڽӱ� 
    edge[num_edge].flow=flow;
    edge[num_edge].dis=dis;
}

//ʹ���������DFS�����������е�����·�� 
int spfa(int s,int t){
    memset(dis,0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis,0,sizeof(vis));
    q.push(s); vis[s]=1; dis[s]=0; pre[t]=-1;

    while (!q.empty()) {
        int now=q.front(); q.pop();
        vis[now]=0; 
        for(int i=head[now]; i!=-1; i=edge[i].next) {//��ǰ�˵�now�������źܶ�ĺ�˵�i 
            if(edge[i].flow>0 && dis[edge[i].to]>dis[now]+edge[i].dis) { //��i���߻����������һ�ʹ���ø�С 
                dis[edge[i].to]=dis[now]+edge[i].dis;
                pre[edge[i].to]=now; //ÿ����������ǰ�˵���now 
                last[edge[i].to]=i; //ÿ�����������ǰһ���� 
                flow[edge[i].to]=min(flow[now],edge[i].flow);//�������ȡ������С���� 
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
		add_edge(b,a,0,-d); //���ߵ�����Ϊ0���������෴�� 
    }
    
    while(spfa(1,n)!=-1) {  //���������ϵĸ������� 
        maxflow+=flow[n];
        mincost+=flow[n]*dis[n];
        int now=n;
        while(now!=1) {//��Դ��һֱ���ݵ���� 
            edge[last[now]].flow-=flow[n];//flow��dis���׸�� 
            edge[last[now]^1].flow+=flow[n];
            now=pre[now];
        }
    }
    
    printf("%d %d",maxflow, mincost);
    return 0;
} 
