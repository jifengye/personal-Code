/* 46. 全排列
 * https://leetcode-cn.com/problems/permutations/description/
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 输入: [1,2,3]
 * 输出: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 2018/10/19
 */
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;

/* 方法一：调用 next_permutation 函数 
 *
 */ 
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		vector<vector<int> > result;
//		do {
//			result.push_back(nums);
//		} while(next_permutation(nums.begin(), nums.end()));
//		return result;
//	}
//};
//void output(vector<vector<int> > matrix){
//	for(auto line : matrix){
//		cout << '[';
//		for(auto elem : line){
//			cout << elem << ',';
//		}
//		cout << ']' << endl;
//	}
//}
//
//int main(){
//	Solution solu;
//	int a[] = {1,2,3};
//	int n = sizeof(a)/sizeof(a[0]);
//	vector<int> nums(a, a+n);
//
//	output(solu.permute(nums));
//	return 0;
//}


/* 方法二：通过 递归 + 交换(第i位和其后nums所有数都交换) 
 *    第1位和其后(包含本身)所有数交换, 第2位和其后(包含本身)所有数交换
	[1,2,3]   ->   [1,2,3]   ->   [1,2,3]
	                         ->   [1,3,2]
	          ->   [2,1,3]   ->   [2,1,3]
	                         ->   [2,3,1]
	          ->   [3,2,1]   ->   [3,2,1]
	                         ->   [3,1,2]
 */ 
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	void dfs(vector<int> nums, vector<vector<int>>& result, int cur){
		if(cur == nums.size()) { //结束条件
			result.push_back(nums);
			return; 
		}
		for(int i=cur; i<nums.size(); i++){
			swap(nums[cur], nums[i]);
			dfs(nums, result, cur+1);
			swap(nums[i], nums[cur]); //很重要，恢复原状 
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {		
		vector<vector<int>> result;	
		dfs(nums, result, 0);
		return result;
	}
};


void output(vector<vector<int> > matrix){
	for(auto line : matrix) {
		for(auto elem : line) cout << elem << ' ';
		cout << endl;
	}
}

int main(){
	Solution solu;
	vector<int> nums = {1,2,3};
	output(solu.permute(nums));
	return 0;
}
