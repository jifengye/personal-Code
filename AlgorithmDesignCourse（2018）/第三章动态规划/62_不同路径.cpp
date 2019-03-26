/* 题目：62. 不同路径
 * 要求：一个 m x n 网格，一个机器人位于左上角，每次只能向下或者向右移动一步，机器人试图达到网格的右下角。
		总共有多少条不同的路径？
 * 来源：https://leetcode-cn.com/problems/unique-paths/description/
 * 时间：2018/11/22
 */

/**
	动态规划
	只能向下或者向右移动 
		-> 网格上边界和左边界只有一种方法能到达
		结论1： 到达(0,j)、(i,0)点方法数 dp[i,j] =  1
		-> 要到达此外的某个点，只能通过该点左边或上边的格子出发
	 	结论2：到达(i,j)点方法数 dp[i,j] =  dp[i-1,j] + dp[i,j-1]
	为了两个结论统一公式，我们使用n+1*m+1数组，上、左边界用0表示，起点变为（1,1）
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0) return 0;
		
		vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 

		dp[1][1]=1; //在这里(1,1)表示起点 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
			}
		}
		
		return dp[n][m];
	}
};


int main() {
	Solution solu;
	cout << solu.uniquePaths(3,2);
	return 0;
} 





/*
	其实这道题是数学中的概率统计
	一共要往下走 n-1 步，往右走 m-1 步。等价于 (n-1)+(m-1) 步中挑出 n-1 步往下
	即为组合数C(n-1)(n+m-1) 
	结合公式 C(m,n)=n!/(m!*(n-m)!) = factorial(n)/(factorial(m)*factorial(n-m))
	问题是：阶乘最后数据太大了，long型也无法放下 
*/
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	long factorial(long number){ //用递归实现阶乘 
//		return number<=1 ? 1:number*factorial(number-1);
//		cout << number; 
//	}
//	
//	int uniquePaths(int m, int n) {
//		if (m==0 || n==0) return 0;
//		return factorial(n+m-2)/(factorial(m-1)*factorial(n-1));
//	}
//};
//
//
//int main() {
//	Solution solu;
//	cout << solu.uniquePaths(1,100);
//	return 0;
//}

