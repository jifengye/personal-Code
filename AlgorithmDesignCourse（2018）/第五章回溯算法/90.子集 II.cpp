/* 90. �Ӽ� II
 * https://leetcode-cn.com/problems/subsets-ii/description/
 * ����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
 * ����: [1,2,2]
 * ���: [[2],[1],[1,2,2],[2,2],[1,2],[]]
 * 2018/10/21
 */

/*
˼·
	�����롶78. �Ӽ���˼·�����ơ� 
	��Ϊ ��78. �Ӽ�������nums�ǲ��ظ��ģ�����������nums�����ظ���
	�Ȿ�����Ҫ�ĵ���Ҫ����
	Ȼ�����ͬ��Ԫ�ػ��ֳ�һ��
	Ȼ���Ԫ��ʱ��һ��һ��Ŀ��ǡ���78. �Ӽ�����һ��Ԫ��һ��Ԫ�ؿ��� 
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
		while (!nums.empty() && nums.back() == elem) { //�ظ��Ļ���һ�� 
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
