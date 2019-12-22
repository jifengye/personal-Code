/*
算法设计与分析 1.1 Joyvan的矩阵
★题目描述
Joyvan有一个大小为n * m的矩阵，现在他要对矩阵进行q次操作，操作分为如下三种：
0 x y：交换矩阵的x、y两行。
1 x y：交换矩阵的x、y两列。
2 x y：求当前矩阵第x行第y列的元素。

★输入格式
第一行三个正整数n、m、q，表示矩阵大小和操作次数。
接下来n行，每行m个空格隔开的整数，表示矩阵的元素。
接下来q行，每行三个数op、x、y，表示上述操作中的一种。
对于80%的数据，1 <= n、m、q <= 1000。
对于100%的数据，1 <= n、m <= 1000,1 <= q <= 1000000,矩阵元素大小在int范围内且非负。

★输出格式
对于操作2，输出一个整数，表示对应的元素。

★样例输入
2 2 6
1 2
3 4
0 1 2
1 1 2
2 1 1
2 1 2
2 2 1
2 2 2
★样例输出
4
3
2
1
★提示
输入规模较大，请使用scanf/printf。
*/

/*
不要再原矩阵上坐变换
用列表C记录矩阵列序号
用列表R记录矩阵行序号
行列的交换再列表C、R上做表示 
*/ 
#include<bits/stdc++.h>
using namespace std;

int M[1001][1001];//记录矩阵 
int C[1001];
int R[1001];

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; ++i){
		R[i]=i;
		for(int j=1; j<=m; ++j){
			scanf("%d",&M[i][j]);
			C[j]=j; 
		}
	}
	
	int opt,x,y;
	while(q--){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==0) 
			swap(R[x],R[y]);
		else if(opt==1)
			swap(C[x],C[y]);
		else
			printf("%d\n",M[R[x]][C[y]]);	
	}
	return 0;
}
