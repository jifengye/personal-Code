/* 78. �Ӽ�
 * https://leetcode-cn.com/problems/subsets/description/
 * ����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
 * ����: nums = [1,2,3]
 * ���: [ [3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[] ]
 * 2018/10/11
 */
 
/* ����vector���� 
 * vector.push_back(a)  β������һ��Ԫ��
 * vector.pop_back()  ɾ��β��һ��Ԫ��
 * vector.back()   ����β��һ��Ԫ��
 */
 
 /*
˼·
	������ʵ���Ǹ���ͳ���е����������
	���ϵ�������ԭ�е��л����ϸ��Ƹ���,��β������Ԫ�� 
���������á�1,2,3����˵
������һ�Σ�  {}
�����ڶ���(��ԭ�е��л���������Ԫ��1) ��{}��{1}
����������(��ԭ�е��л���������Ԫ��2) �� {}��{1}��{2}��{1,2}
�������Ĵ�(��ԭ�е��л���������Ԫ��3) �� {}��{1}��{2}��{1,2}��{3}��{1,3}��{2,3}��{1,2,3}
 */ 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> nums) {
		if(nums.empty())  return {{}}; //�ݹ���� 
		
		int elem = nums.back();nums.pop_back();
		vector<vector<int> > result = subsets(nums);
		for(int i=result.size()-1; i>=0; i--){
			result.push_back(result[i]);
			result.back().push_back(elem); //result���һ������Ԫ�� elem
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
�������ԭ��һ����ֻ�ǵݹ����forѭ��
 for(auto elem : nums) �� �ݹ� ����ͬ�� 
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
