/* 题目：最大子序和
 * 要求：给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 输入：-2 1 -3 4 -1 2 1 -5 4
 * 输出：6 
 * 来源：https://leetcode-cn.com/problems/maximum-subarray/description/
 * 时间：2018/9/16
 */

/* 方法一：贪婪算法
 * 时间复杂度： O(n) 
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//using namespace std;
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = INT_MIN, tmp = 0;
//		for (auto e : nums) {
//			ans = max(ans, tmp += e);
//			tmp = max(tmp, 0);
//		}
//        return ans;
//    }
//};
//
//int main(){
//	Solution solu;
//	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
//	int n = sizeof(a)/sizeof(a[0]);
//	vector<int> nums(a, a+n);
//	
//    cout<<solu.maxSubArray(nums);
//    return 0;
//}





/* 方法二：分治算法 
 * 时间复杂度： O(NlogN)
 * 所花时间比贪心算法更多
数组分成左右两部分，考虑三种情况：
答案数组完全落在左边。
........完全落在右边。
........落在两边。
前两者递归解决。
第三种为左边的一个后缀数组 + 右边的一个前缀数组。
所以问题转化为求数组的最大前缀/后缀数组。 
 */
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> 
using namespace std;

class Solution {
private:
	int maxPreArray(vector<int> nums) { //最大前缀 
		int ans = -INT_MAX, tmp = 0;
		for(int i = 0; i < nums.size(); i++){
			tmp += nums[i];
			ans = max(ans, tmp);
		}
		return ans;
	}
	int maxSufArray(vector<int> nums) { //最大后缀 
		reverse(nums.begin(), nums.end());
		return maxPreArray(nums);
	}
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return -INT_MAX;
		if (nums.size() == 1) return nums[0];//这两个是递归结束
		
		int mid = nums.size() >> 1;
		vector<int> nums_left(nums.begin(), nums.begin() + mid);//把nums对半分成两组
		vector<int> nums_right(nums.begin() + mid, nums.end());
		
		//这就是那三种情况，返回最大的值 
		//要比较 a,b,c 三数大小，可以用 max( max(a,b), c ) 
		return max( max(maxSubArray(nums_left), maxSubArray(nums_right)), maxSufArray(nums_left) + maxPreArray(nums_right) );
	}
};

int main(){
    Solution solu;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<solu.maxSubArray(nums);
    return 0;
}
