/*
算法设计与分析 1.4 区间
★题目描述
有N个区间，第i个区间的端点是li和ri,即第i个区间覆盖了[li,ri]
是否存在一个编号最小的区间包含所有的区间。如果存在，则输出区间编号，否则输出"-1".
区间包含指的是，假设一个区间[a,b]包含另外一个区间[c,d]，需要满足a<=c<=d<=b.

★输入格式
第一行一个整数N表示区间个数，N<=100000
接下去N行每行2个整数li,ri表示第i个区间的端点，1<=li<=ri<=1000000000
对于30%的数据，N<=100, 1<=li<=ri<=100
对于80%的数据，N<=1000, 1<=li<=ri<=1000
对于100%的数据，N<=100000, 1<=li<=ri<=1000000000

★输出格式
一个整数表示满足要求区间的编号。若不存在则输出-1。

★样例输入1
3
1 1
2 2
3 3
★样例输出1
-1
★样例输入2
6
1 5
2 3
1 10
7 10
7 7
10 10
★样例输出2
3
*/

/*
直切要点：
如果存在一个区间包含所有其他区间
那么该区间的长度一定最大 
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int l,r,minL,maxR;
	scanf("%d%d",&minL,&maxR);
	int resL=minL,resR=maxR, resid=1; //如果是区间，那么该区间长度一定最大 
	for(int i=2; i<=n; ++i){
		scanf("%d%d",&l,&r);
		minL = min(l,minL);
		maxR = max(r,maxR);
		
		if(resR-resL<r-l) resL=l,resR=r,resid=i; 
	}
	
	if(resL==minL && resR==maxR) printf("%d\n",resid);
	else printf("-1\n"); 
	return 0;
}
