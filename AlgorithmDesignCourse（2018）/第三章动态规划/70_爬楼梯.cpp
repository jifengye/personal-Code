/* 题目：70. 爬楼梯
 * 要求：爬 n 阶楼梯，每次只能爬 1 或 2 个台阶。有多少种不同的方法可以爬到楼顶呢？
 * 来源：https://leetcode-cn.com/problems/climbing-stairs/description/
 * 时间：2018/9/27
 */
 
 
/**
	动态规划 O(n)
		实质就是斐波那契数列 
		
		注：没有0号台阶，是起点，dp[0]不是。dp[0]值为 1 
		到 1 号台阶方法有 dp[1] = 1   
		到 2 号台阶方法有 dp[2] = dp[1] + dp[0]  // 从1号台阶上去或从起点上去
		到 3 号台阶方法有 dp[2] = dp[2] + dp[1]  // 从2号台阶上去或从1号台阶上去
		... ...
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        if(n<=0)  return 0;
		
		int f0=1,f1=1,f;
        while(n--){
			f=f0+f1;
			f0=f1;
			f1=f;
		}
		return f0; 
	}
};

int main(){
	Solution solu;
	cout << solu.climbStairs(3);
	return 0;
}

