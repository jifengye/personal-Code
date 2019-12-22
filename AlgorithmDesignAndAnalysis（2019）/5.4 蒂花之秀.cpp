/*
算法设计与分析 5.4 蒂花之秀
★题目描述
地图为一个N行M列的阵图，阵图里的各个结点可能是一个无法通过的障碍格，也可能是一个数字格。

可以从阵图上的任意一个数字格出发，每次沿上下左右之一的方向走一格，但不能走到障碍格中，也不能重复经过一格数字格。

将跑步起点的数字格到终点的数字格，途经的所有格上的数字按照访问顺序连接在一起得到一个整数，作为自己训练的评价指标。

现在给你韩跳跳的训练地图，请问他在这张地图上能得到的最大评价指标是多少?

★输入格式
首先输入一个数T(T<=10)，代表总共有T组数据。

每组数据第1行包含两个整数N、M，表示地图为N*M的阵列；

接下来N行每行包括M个字符，由数字“1~9”和“#”组成。

输入保证，每个地图上至少有一个数字格。

★输出格式
每组数据一个整数代表对应地图中能得到的最大评价指标。

★样例输入
1
6 3
122
789
685
7#5
941
48#
★样例输出
9885514849767122

★数据范围
50%的数据：2<=N，M<=10，N*M<=10；
100%的数据：2<=N，M<=15，N*M<=30
*/

/*
数据量似乎不是很大，尝试深搜遍历整个地图 
*/ 

#include<bits/stdc++.h>
using namespace std;

int T,N,M;
char Map[16][16]; 
int  Vis[16][16];
int  Dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
string res,path;

void df(int x, int y){
	int end=1;
	for(int i=0; i<4; ++i){
		int nx=x+Dir[i][0], ny=y+Dir[i][1];
		if(1<=nx && nx<=N && 1<=ny && ny<=M && Vis[nx][ny]==0 && Map[nx][ny]!='#'){
			Vis[nx][ny]=1, path.push_back(Map[nx][ny]), end=0;
//			cout<<"("<<nx<<","<<ny<<")"<<path+Map[nx][ny]<<endl;
			df(nx, ny);
			Vis[nx][ny]=0, path.pop_back();
		}
	}
	if(end){
		if(path.length()>res.length()) res = path;
		else if(path.length()==res.length()) res = max(res, path);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>T;
	while(T--){
		cin>>N>>M;
		
		memset(Vis, 0, sizeof(Vis));
		memset(Map, 0, sizeof(Map));
		res="",path=""; 
		for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j) cin>>Map[i][j];
		
		for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
			if(Map[i][j]=='#') continue;
			Vis[i][j]=1, path.push_back(Map[i][j]);
			df(i, j);
			Vis[i][j]=0, path.pop_back();
		}
		
		cout<<res<<endl;
	}
	return 0;
} 
