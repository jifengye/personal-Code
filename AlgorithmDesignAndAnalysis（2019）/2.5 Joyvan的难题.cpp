/*
算法设计与分析 2.5 Joyvan的难题
★题目描述
Joyvan最近遇到了一个难题,对于一个包含
N个整数的序列a1,a2,……,aN，定义：f(i,j)=(j-i)2+(j∑k=i+1 ak)2
现在Joyvan想要你帮他计算所有
f(i,j)(1<=i<j<=N)的最小值。

★输入格式
输入的第一行为数字N，表示给定序列的长度。
第二行包含N个整数，表示序列中的整数a1,a2,……,aN。


★输出格式
输出一个整数，即所有f(i,j)(1<=i<j<=N)的最小值。

★样例输入
4
1 0 0 -1
★样例输出
1
*/
/*
对公式进行变形
假设 xi=i，yi= i∑k=1 ak
那么 f(i,j)=(xj-xi)2+(yj-yi)2
那么也就是相当于问距离最近的两点

现在的问题就是如何使用二分法找到距离最近的两点

可以百度“平面最近点对”，即可找到模板题 

如果是一维的一列数组我们是如何找到差最小的两个数呢？
	方法一是暴力，需要比较（n-1）！，不采取 
	方法二是按照数值大小排序后，比较（n-1）次，需要logn，
		但是二维情况下如何定义这个排序？想不出来。这个方法用不了
	方法三就是分治了
		首先将点图按照X排序、分成左右两半，这时所求最近的两点有如下三种情况： 
			所求两点都在左半边
			所求两点都在右半边
			所求两点一个在左，一个在右
		变成算法就是
			已知 PL、PR 两个集合的最近点对距离 dl, dr，求 P 的最近点对。
			面对情况一二：继续二分 
			面对情况三：由于 PL、PR 两个集合的最近点对已知，令 lim = min(dl, dr)，
			PL、PR 之间的最近点对只会存在于以直线 l 为中心，宽度 2lim 的垂直带形区域中。


注意一个坑，要小心数据的范围，要使用long型 
在 Dist 求两点的平方距离中，要将int型强制转化为long型 
 */
 
#include<bits/stdc++.h>
#define sq(x) ((x)*(x))
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int n;
struct Point{
	int x, y;
	bool operator < (const Point &b) const {return y<b.y;}
}P[100005], tmp[100005]; 

long Dist(struct Point a, struct Point b){
	return sq(a.x-b.x) + sq(a.y-b.y);
}

int cmpy(struct Point a, struct Point b){
	return a.y<b.y;
}

long long  df(int L, int R){
	if(L>=R) return 0x3fffffff;
	if(L+1==R) return sq(P[L].x-P[R].x) + sq(P[L].y-P[R].y);
	
	int mid = (L+R)>>1;
	long lim = min(df(L, mid-1), df(mid+1, R));
	
//	int m=0;
//	for(int i=L; i<=R; ++i) if(sqr(i-mid)<=lim) tmp[m++]=P[i];
//	
//	sort(tmp, tmp+m);
	
	for(int i=0; i<m; ++i) 
		for(int j=i+1; j<m; ++j){
			long y_dist = sq(tmp[j].y-tmp[i].y)
			if(y_dist>lim) break;
			lim = min(lim, y_dist);
	}
	return lim;
}

int main(){
	int a, ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",&a);
		P[i].x = i;
		// P[i].y = P[i-1].y+a;
		ans += a;
		P[i].y = ans;
	}

	printf("%ld\n", df(1, n));
	return 0;
} 
/*
4
1 0 0 -1

2
1 2

2
1 3

3
0 3 -2
*/
