/* ��Ŀ��303. ����ͼ��� - ���鲻�ɱ�
 * Ҫ�󣺸���һ����������  nums�������������� i �� j  (i �� j) ��Χ��Ԫ�ص��ܺͣ����� i,  j ���㡣
 * ��Դ��https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 * ʱ�䣺2018/11/21
 */
 
/**
	��̬�滮
		�ܼ򵥣����ǺͲ�  sum[i,j] = sum[0,j] - sum[0,i] 
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

