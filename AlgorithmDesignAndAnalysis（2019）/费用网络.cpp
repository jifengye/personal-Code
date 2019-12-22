#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
 
int H[maxn],num_edge;
struct Edge{
    int end, next, flow, dis;//flow���� dis���� 
}E[maxn]; //����������Ǳ� 

int idx = -1; 
void AddEdge(int s, int e, int flow, int dis){ //���ڽӱ��¼ϡ��ͼ 
    ++idx;
    E[idx].end=e; //�ߵĶ˵� 
	E[idx].next=H[s]; 
    E[idx].flow=flow;
    E[idx].dis=dis;
    H[s]=idx; //�ڽӱ� 
}


queue<int> Q; //��������ȱ��� 
int dis[maxn],pre[maxn],last[maxn],flow[maxn];//dis��С����;preÿ�����ǰ����lastÿ�����������ǰһ���ߣ�flowԴ�㵽�˴������� 
int vis[maxn];//���� 

int spfa(int s, int t){//ʹ���������DFS�����������е�����·�� 
    memset(dis, 0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis, 0,   sizeof(vis));
	vis[s]=1, dis[s]=0, pre[t]=-1;
    Q.push(s); 

    while(!Q.empty()) {
        int now=Q.front(); Q.pop(); vis[now]=0; 
        for(int i=H[now]; i!=-1; i=E[i].next) {
            if(E[i].flow>0 && dis[E[i].end]>dis[now]+E[i].dis) { //��i���߻����������һ�ʹ���ø�С 
                dis[E[i].end]=dis[now]+E[i].dis;
                pre[E[i].end]=now; //ÿ����������ǰ�˵���now 
                last[E[i].end]=i; //ÿ�����������ǰһ���� 
                flow[E[i].end]=min(flow[now],E[i].flow);//�������ȡ������С���� 
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
		AddEdge(b, a, 0, -d); //���ߵ�����Ϊ0���������෴�� 
    }
    
    int maxflow=0, mincost=0;
    while(spfa(s, t)!=-1) {  //���������ϵĸ������� 
        maxflow+=flow[t];
        mincost+=flow[t]*dis[t];
        int now=t;
        while(now!=s) {//��Դ��һֱ���ݵ���� 
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
