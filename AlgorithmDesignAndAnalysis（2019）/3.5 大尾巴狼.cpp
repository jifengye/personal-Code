/*
★题目描述
本期活动中，共有N件商品参与促销。

狼是一种很智慧的动物，店主提出了一个这样的促销方案：每件商品有折扣价Ci和原价Vi。

如果购物车内所有商品的原价和恰好是折扣价的K倍，那么直接免单！

你想知道在能够免单的情况下，最多免费拿走原价总价值和多少的商品。


★输入格式
第一行包括两个正整数N， K，表示共有N件商品，指定的常数为K。

接下来的一行包括N个正整数，第i个正整数表示第i个物品的原价。

接下来的一行包括N个正整数，第i个正整数表示第i个物品的折扣价。


★输出格式
输出仅包括一个正整数，表示你能拿走的最大总价值。

★输入样例
3 2
10 8 1
2 7 1
★输出样例
18

★HINT
对于100%的数据，1<=N<=100，1<=k<=10，1<=Ci，Vi<=100
*/ 

/*
用变量cnt记录原价与折扣价K倍的差值 
F[cnt] 表示为差值cnt为负的情况下能取到的最大价值
G[cnt] 表示为差值cnt为正的情况下能取到的最大价值
最后结果就是看 F[i]+G[i] 和最大即为所求， 
*/

#include<bits/stdc++.h>
using namespace std;

int N,K;
int C[105],V[105];
int F[10005], G[10005]; //价与折扣价K倍的差值  --> 最大总价值 

int main(){
    scanf("%d%d",&N,&K);
    for(int i=1; i<=N; i++)  scanf("%d",&V[i]);
    for(int i=1; i<=N; i++)  scanf("%d",&C[i]);
    
    memset(F, -0X3F, sizeof(F)), F[0]=0;
    memset(G, -0X3F, sizeof(G)), G[0]=0;  
    for(int i=1; i<=N; i++) { //考虑第i件商品 
        int cnt=V[i]-C[i]*K; // 折扣价的K倍与原价之间的差值
        if(cnt<0){
            cnt=-cnt;
            for(int j=10000; j>=cnt; --j) F[j] = max(F[j], F[j-cnt]+V[i]);
        }
        else{
            for(int j=10000; j>=cnt; --j) G[j] = max(G[j], G[j-cnt]+V[i]);
        }
//        cout<<i<<endl; 
//    	for(int j=0; j<=8; ++j) cout<<F[j]<<" ";cout<<endl; 
//    	for(int j=0; j<=8; ++j) cout<<G[j]<<" ";cout<<endl; 
    } 
    
	int res=0;
    for(int i=0; i<10000; ++i) { //折扣价的K倍与原价之间的差值
        res = max(res, F[i]+G[i]);
    }
	printf("%d\n",res==0 ? -1 : res);
    return 0;
}


