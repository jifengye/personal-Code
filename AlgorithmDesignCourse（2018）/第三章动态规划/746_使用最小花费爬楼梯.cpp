/* ��Ŀ��746. ʹ����С������¥��
 * Ҫ���� n ��¥�ݣ�ÿ��ֻ���� 1 �� 2 ��̨�ס�
 *       ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ.����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ�
 * ��Դ��https://leetcode-cn.com/problems/climbing-stairs/description/
 * ʱ�䣺2018/9/27
 */
 
/**
	��̬�滮  O(n)
		���� 0 ��̨����ͻ��� cost[0] = cost[0] 
		���� 1 ��̨����ͻ��� cost[1] = cost[1] 
		���� 2 ��̨����ͻ��� cost[2] = cost[2] + min(cost[0] , cost[1])  // ֻ�ܴ� 0 �Ż� 1 ��̨�׳���
		���� 3 ��̨����ͻ��� cost[3] = cost[3] + min(cost[1] , cost[2])  // ֻ�ܴ� 1 �Ż� 2 ��̨�׳���
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

