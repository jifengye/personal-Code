/*
�㷨�������� ����ȡ��
����Ŀ����
��һ��N��M�е����̣�����ڷ���K�����ӣ�������Ҫ�����ܵĴ�������ȡ����Щ����
�������̵�ÿ��ÿ����������ȡһ�����ӣ����������ȡ�������ӣ�

�������ʽ
����ĵ�һ����������N,M,K(1<=N,M<=100,1<=K<=M*M)$����ʾ��������������
������K��ÿ����������a,b(1<=a<=N,1<=b<=M)����һ��λ��a��b�е����ӡ�

�������ʽ
���һ��������ʾ�����ȡ��������Ŀ��

����������
2 2 4
1 1
1 2
2 1
2 2
���������
2
*/

/*
��Ŀ�ȼ��ڣ�
	ȡ��һ�����ӣ����������ͬ�С�ͬ�еĻᱻ����
	��ô��ξ����ܶ���ó����� 


������һ��ʹ�û��ݷ�
ÿ�е�ÿ�����Ӷ����Թ� 

�Ľ�һ��
	ʹ���ڽӱ��˼��洢�����ñ������ű�
	
�Ľ�����
	���������ٵ��п�ʼȡ����Ч���͸��Ӷ� 
	

�������ʧ��	
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//int n,m,k;
//int Map[101][101];
//int vis[101]; //��־����ȡ���ˣ�������ȡ�� 
//int res=0; 
//
//void dfs(int step, int cnt){
//	if(res==n) return; //���Ѿ������ҵ������ֵ�ˣ����Խ����� 
//	
//	if(step>n){
//		res = max(cnt, res);
//		return;
//	}
//	
//	int j=0;
//	for(int j=0; Map[step][j]!=0; ){
//		j=Map[step][j];
//		if(vis[j]==0){
//			vis[j]=1;
//			dfs(step+1, cnt+1);
//			vis[j]=0;
//		}
//	} 
//	dfs(step+1, cnt);
//}
//
//
//void fun(int i, int j, int nj){
//	while(Map[i][j]!=0) j=Map[i][j];
//	Map[i][j]=nj;
//}
//
//int main(){
//	cin>>n>>m>>k;
//	int a,b;
//	memset(Map, 0, sizeof(Map));
//	memset(vis, 0, sizeof(vis));
//	while(k--){
//		cin>>a>>b;
//		fun(a, Map[a][0], b);
//	}
//	
//	dfs(0,0);
//	
//	printf("%d\n",res);
//	return 0;
//}
/*
2 2 4
1 1
1 2
2 1
2 2



3 3 3
1 3
2 3
3 3


3 3 3
1 3
2 2
3 3

5 1 3
1 1
2 1
3 1


1 5 3
1 2
1 3
1 5


5 6 8
1 1
2 2
1 5
4 3
2 5
3 3
1 6
4 6


*/


/*
��˼·����������ʵ�Ƕ���ͼ
�ȿ������������Ķ��壺
�ڣθ����ͼG��ѡ��m���㣬ʹ��m��������֮��û�б�(û��ĳ�ֹ�ϵ)����m���ֵ��
���ͼ���������ͼ������������ö���ͼƥ�������������������� = N - ���ƥ������

��û��ĳ�ֹ�ϵ���������о���ָû�ù�ͬ���к��� 

�Ƚ�����ƥ���������⣺https://www.acwing.com/problem/content/863/ 
*/ 

#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int H[501]; //��¼�ڵ����ӵıߵı�� 
struct Edge{
	int end,nxt; 
}E[100001]; //���ձ�ż�¼�� 

int Match[501];
int Visit[501];

int idx=0;
void AddEdge(int u, int v){ //���ڽӱ�ʽ��¼��ϡ��ͼ 
    idx++;
    E[idx].end = v;
    E[idx].nxt = H[u];
    H[u] = idx;
}


int find(int x) {
    for(int i=H[x]; i!=0; i=E[i].nxt) { //������x�����ı� 
        int e = E[i].end;
        if(!Visit[e]){ //�������һ��ģ��ƥ����,���Ů����δ��Ԥ��
            Visit[e] = 1; //��x��Ԥ�����Ů����
            if(Match[e]==0 || find(Match[e])) { //���Ů��jû�������ѣ�������ԭ�����������ܹ�Ԥ������ϲ����Ů������Գɹ�
                Match[e] = x;
                return 1;
            }
        }
    }
    return 0;//�Լ������ȫ������Ԥ���ˡ����ʧ�ܡ�
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	
	int u,v;
	memset(H, 0, sizeof(H));
	while(k--){
		scanf("%d%d",&u,&v);
		AddEdge(u, v);
	}
	
	int res=0;
	memset(Match, 0, sizeof(Match));
	for(int i=1; i<=n; i++) {
        memset(Visit,0,sizeof(Visit));//��Ϊÿ��ģ��ƥ���Ԥ��������ǲ�һ��������ÿ��ģ�ⶼҪ��ʼ��
        res += find(i);
    }
    
    printf("%d\n",res);
    return 0;
} 
