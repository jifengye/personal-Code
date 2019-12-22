/*
算法设计与分析 5.5 真-白给题
★题目描述
给定1-n的一个排列，要求你将它们重排，使得任意两个相邻的数的和为质数。

★输入格式
一个正整数n。n<=20。

★输出格式
输出一行一个1-n的排列，满足相邻的两个数相加为质数。
如果有多组解，输出字典序最小的那一个。
如果无解，输出-1。

★样例输入1
2
★样例输出1
1 2
★样例输入2
3
★样例输出2
1 2 3
*/
/*
优化一：
	一积一偶排列 
*/


#include<bits/stdc++.h>
using namespace std;
int n;
int res[21];

int isPrime(int num){ 
    if(num==2) return true; //2特殊处理 
    if(num<2 || num%2 == 0) return false; //识别小于2的数和偶数 
	for(int i=3; i*i<=num; i+=2){
		if(num%i==0) return false;
	}
	return true;
}

void dfs(int step){
	if(step==n+1){
		for(int i=1; i<=n; ++i) printf("%d ",res[i]);
		exit(0);
	}
	for(int i=step; i<=n; i+=2){
		swap(res[step], res[i]);
		if(isPrime(res[step]+res[step-1])) dfs(step+1);
		swap(res[step], res[i]);
	}
} 

int main(){
	scanf("%d",&n);
 
	for(int i=1; i<=n; ++i){
		res[i]=i;
	}
	
	for(int i=1; i<=n; i+=2){
		swap(res[1], res[i]);
		dfs(2);
		swap(res[1], res[i]);
	}
	printf("-1\n"); 
	return 0;
}




//
///** 测试题 **/
////https://www.luogu.org/problem/UVA524
// 
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int res[21];
//
//int isPrime(int num){ 
//    if(num==2) return true; //2特殊处理 
//    if(num<2 || num%2 == 0) return false; //识别小于2的数和偶数 
//	for(int i=3; i*i<=num; i+=2){
//		if(num%i==0) return false;
//	}
//	return true;
//}
//
//void dfs(int step){
//	if(step==n+1){
//		if(isPrime(res[n]+res[1])){
//			for(int i=1; i<=n; ++i) printf("%d ",res[i]);
//			printf("\n");
//		}
//	}
//	for(int i=step; i<=n; i+=2){
//		swap(res[step], res[i]);
//		if(isPrime(res[step]+res[step-1])) dfs(step+1);
//		swap(res[step], res[i]);
//	}
//} 
//
//int main(){
//	int id=1; 
//	while(~scanf("%d",&n)){	
//		if(id>=2) {     //第二组就要开始输出换行了。。
//            printf("\n");
//        }
//		for(int i=1; i<=n; ++i){
//			res[i]=i;
//		}
//		printf("Case %d:\n",id++);
//		dfs(2);
//	}
//	return 0;
//}
