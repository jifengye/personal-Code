/* ��Ŀ��241. Ϊ������ʽ������ȼ�
 * Ҫ�󣺸���һ���������ֺ���������ַ�����Ϊ���ʽ������ţ��ı����������ȼ��������ͬ�Ľ�����������п��ܵ���ϵĽ����
 * ��Դ��https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 * ʱ�䣺2018-11-18
 */

/*
 	�����㷨��
	 	�������Ϊ����������������������Ҫ����ķ���һ�����������հѸ����ٷ�Ϊ�θ��� 
 		���п��ܵĽ���� (..)   op1  (...........)			(......) op1 (.......)			(...........) op1 (..)
 					   (.)op2(.) op1 (..)op2(.......)                .                               .
 					 (.)op2(.) op1 (.)op3(.)op2(..)op3(...)          .                               .
 						.                                            .                               . 
 						.
 						.		
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		for (int i=0; i<input.length(); i++) {
			if( isdigit(input[i]) )  continue; //��������� 

			auto v1 = diffWaysToCompute(input.substr(0, i)); //�����input[i]��ߣ�������ϵĽ��
			auto v2 = diffWaysToCompute(input.substr(i + 1)); //�����input[i]�ұߣ�������ϵĽ��
			for (auto e1 : v1) for (auto e2 : v2) switch (input[i]) {
				case '+' : result.push_back(e1 + e2); break;
				case '-' : result.push_back(e1 - e2); break;
				case '*' : result.push_back(e1 * e2); break;
			}
			
		}
		
		//resultΪ��˵���ݹ鵽���ˣ�inputֻ�������ַ� 
		if (result.empty())  result.push_back(stoi(input));
		return result;
	}
};

void output(vector<int> nums){
	for(auto e:nums)
		cout << e << endl;
}

int main() {
	Solution solu;
    string input = "2*3-4*5";
    output(solu.diffWaysToCompute(input));
    return 0;
}
