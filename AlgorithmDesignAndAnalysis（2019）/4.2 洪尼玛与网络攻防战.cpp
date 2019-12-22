/*
算法设计与分析 4.2 洪尼玛与网络攻防战

★题目描述
有n名黑客袭击了他公司的账户，第i名黑客每分钟可以从账户中盗取ci元，对付第i名黑客需要2*ti时间 
一旦洪尼玛对第i名黑客开始进行攻防，该黑客将无法继续盗取钱财，但其他未被攻防的黑客可以继续盗取钱财。
这n名黑客从第0时刻开始进行袭击。洪尼玛想知道对付完这n名黑客后被盗取的金额最小是多少？

★输入格式
第一行为一个正整数n，表示黑客的数量；
接下来n行，每行两个正整数ci、ti，表示第i名黑客；
对于60%的数据，1<=n<=103；
对于100%的数据，1<=n<=105、1<=ci、ti<=103。

★输出格式
输出一个正整数，表示被盗取的最小金额。

★样例输入
5
1 1
2 2
3 3
4 4
5 5
★样例输出
170
*/

/*
首先不是先把ci最大的砍死，因为当砍死ci-1的黑客只需要1秒呢 
也不是先把ti最小的砍死，因为当tk最大的黑客其ck是105量级呢
那么此时问 ci/ti 表示什么：
是否根据 ci/ti 排序来： 
*/ 
#include<bits/stdc++.h>
using namespace std;
long long ID[100005];
long long C[100005];
long long T[100005];
long long ans=0;
long long res=0; 
int n;

bool cmp(const long long a, const long long b){
	return C[a]*T[b] > C[b]*T[a];
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		scanf("%lld%lld", &C[i], &T[i]);
		ID[i]=i;
		ans+=C[i];
	}
	
	sort(ID, ID+n, cmp);
	
	for(int i=0; i<n; ++i){
		ans-=C[ID[i]];
		res+=ans*T[ID[i]]*2;
	}
	printf("%lld\n",res);
	return 0;
}
/*
3
6 3
5 2
4 1
*/





/**
暴力 
*/

//#include<bits/stdc++.h>
//using namespace std;
//int Order[100005];
//int C[100005];
//int T[100005];
//long long ans=0;
//long long minres=0x3f3f3f3f; 
//int n;
//
//void dfs(int step, long long res){
//	if(ans>res) return;
//	if(step==n){
//		if(res<=minres){			
//			printf("minres=%d, solve order: ",res);
//			for(int i=0; i<n; ++i){
//				printf("%d ",Order[i]);
//			}
//			printf("\n");
//		}
//		minres = min(minres, res);
//		return;
//	}
//	for(int i=step; i<n; ++i){
//		swap(Order[step], Order[i]);
//		ans -= C[Order[step]];
//		dfs(step+1, res+(ans*2*T[Order[step]]));
//		ans += C[Order[step]];
//		swap(Order[step], Order[i]);
//	}
//} 
//
//int main(){
//	scanf("%d",&n);
//	for(int i=0; i<n; ++i){
//		scanf("%d%d", &C[i], &T[i]);
//		Order[i]=i;
//		ans+=C[i];
//	}
//	
//	
//	for(int i=0; i<n; ++i){
//		swap(Order[0], Order[i]);
//		ans -= C[Order[0]];
//		dfs(1, ans*2*T[Order[0]]);
//		ans += C[Order[0]];
//		swap(Order[0], Order[i]);
//	}
//	printf("%d\n",minres);
//	return 0;
//}
/*
8
6 6
3 2
4 1
4 4
7 2
4 8
2 5
1 2
2 4 1 0 3 5 7 6
*/ 

