/* 题目：303. 区域和检索 - 数组不可变
 * 要求：给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 来源：https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 * 时间：2018/11/21
 */
 
/**
	动态规划
		很简单，就是和差  sum[i,j] = sum[0,j] - sum[0,i] 
		... ...
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class NumArray {
private:
	int *pre_sum;

public:
	NumArray(vector<int> nums) {
		if (nums.empty())  return;

		int n = nums.size();
		pre_sum = new int[n+1];
		pre_sum[0] = 0;
		for (int i=0; i<n; i++) {
			pre_sum[i+1] = pre_sum[i] + nums[i];
		}
	}
	
	int sumRange(int i, int j) {
		return pre_sum[j+1]-pre_sum[i];
	}
};

int main() {
	NumArray numA({-2, 0, 3, -5, 2, -1});
	
	cout << numA.sumRange(0, 2) << endl;
	cout << numA.sumRange(2, 5) << endl;
	cout << numA.sumRange(0, 5) << endl;
	
	return 0;	
}

