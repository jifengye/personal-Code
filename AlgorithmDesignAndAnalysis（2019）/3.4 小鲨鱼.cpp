/*
算法设计与分析3.4 小鲨鱼

本期活动中，共有N件商品参与促销，你身上带了M块钱。
这N种物品每种物品有价格Ci和原价Vi，以及限购Ki件。
你想知道你最多能够买走原价总和多少的商品。

★输入格式
第一行包括两个正整数N， M，表示共有N件商品，你有M块钱。
接下来的N行，每i行包括三个自然数Ci,Vi,Ki。表示第i件商品的价格、原价和限购数量。

★输出格式
输出仅包括一个正整数，表示你能买走的最大原价总和。

★输入样例
2 8
2 100 4
4 100 2
★输出样例
400

★HINT
1<=N<=200,1<=M<=3000,
0<=Ci<=20,1<=Vi<=200,1<=Ki<=1000000 
*/ 

/*
多重背包问题
但是由于时间的限制，在遍历商品数量时要用二进制的思想 
*/ 
#include<bits/stdc++.h>
using namespace std;
int N,M;
int Ci,Vi,Ki;
int F[3001];

int main(){
	cin>>N>>M;
	
	memset(F, 0, sizeof(F));
	for(int i=0; i<N; ++i){
		scanf("%d%d%d",&Ci,&Vi,&Ki);
		for(int k=1; k<=Ki; Ki-=k, k=min(k*2, Ki)){  
			for(int v=M; v>=Ci; --v){
				if(v>=k*Ci) F[v] = max(F[v], F[v-k*Ci]+k*Vi);
			}
			if(k==Ki) break;
		}
	}
	
	cout<<F[M]<<endl;
	return 0;
} 
