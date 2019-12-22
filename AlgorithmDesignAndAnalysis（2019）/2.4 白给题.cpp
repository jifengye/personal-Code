/*
算法设计与分析 2.4 白给题
★题目描述
给定N个自然数，你需要选择M个，使得M个数中两两之间的差的绝对值的最小值尽可能大，求这个最大值。

★输入格式
第一行两个空格隔开的正整数N，M，表示自然数个数和要选的数的个数。
接下来一行为N个空格隔开的给定自然数。

★输出格式
一个整数。

★样例输入
3 2
1 2 3
★样例输出
2
*/
/*
先对数列进行排序
然后保存这个序列相邻两个数的差值，组成差值序列 
这个时候就变成一道类型题了， 
现在就是要通过相邻的两个差值合并，使最后余下的m-1个的差值中最小值尽可能的大
 
设置一个变量 间隔res 
设置这个 间隔res 从(max-min)/m开始减小到为1
一旦根据这个间隔可以在差值序列中找到对应的数列，那么就说明这个间隔为答案 

但是这个章节又是讲二分
所以，[0,max_res]间找间隔res应该使用二分 
*/
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int b[200005];

int fun(int res){
	int cnt=0, k=1;
	for(int i=1; i<n; ++i){
		if(res+a[cnt]<=a[i]){
			cnt=i;
			k++;
		}
		if(k>=m) return 1;
	}
	return 0;
}

int df(int L, int R){
//	printf(" **(%d %d %d)\n", L, (L+R)/2, R); 
	if(L>R) return 0;
	
	int mid = (L+R)/2;
	if(fun(mid)) 
		return max(df(mid+1, R), mid);
	else
		return df(L, mid-1);
}

int main(){
	scanf("%d%d",&n, &m);
	for(int i=0; i<n; ++i){
		scanf("%d", &a[i]);
	} 
	
	sort(a, a+n);
 	
	printf("%d\n",df(0, (a[n-1]-a[0])/(m-1) )); 
	
	
}
/*
3 2
1 2 3


10 8
1 10 2 3 4 9 8 7 6 5

10 4
1 10 2 3 3 3 3 3 3 3

8 8
3 4 3 3 3 3 3 3

6 3
1 11 44 33 99 100 
*/
