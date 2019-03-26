/* 题目：121. 买卖股票的最佳时机 
 * 要求：给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 		如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 来源：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/ 
 * 时间：2018/9/27 
 */
 

#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int cost = INT_MAX, result = 0;
		for(int i=0; i<prices.size(); i++) {
			cost = min(cost, prices[i]);
			result = max(result, prices[i] - cost);
		}
		return result;
	}
};

int main(){
	Solution solu;
	vector<int> nums = {7,1,5,3,6,4};
	cout<<solu.maxProfit(nums);
	return 0;
}
