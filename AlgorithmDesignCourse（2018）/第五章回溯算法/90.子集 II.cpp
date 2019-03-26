/* 90. 子集 II
 * https://leetcode-cn.com/problems/subsets-ii/description/
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 输入: [1,2,2]
 * 输出: [[2],[1],[1,2,2],[2,2],[1,2],[]]
 * 2018/10/21
 */

/*
思路
	这题与《78. 子集》思路有类似。 
	因为 《78. 子集》所给nums是不重复的，而本题所给nums是有重复的
	解本题很重要的点是要排序
	然后把相同的元素划分成一组
	然后加元素时：一组一组的考虑。《78. 子集》是一个元素一个元素考虑 
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.empty())  return {{}};

		int elem = nums.back(), cnt = 0;
		while (!nums.empty() && nums.back() == elem) { //重复的划成一组 
			cnt++;
			nums.pop_back();
		}
		
		auto result = subsetsWithDup(nums);
		for (int i=result.size()-1; i>=0; i-- ) {
			auto temp = result[i];
			for (int j=1; j<=cnt; j++) {
				temp.push_back(elem);
				result.push_back(temp);
			}
		}
		return result;
	}
};

void output(vector<vector<int> > matrix){
	for(auto line : matrix){
		for(auto elem : line) cout << elem << ' ';
		cout << endl;
	}
}

int main(){
	Solution solu;
	vector<int> nums = {1,2,2};
	output(solu.subsetsWithDup(nums));
	return 0;
}
