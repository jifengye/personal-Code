/* 题目：746. 使用最小花费爬楼梯
 * 要求：爬 n 阶楼梯，每次只能爬 1 或 2 个台阶。
 *       每当你爬上一个阶梯你都要花费对应的体力花费值.您需要找到达到楼层顶部的最低花费。
 * 来源：https://leetcode-cn.com/problems/climbing-stairs/description/
 * 时间：2018/9/27
 */
 
/**
	动态规划  O(n)
		到达 0 号台阶最低花费 cost[0] = cost[0] 
		到达 1 号台阶最低花费 cost[1] = cost[1] 
		到达 2 号台阶最低花费 cost[2] = cost[2] + min(cost[0] , cost[1])  // 只能从 0 号或 1 号台阶出发
		到达 3 号台阶最低花费 cost[3] = cost[3] + min(cost[1] , cost[2])  // 只能从 1 号或 2 号台阶出发
		... ...
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		for (int i=2; i<n; i++) {
			cost[i] += min(cost[i-2],cost[i-1]);
		}
		return min(cost[n-2], cost[n-1]);
	}
};

int main(){
	Solution solu;
	vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	cout<<solu.minCostClimbingStairs(nums);
	return 0;
}

