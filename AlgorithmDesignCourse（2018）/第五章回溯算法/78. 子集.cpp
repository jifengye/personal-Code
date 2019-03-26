/* 78. 子集
 * https://leetcode-cn.com/problems/subsets/description/
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 输入: nums = [1,2,3]
 * 输出: [ [3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[] ]
 * 2018/10/11
 */
 
/* 对于vector容器 
 * vector.push_back(a)  尾部加入一个元素
 * vector.pop_back()  删除尾部一个元素
 * vector.back()   返回尾部一个元素
 */
 
 /*
思路
	这题其实就是概率统计中的排列组合题
	不断迭代，在原有的行基础上复制该行,并尾部加上元素 
　　例如拿【1,2,3】来说
　　第一次：  {}
　　第二次(在原有的行基础加上新元素1) ：{}、{1}
　　第三次(在原有的行基础加上新元素2) ： {}、{1}、{2}、{1,2}
　　第四次(在原有的行基础加上新元素3) ： {}、{1}、{2}、{1,2}、{3}、{1,3}、{2,3}、{1,2,3}
 */ 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> nums) {
		if(nums.empty())  return {{}}; //递归结束 
		
		int elem = nums.back();nums.pop_back();
		vector<vector<int> > result = subsets(nums);
		for(int i=result.size()-1; i>=0; i--){
			result.push_back(result[i]);
			result.back().push_back(elem); //result最后一行增加元素 elem
		}
		return result;
	}
};

void output(vector<vector<int> > matrix){
	for(auto line : matrix){
		for(auto elem : line) cout << elem << ',';
		cout << endl;
	}
}

int main(){
	Solution solu;
	vector<int> nums = {1,2,3};
	output(solu.subsets(nums));
	return 0;
}


/*
和上面的原理一样，只是递归改用for循环
 for(auto elem : nums) 和 递归 异曲同工 
 */
//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int> > subsets(vector<int> nums) {
//		vector<vector<int> > result;
//		result.push_back({});
//		for(auto elem : nums){
//			for(int i=result.size()-1; i>=0; i--){
//				result.push_back(result[i]);
//				result.back().push_back(elem);
//			}
//		}
//		return result;
//	}
//};
//
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
//	vector<int> nums = {1,2,3};
//	output(solu.subsets(nums));
//	return 0;
//}
