/*
�㷨�������� ·������
����Ŀ����
�����޻�ͼ��һ����·��[V0->V1->������->Vl](V0���ܵ���Vl)����������·���ϵ����нڵ㡣

���ҳ�һ����·���ļ��ϣ�ʹ��ÿ���ڵ�ǡ�ñ�����һ�Σ����·��������������

�������ʽ
����ĵ�һ����������n��m(1<=n<=100��1<=m<=n*(n-1)/2)$����ʾ�����޻�ͼ�Ľڵ����������

������m��ÿ����������a��b(1<=a��b<=m)����һ����aָ��b������ߡ�

�������ʽ
���һ��������ʾ������Ҫ��·��������

����������
11 12
1 2
1 3
1 4
2 5
3 6
4 7
5 8
6 9
7 10
8 11
9 11
10 11
���������
3

������˵��
����·���ֱ�Ϊ(1->4->7->10->11)��(2->5->8)��(3->6->9)��
*/

/*
Ҳ��һ������ͼ���ƥ�����

��Ŀ���ʵ����ٵ�·���� = �ڵ���n - ���ƥ���� 
*/
#include<bits/stdc++.h>
using namespace std;

int Match[101];
int Visit[101];

int H[101];
struct Edge{
	int end,nxt; //β�˵㣬ͷ�ڵ���ͬ����һ���� 
}E[5000];

int idx=0;
void AddEdge(int u, int v){
	++idx;
	E[idx].end=v, E[idx].nxt=H[u];
	H[u]=idx;
}

int find(int x){
	for(int i=H[x]; i!=0; i=E[i].nxt){
		int e=E[i].end;
		if(Visit[e]==0){
			Visit[e]=1;
			if(Match[e]==0 || find(Match[e])){
				Match[e]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int u,v;
	while(m--){
		cin>>u>>v;
		AddEdge(u,v);
	} 
	
	int res=0;
	memset(Match, 0, sizeof(Match));
	for(int i=1; i<=n; ++i){
		memset(Visit, 0, sizeof(Visit));
		res += find(i);
	}
	
	cout<<n-res<<endl;
	return 0;
} 
