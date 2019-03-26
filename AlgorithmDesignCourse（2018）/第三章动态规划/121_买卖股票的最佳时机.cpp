/* ��Ŀ��121. ������Ʊ�����ʱ�� 
 * Ҫ�󣺸���һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
 		��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
 * ��Դ��https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/ 
 * ʱ�䣺2018/9/27 
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
