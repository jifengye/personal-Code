/* 题目：493. 翻转对 
 * 要求：给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。你需要返回给定数组中的重要翻转对的数量。 
 * 来源：https://leetcode-cn.com/problems/reverse-pairs/description/
 * 输入: 1 3 2 3 1
 * 输出: 2
 * 时间：2018/9/25 
 */
 
/* 方法一：暴力
 * 时间：O(n^2)
 * 只通过了33个实例 
 */
//#include <iostream>
//#include <vector>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//	int reversePairs(vector<int>& nums) {
//		int count=0; //翻转对
//		for(int i=0; i<nums.size(); i++)
//			for(int j=i+1; j<nums.size(); j++)
//				if(nums[i]/2.0>nums[j]) count++;
//		return count;
//	}
//};
//
//int main(){
//    Solution solu;
//    vector<int> nums;
//    int a;
//	cout<<"（输入结束时，先ctrl+d，再enter）"<<endl;
//    while(cin>>a){
//        nums.push_back(a);
//    } 
//    cout<<solu.reversePairs(nums);
//    return 0;
//} 


/* 方法二：分治
 * 时间：O(NlogN)
 * 实质是归并排序算法过程中计算对数 
 */
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
private:
	vector<int> merge(vector<int> left, vector<int> right) { //归并排序方法 
		vector<int> ans;
		int i=0;
		int j=0;
		while(i<left.size() && j<right.size()) {
			if(left[i]<right[j])  ans.push_back(left[i++]);
			else  ans.push_back(right[j++]);
		}
		while(i<left.size()) ans.push_back(left[i++]); 
		while(j<right.size()) ans.push_back(right[j++]);
		
		return ans;
	}
public:
	int reversePairs(vector<int>& nums) {
		if (nums.size() < 2) return 0; //递归结束
		 
		int mid = nums.size() >> 1; //对半分成左右两个 
		vector<int> left(nums.begin(), nums.begin() + mid);
		vector<int> right(nums.begin() + mid, nums.end());
		
		int ans = reversePairs(left) + reversePairs(right); //递归 
		
		int j=0;
		for(int i=0; i<left.size(); i++) {
			for(; j<right.size() && left[i]/2.0-right[j]>0; j++);
			ans += j;
		}
		nums = merge(left, right);//排序和归并
		return ans;
	}
};

int main(){
    Solution solu;
    vector<int> nums = {1,3,2,3,1};
    cout<<solu.reversePairs(nums);
    return 0;
} 
