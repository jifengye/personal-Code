/*
算法设计与分析 2.2 画三角形
★题目描述
编程画出规模为N的三角形。
规模为1的三角形如样例所示。
规模为X的三角形为三个规模为 X-1的三角形拼接而成，如样例所示。

★输入格式
一个整数N，表示三角形的规模。 对于100%的数据，1 <= N <= 10。

★输出格式
画出对应的三角形，注意最后一个有效字符后直接回车，不要输出多余的空格。

★样例输入1
1
★样例输出1
avatar

★样例输入2
2
★样例输出2
avatar
*/


/*
1
 /\
/__\
 

2
   /\
  /__\
 /\  /\
/__\/__\


3
       /\   0
      /__\  1
     /\  /\    2
    /__\/__\   3
   /\      /\    4
  /__\    /__\   5
 /\  /\  /\  /\    6
/__\/__\/__\/__\   7

使用字符数组
每次迭代创建一个新的字符数组 
然后实现每次图案的时候从最底层往上 
*/


#include<iostream>
#include<string.h>
using namespace std;
string sj[1024] = {" /\\", "/__\\"};

void dfs(int n){
	int step = (1<<n-1);
	for(int i=2*step-1; i>=step; --i){
		sj[i] = sj[i-step];
		for(int j=1; j<2*step-i; j++) sj[i]+=" ";
		sj[i] += sj[i-step];
	}
	string tmp;
	for(int i=step-1; i>=0; --i){
		tmp = "";
		for(int j=1; j<=step; j++) tmp+=" ";
		sj[i] = tmp + sj[i];
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i=2; i<=n; i++) dfs(i);
	
	for(int i=0; i<=(1<<n)-1; ++i){
		//printf("%s\n",sj[i].c_str());
		//puts(sj[i].c_str());
		cout<<sj[i]<<endl;
	}
	return 0;
}
