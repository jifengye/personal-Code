/* 题目：198. 打家劫舍
 * 要求：每间房内都藏有一定的现金。可以偷窃多间房屋，但是要求被偷房屋不能相邻。 
		求能够偷窃到的最高金额。
 * 来源：https://leetcode-cn.com/problems/house-robber/description/
 * 时间：2018/11/20
 */
 
/**
	动态规划
		某种程度上偷窃到的最高金额就是要求所偷的房屋要尽可能的多
		换句话说就是要求：隔 1家 或 2家 偷一次
		所以这个问题等价于走楼梯花费最小问题，每次走2步或3步，问最大收益，
		
		偷到 0 号房屋累积偷窃金额最高 nums[0] =  nums[0]
		偷到 1 号房屋累积偷窃金额最高 nums[1] =  nums[1]  // 0号房屋不能偷
		偷到 2 号房屋累积偷窃金额最高 nums[2] =  nums[2] + nums[0]
		偷到 3 号房屋累积偷窃金额最高 nums[3] =  nums[3] + max(nums[0], nums[1]) 
		偷到 4 号房屋累积偷窃金额最高 nums[4] =  nums[4] + max(nums[1], nums[2])
		... ...
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return  0;
		else if(n==1) return nums[0];
		else if(n==2) return max(nums[0], nums[1]);
		
		nums[2] += nums[0];
		for (int i=3; i<n; i++) {
			nums[i] += max(nums[i-3], nums[i-2]);
		}
		return max(nums[n-2], nums[n-1]);
	}
};

int main(){
	Solution solu;
	vector<int> nums = {2,7,9,3,1};
	cout << solu.rob(nums);
	return 0;
}
