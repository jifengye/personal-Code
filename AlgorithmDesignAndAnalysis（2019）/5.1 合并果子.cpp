/*
算法设计与分析 5.1 合并果子
★题目描述
GYY面前有N堆果子，分别有1，2，3，。。。。，N个果子，这N堆果子一开始按照某种顺序排列。
GYY有一种独特的魔法，他每轮操作会依次把第i+1堆的果子复制一份加到第i堆上，最后舍弃掉最后一堆。
N轮操作之后，就只剩下一堆果子了（废话）。
然而当GYY忙活完这一切的时候，他发现他忘了自己一开始的N堆果子是怎么摆放的了，
现在给你操作轮次数和最后那堆果子的数量，找到一个满足条件的初始排列
如果有多个解则输出字典序最小的那一个。

★输入格式
输入仅一行，包括两个正整数N和Sum，表示一开始有N堆果子
操作了N轮后剩下的那堆果子有Sum个。

★输出格式
输出包括N个整数，相邻两个整数之间用空格隔开，如果无解则输出“GG”，
如果多解输出字典序最小的那一组解。
注意，行末多余的空格可能会导致答案错误。

★样例输入
4 16
★样例输出
3 1 2 4

★HINT
3   1   2   4
  4   3   6
    7   9
     16
对于60%的数据，N <= 7; 
对于100%的数据，N <= 12, Sum <= 20000。
*/

/*
每堆果子合并次数的规律符合杨辉三角
下面是一个杨辉三角
      1
	1   1
  1   2   1
1   3   3   1 
用杨辉三角作为系数， 乘上每堆果子的数量应该为sum
1*3 + 3*1 + 3*2 + 1*4 = 16 


数据量好像不大，尝试一下回溯穷举果子数量的排列

所以接下来的问题就是按照字典序的顺序生成果子数量方案 
生成全排列方案可以使用next_permutation 
*/
#include<bits/stdc++.h>
using namespace std;

int N,Sum;
int yhs[13]; 
int res[13]; 
int ok=0;

int IsCorr(){
	int ans=0;
	for(int i=1; i<=N; ++i) ans+=yhs[i]*res[i];
	return Sum==ans;
} 


int main(){
	scanf("%d%d",&N, &Sum);
	
	//构造杨辉三角
	memset(yhs, 0, sizeof(yhs)), yhs[1]=1;
	for(int k=2; k<=N; ++k){
		for(int i=k; i>0; --i){
			yhs[i]=yhs[i]+yhs[i-1];
		}
	}

	//穷举每堆果子可能的个数，按字典序穷举 
	for(int i=1; i<=N; ++i) res[i]=i;
    do {
		if(IsCorr()){
			ok=1;
			break;
		}
	} while(next_permutation(res+1, res+N+1));
	
	//结果输出
	if(ok){
		for(int i=1; i<=N; ++i) printf("%d ",res[i]);
		printf("\n");
	} 
	else printf("GG\n");
	return 0;
} 
