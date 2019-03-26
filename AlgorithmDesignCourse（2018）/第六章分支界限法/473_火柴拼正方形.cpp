/* 题目：473. 火柴拼正方形
 * 要求：输入每根火柴长度。判断是否能用所有的火柴拼成正方形
 * 来源：https://leetcode-cn.com/problems/matchsticks-to-square/description/
 * 时间：2018-11-16
 */

/**
	暴力解法
		每条火柴分别分配到四条边，穷举所有组合，直到有成功的方案返回
		
	改进： 
		通过所有火柴长度和可以求出正方形边长，
		得到剪枝条件：一旦长度超过边长，该方案不成立，剪枝
		简化判断成功条件：只要能组合出三条边，第四条一定能成功 
		更快达到剪枝条件：火柴按长度从大到小排序 
*/	 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
	int circumfer; //正方形周长 
	int sideLength; //正方形边长 
	vector<int> sides = {0,0,0,0}; //四条边
	
	bool dfs(const vector<int>& nums, int id) {
		if(id == nums.size()) 
			return sides[0]==sideLength && sides[1]==sideLength && sides[2]==sideLength;
			
		for (int i=0;i<4;i++) {
			if (sides[i]+nums[id] > sideLength) continue; //剪枝 
			
			sides[i] += nums[id];
			if(dfs(nums,id+1)) return true; //剪枝，有成功的方案，算法停止 
			sides[i] -= nums[id];
		}
		return 0;
	}
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) return false;
		
		circumfer = accumulate(nums.begin(),nums.end(),0); //所有火柴长度和 
		if (circumfer%4 != 0) return false; 
		
		sort(nums.begin(),nums.end(),greater<int>()); //降序 
		sideLength = circumfer/4;
		if (nums[0] > sideLength) return false; 
		
		return dfs(nums,0);
	}
};

int main() {
	Solution solu;	
	vector<int> nums({1,1,2,2,2});	
	cout << solu.makesquare(nums);
	return 0;
}
