/* ��Ŀ��198. ��ҽ���
 * Ҫ��ÿ�䷿�ڶ�����һ�����ֽ𡣿���͵�Զ�䷿�ݣ�����Ҫ��͵���ݲ������ڡ� 
		���ܹ�͵�Ե�����߽�
 * ��Դ��https://leetcode-cn.com/problems/house-robber/description/
 * ʱ�䣺2018/11/20
 */
 
/**
	��̬�滮
		ĳ�̶ֳ���͵�Ե�����߽�����Ҫ����͵�ķ���Ҫ�����ܵĶ�
		���仰˵����Ҫ�󣺸� 1�� �� 2�� ͵һ��
		�����������ȼ�����¥�ݻ�����С���⣬ÿ����2����3������������棬
		
		͵�� 0 �ŷ����ۻ�͵�Խ����� nums[0] =  nums[0]
		͵�� 1 �ŷ����ۻ�͵�Խ����� nums[1] =  nums[1]  // 0�ŷ��ݲ���͵
		͵�� 2 �ŷ����ۻ�͵�Խ����� nums[2] =  nums[2] + nums[0]
		͵�� 3 �ŷ����ۻ�͵�Խ����� nums[3] =  nums[3] + max(nums[0], nums[1]) 
		͵�� 4 �ŷ����ۻ�͵�Խ����� nums[4] =  nums[4] + max(nums[1], nums[2])
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
