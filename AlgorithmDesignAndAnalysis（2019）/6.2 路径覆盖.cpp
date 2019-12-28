/*
算法设计与分析 路径覆盖
★题目描述
有向无环图上一条简单路径[V0->V1->。。。->Vl](V0可能等于Vl)覆盖了这条路径上的所有节点。

请找出一个简单路径的集合，使得每个节点恰好被覆盖一次，输出路径的最少条数。

★输入格式
输入的第一行两个数字n，m(1<=n<=100，1<=m<=n*(n-1)/2)$，表示有向无环图的节点数与边数。

接下来m行每行两个数字a，b(1<=a，b<=m)代表一条由a指向b的有向边。

★输出格式
输出一个整数表示最少需要的路径条数。

★样例输入
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
★样例输出
3

★样例说明
三条路径分别为(1->4->7->10->11)，(2->5->8)，(3->6->9)。
*/

/*
也是一道二分图最大匹配的题

题目所问的最少的路径数 = 节点数n - 最大匹配数 
*/
#include<bits/stdc++.h>
using namespace std;

int Match[101];
int Visit[101];

int H[101];
struct Edge{
	int end,nxt; //尾端点，头节点相同的下一条边 
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
