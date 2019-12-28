/*
算法设计与分析 结对编程
★题目描述
现在有n个代码手和m个观察者，只有相互熟悉的代码手和观察者才能进行良好的结对编程。
请问怎样搭配可以有最多的结对编程组合

★输入格式
输入的第一行三个数字n，m和k(1<=n，m<=100，1<=k<=n*m)，表示代码手人数、观察者人数和熟识的关系数目。
接下来k行每行两个数字a(1<=a<=n)，b(1<=b<=m)代表第a位代码手与第b位观察者相互熟识。

★输出格式
输出一个整数表示最多的结对编程组合。

★样例输入
2 2 2
1 1
2 2
★样例输出
2
*/

/*
用邻接表记录关系 
套一个二分最大匹配模板
n个代码手分到A子集中 
m个观察者分到B子集中 
*/ 
#include<bits/stdc++.h>
using namespace std;

int Match[100+5]; //记录的是B子集（观察者）是否已经匹配了 
int Visit[100+5]; //记录的是B子集（观察者）是否已经问过了 

int H[100+5]; //记录的是A子集（代码手）熟识的观察者 
struct Edge{
	int end,nxt; 
}E[10000+5]; //按照编号记录熟识关系 

int idx=0;
void AddEdge(int u, int v){ //用邻接表方式记录存稀疏图 
    idx++;
    E[idx].end = v;
    E[idx].nxt = H[u];
    H[u] = idx;
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
	return 0;//自己中意的全部都被预定了。配对失败。
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int u,v;
	while(k--){
		cin>>u>>v;
		AddEdge(u,v);
	}
	
	int res=0;
	memset(Match, 0, sizeof(Match));
	for(int i=1; i<=n; ++i){ //因为邻接表是从代码选手角度记录的，所以从代码选手角度出发找配对 
		memset(Visit, 0, sizeof(Visit));
		res += find(i);
	}
	
	cout<<res<<endl;
    return 0;
} 
