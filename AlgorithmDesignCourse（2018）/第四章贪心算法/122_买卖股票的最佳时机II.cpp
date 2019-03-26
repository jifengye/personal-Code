/* ��Ŀ��122. ������Ʊ�����ʱ�� II
 * Ҫ������һֻ��Ʊ�����������
         ����һ�����飬��i��Ԫ���Ǹù�Ʊ��i��ļ۸񡣿��Զ������
 * ��Դ��https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/ 
 * ʱ�䣺2018-9-30 
 */
 
/* ����һ��̰���㷨 
 * ʱ�䣺O(N)
 * ˼·���ڼ۸�Ĳ������룬�����������൱�����е�����ֵ�������� 
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
			result += max(0, prices[i]-prices[i-1]); //��ֵ����0�ͼ� 
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

