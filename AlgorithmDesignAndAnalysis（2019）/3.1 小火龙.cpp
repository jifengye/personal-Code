/*
算法设计与分析 3.1 小火龙
★题目描述
共有N种商品会进行打折，第i种商品打折后的价格为Ci，原价为Vi，从第Ti天开始出售，每种商品限购一件。
如果顾客来的时间早于第Ti天，就无法购买到这件商品。
现在你想知道，倘若你只在第X天带了Y块钱去一次超市，最多可以购买到原价总和为多少的商品。

★输入格式
第一行包括两个正整数N，M，表示有N种商品进行促销，有M个购物询问。
接下来的N行，每行包括三个正整数Ci, Vi, Ti, 分别表示每种商品的折后价，原价， 和开放购买的日期。
接下来的M行，每行包括两个正整数Xi和Yi，表示你想知道第Xi天带着Yi去购物最多能买到原价总和多少的商品。

★输出格式
输出包括M行，每行一次整数，表示对应的购物计划所能买的最大原价总和。

★样例输入
5 2
5 5 4
1 3 1
3 4 3
6 2 2
4 3 2
3 8
5 9
★样例输出
10
12
*/

/*
动态规划算法

每一次购物询问进行一次动态规划，找出最优解

对商品和询问统一进行排序，按时间升序 

这里考虑数据的大小， Ci,Yi<=109, Vi<=300
因此将常用的 maxF[i][c] 改为 minF[i][v]

将这个做改变后，要在更新第二遍 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int ti, ci, vi, yi, i, type;
	Node() {}
	Node(int c, int v, int t):ci(c), vi(v), ti(t), type(0) {} //输入商品 
	Node(int x, int y): ti(x), yi(y), type(1) {}//输入询问 
	bool operator < (const Node &b) const {return ti==b.ti ? type<b.type : ti<b.ti;} //按时间，节点类型升序 
}node[100301]; 

int Vans=0;
long F[100000]; //价值 --> 花费
int res[100001]; 

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	
	int c,v,t;
	for(int i=0; i<N; ++i){
		scanf("%d%d%d",&c, &v, &t);
		node[i] = Node(c, v, t); //输入商品
		Vans += v;
	}
 	
 	int x,y;
	for(int i=0; i<M; ++i){
		scanf("%d%d",&x, &y);
		node[i+N] = Node(x, y); //输入询问 
		node[i+N].i = i;
	}
 	
 	sort(node, node+N+M); //按时间，节点类型升序 
 	
	memset(F, 0x3f, sizeof(F)); F[0]=0;
	for(int i=0; i<N+M; ++i){
		if(node[i].type==0){ //是商品，更新F
			for(int v=Vans; v>=node[i].vi; --v) F[v] = min(F[v],F[v-node[i].vi]+node[i].ci);
			for(int v=Vans; v>=0; --v) F[v]=min(F[v], F[v+1]); //重点，再更新一遍。既然花费F[v+1]能获得V+1价值，那么v价值也肯定可以 
		} 
		else{
			res[node[i].i] = upper_bound(F, F+Vans, node[i].yi)-F-1;  //找到此花费下最大价值（F中上界位置v) 
		}
	}
	
	for(int i=0; i<M; ++i){
		printf("%d\n", res[i]);
	}
	return 0; 
}
