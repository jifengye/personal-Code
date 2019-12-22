/*
算法设计与分析 5.2 洪尼玛的围栏
★题目描述
有n块长度不同的木板，他想用这些木板拼成一个等边三角形的围栏。
现在，给你这n块木板的长度，洪尼玛想知道他能否拼成这个围栏？
要求：n块木板都得用上。

★输入格式
第一行为一个正整数T，表示有T组测试数据。
对于每组测试数据，第一行为一个正整数n，表示木板个数；
第二行包含n个正整数，表示每块木板的长度。

对于60%的数据，1<=T<=5，3<=n<=5，每块木板长度大于等于1小于等于100。
对于100%的数据，1<=T<=5，3<=n<=10，每块木板长度大于等于1小于等于100。

★输出格式
如果能拼成围栏输出Yes，否则输出No。

★样例输入
2
4
1 2 3 4
4
1 2 3 3
★样例输出
No
Yes
*/

#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int side[3],RSide = 0;
int Len[11]; 

bool cmp(const int a, const int b){
	return a>b;
}


int dfs(int step){
	if(step==n){
//		cout<<side[0]<<side[1]<<side[2]<<endl;
		return side[0]==RSide && side[1]==RSide && side[2]==RSide;
	}
	for(int i=0; i<3; ++i){
		if(side[i]+Len[step]<=RSide){
			side[i]+=Len[step];
			if(dfs(step+1)) return 1;
			side[i]-=Len[step];
		}
	}
	return 0;
}

int fun(){
	scanf("%d",&n);
	int sum=0;
	memset(side, 0, sizeof(side));
	for(int i=0; i<n; ++i){
		scanf("%d", &Len[i]);
		sum += Len[i];
	}
	if(sum%3!=0) return 0;
	RSide = sum/3;
	
	sort(Len, Len+n);
	
	if(Len[0]>RSide) return 0;
	
	return dfs(0); 
}

int main(){
	scanf("%d",&T);
	while(T--){
		fun()==1 ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
