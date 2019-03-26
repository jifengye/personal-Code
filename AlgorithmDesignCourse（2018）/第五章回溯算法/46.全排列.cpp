/* 46. ȫ����
 * https://leetcode-cn.com/problems/permutations/description/
 * ����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�
 * ����: [1,2,3]
 * ���: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 2018/10/19
 */
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;

/* ����һ������ next_permutation ���� 
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


/* ��������ͨ�� �ݹ� + ����(��iλ�����nums������������) 
 *    ��1λ�����(��������)����������, ��2λ�����(��������)����������
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
		if(cur == nums.size()) { //��������
			result.push_back(nums);
			return; 
		}
		for(int i=cur; i<nums.size(); i++){
			swap(nums[cur], nums[i]);
			dfs(nums, result, cur+1);
			swap(nums[i], nums[cur]); //����Ҫ���ָ�ԭ״ 
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
