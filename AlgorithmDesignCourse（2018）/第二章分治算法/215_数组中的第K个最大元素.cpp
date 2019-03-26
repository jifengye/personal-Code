/* ��Ŀ��215 �����еĵ�K�����Ԫ��
 * Ҫ�� ��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
 * ����: 3 2 3 1 2 4 5 5 5 6 �� k = 4
 * ���: 5
 * ʱ�䣺2018/9/25 
 */
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		k = nums.size() - k;
		nth_element(nums.begin(), nums.begin() + k, nums.end());
		return nums[k];
	}
};

int main(){
    Solution solu;
    vector<int> nums = {3,2,3,1,2,4,5,5,5,6};
    int k = 4;
    cout<<solu.findKthLargest(nums,k);
    return 0;
}
