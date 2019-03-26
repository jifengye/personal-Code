/* 题目：241. 为运算表达式设计优先级
 * 要求：给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。给出所有可能的组合的结果。
 * 来源：https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 * 时间：2018-11-18
 */

/*
 	分治算法：
	 	把整体分为两个个体解决，个体与整体要解决的方法一样，所以依照把个体再分为次个体 
 		所有可能的结果： (..)   op1  (...........)			(......) op1 (.......)			(...........) op1 (..)
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
			if( isdigit(input[i]) )  continue; //不是运算符 

			auto v1 = diffWaysToCompute(input.substr(0, i)); //运算符input[i]左边，所有组合的结果
			auto v2 = diffWaysToCompute(input.substr(i + 1)); //运算符input[i]右边，所有组合的结果
			for (auto e1 : v1) for (auto e2 : v2) switch (input[i]) {
				case '+' : result.push_back(e1 + e2); break;
				case '-' : result.push_back(e1 - e2); break;
				case '*' : result.push_back(e1 * e2); break;
			}
			
		}
		
		//result为空说明递归到底了，input只有数字字符 
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
