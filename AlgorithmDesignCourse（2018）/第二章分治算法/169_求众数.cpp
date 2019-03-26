/* 题目：169.求众数 
 * 要求：给定大小为n的数组，找到其中的众数(定义众数是在数组中出现大于n/2次的元素) 
 * 来源：https://leetcode-cn.com/problems/majority-element/description/ 
 * 输入：2 2 1 1 5 6 1 2 2 1 1
 * 输出：1 
 * 时间：2018/9/23
 */


/* 方法一：打擂台法 
 * 描述： 若和擂主同派系，则擂主势力++，否则擂主势力--；台上没人，则成为新的擂主。
 * 时间复杂度： O(n)
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int ans = nums[0];//擂主
		int cnt = 0;//擂主的势力
		for(int i=0; i<nums.size(); i++){
			// 打擂 
			if(nums[i] == ans) cnt++; 
			else cnt--;
			
			// 判断擂主属于谁 
			if(cnt < 0) {
				ans = nums[i];
				cnt = 1;
			}
		}
		return ans;
	}
};

int main(){
	Solution solu;
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<solu.majorityElement(nums);
    return 0;
}

/* 方法二：排序求中位数 
 * 时间复杂度： 因为使用快排，O(NlogN) 
 * 使用了排序算法解题反而花更多时间 
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		return nums[nums.size() >> 1];
//	}
//};
//
//int main(){
//	Solution solu;
//    vector<int> nums={2,2,1,1,1,2,2};
//    cout<<solu.majorityElement(nums);
//    return 0;
//}
