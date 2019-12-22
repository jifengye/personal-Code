/*算法设计与分析 4.3 洪尼玛与芒果篮
★题目描述
有一天，洪尼玛来到楼下超市准备买芒果，刚好商家正在做促销活动。
一共有n篮芒果，第i篮有ai个芒果。
商家给出m个可以选择的区间li、ri，你需要从中选择k个区间，
这k个区间的交集所对应位置上的芒果就可以以一块钱全部购得。
洪尼玛刚好只剩一块钱，他想知道用这一块钱最多可以买多少个芒果？

★输入格式
第一行为三个正整数n、k、m，表示芒果篮数、需选择的区间个数和可以选择的总区间个数；
第二行包含n个正整数，表示每篮的芒果个数；
接下来m行，每行两个正整数li、ri，表示可以选择的区间；
对于60%的数据，1<=n<=103、1<=k<=m<=103；
对于100%的数据，1<=n<=105、1<=k<=m<=105、0<=ai<=109、1<=li<=ri<=n。

★输出格式
输出一个正整数，表示最多的芒果个数。

★样例输入
5 2 4
1 2 3 4 5
1 2
2 3
3 4
2 5
★样例输出
７
*/
/*
本题是区间的并集查找 

先按照左端点从小到大对区间排序
然后将前k个区间的右端点放入最小优先队列中
此时这k个区间的并集为【第k个区间的左端点（因为左端点依据排序了），优先队列中最小的右端点】 
那么就可以得到这k个区间的芒果数

接站遍历区间 
不断的删除优先队列中最小右端点，加入新区间的右端点 
*/
#include<bits/stdc++.h>
using namespace std;

int n,k,m;
int sum[100005] = {0};
struct section{
	int l,r;
	section() {}
	section(int v1, int v2):l(v1),r(v2){}
	bool operator < (const section &b) const{return l==b.l ? r<b.r : l<b.l;}
}S[100005];

int main(){
	scanf("%d%d%d",&n,&k,&m);
	
	int a;
	for(int i=1; i<=n; ++i) scanf("%d",&a), sum[i] = sum[i-1]+a;
	for(int i=1; i<=m; ++i)	scanf("%d%d",&S[i].l, &S[i].r);
	
	sort(S+1, S+m+1);
	
	int res=0;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=1; i<=m; ++i){
		q.push(S[i].r);
		if(q.size()==k){
//			cout<<S[i].l<<" "<<q.top()<<" "<<sum[q.top()]-sum[S[i].l-1]<<endl;
			res = max(res, sum[q.top()]-sum[S[i].l-1]);
			q.pop();
		}
	}
	
	printf("%d\n",res);
	return 0;
} 
