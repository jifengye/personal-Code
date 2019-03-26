/* 题目：122. 买卖股票的最佳时机 II
 * 要求：买卖一只股票，求最大利润。
         给定一个数组，第i个元素是该股票第i天的价格。可以多次买卖
 * 来源：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/ 
 * 时间：2018-9-30 
 */
 
/* 方法一：贪心算法 
 * 时间：O(N)
 * 思路：在价格的波谷买入，波峰卖出。相当于所有递增差值都是利润 
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		for (int i=1; i<prices.size(); i++) {
			result += max(0, prices[i]-prices[i-1]); //差值大于0就加 
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

