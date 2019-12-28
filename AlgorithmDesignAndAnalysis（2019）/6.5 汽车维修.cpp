/*
�㷨�������� ����ά��
����Ŀ����
��Nλ�ͻ��������ȴ�ά�ޣ�����M��ά��Ա��ÿ��ά��Ա����ÿ̨������ʱ�䲻ͬ��
�밲��ÿ��ά��Ա��Ҫά�޵ĳ���ά��˳��ʹ�����пͻ��ܵȴ�ʱ�����١�

�������ʽ
����ĵ�һ����������M��N(1<=N��M<=20��1<=K<=20)����ʾά��Ա��Ŀ��������Ŀ��
������N��ÿ��M������Ti��j(1<=Ti��j<=20)�����j��ά��Ա�����i������ҪTi��jʱ��

�������ʽ�����С���ܵȴ�ʱ�䡣

����������
2 2
3 2
1 4
���������
3
*/


/*
���������С��������

����������Ҫ��ι����������ͼ

��α��һ�������ܵȴ�ʱ��Ĺ��ף�
��i�ų��ǵ�jλά��Ա����ĵ�����k��������ô����ʱ��Ĺ��� T = k*T[i,j] 
��Ϊ�˱���࣬�����á�������k�������������Խ��û��Ӱ�죩

����ͼ������ʾ

���ھ�����������ͼ���������������С���� 
*/
#include<bits/stdc++.h>
using namespace std;

int M,N;
int T[20+5][20+5]; 
struct Edge{
    int to,next,flow,dis;//flow���� dis���� 
}E[10000]; //����������Ǳ� 
int H[10000], numEdge;
void AddEdge(int u, int v, int f, int d){
    ++numEdge;
    E[numEdge].to=v;
    E[numEdge].flow=f;
    E[numEdge].dis=d;
	E[numEdge].next=H[u]; 
    H[u]=numEdge;
}


bool vis[10000];
int dis[10000],pre[10000],last[10000],flow[10000];//dis��С����;preÿ�����ǰ����lastÿ�����������ǰһ���ߣ�flowԴ�㵽�˴������� 
int maxflow,mincost;
queue <int> q; //����������ǵ㣨����㵽�յ㣩 


//ʹ���������DFS�����������е�����·�� 
int spfa(int s,int t){
    memset(dis,0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis,0,sizeof(vis));
    q.push(s); vis[s]=1; dis[s]=0; pre[t]=-1;

    while (!q.empty()) {
        int now=q.front(); q.pop();
        vis[now]=0; 
        for(int i=H[now]; i!=-1; i=E[i].next) {//��ǰ�˵�now�������źܶ�ĺ�˵�i 
            if(E[i].flow>0 && dis[E[i].to]>dis[now]+E[i].dis) { //��i���߻����������һ�ʹ���ø�С 
                dis[E[i].to]=dis[now]+E[i].dis;
                pre[E[i].to]=now; //ÿ����������ǰ�˵���now 
                last[E[i].to]=i; //ÿ�����������ǰһ���� 
                flow[E[i].to]=min(flow[now],E[i].flow);//�������ȡ������С���� 
                if(!vis[E[i].to]) {
                    vis[E[i].to]=1;
                    q.push(E[i].to);
                }
            }
        }
    }
    return pre[t];
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>M>>N;
	int sta=0, end=N+M*N+1; //������Դ�㡱�͡�������㡱
	for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
		cin>>T[i][j];
	} 
	
	//��������ͼ
	memset(H,-1,sizeof(H)), numEdge=-1; 
	for(int i=1; i<=N; ++i){
		AddEdge(sta, i, 1, 0); //�ӡ�����Դ�㡱������i������ 
		AddEdge(i, sta, 0, 0);
		
		for(int j=1; j<=M; ++j) for(int k=1; k<=N; ++k){ 
			AddEdge(i, j*N+k, 1, k*T[i][j]); //�ӡ���i������������j��ά��Ա�޵ĵ�����k������
			AddEdge(j*N+k, i, 0, -k*T[i][j]);
			if(i==N){
				AddEdge(j*N+k, end, 1, 0); //�ӡ���j��ά��Ա�޵ĵ�����k����������������㡱 
				AddEdge(end, j*N+k, 0, 0);
			}
		}
	}
	
	//���������С���� 
	int maxflow=0, mincost=0;
	while(spfa(sta, end)!=-1) {  //���������ϵĸ������� 
		maxflow+=flow[end];
        mincost+=flow[end]*dis[end];
        int now=end;
        while(now!=sta) {//��Դ��һֱ���ݵ���� 
            E[last[now]].flow-=flow[end];//flow��dis���׸�� 
            E[last[now]^1].flow+=flow[end];
            now=pre[now];
        }
    }
    cout<<mincost<<endl;
    return 0;
}
