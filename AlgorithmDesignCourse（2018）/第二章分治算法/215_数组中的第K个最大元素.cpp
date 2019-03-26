/* 题目：215 数组中的第K个最大元素
 * 要求： 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 输入: 3 2 3 1 2 4 5 5 5 6 和 k = 4
 * 输出: 5
 * 时间：2018/9/25 
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
