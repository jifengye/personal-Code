/* 题目：392.判断子序列
 * 要求：给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
		 s 和 t 中仅包含英文小写字母。
		字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
		（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 来源：https://leetcode-cn.com/problems/is-subsequence/description/
 * 时间：2018-11-05
 */
 

/* 直接暴力解 */ 
#include <string>
#include <iostream>
#include <algorithm> 
using namespace std; 

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if(s.length()==0) return true;
		
		int si = 0;
		for(auto c : t){
			if(si<s.size() && c==s[si]){
				si++;
			}
		}
		return si>=s.size();
	}
};

int main(){
	Solution Solu;
	string s = "leeeeetcode";
	string t = "yyyyylyyyyyyyyyyyyyyyyyyyy";
	cout << boolalpha << Solu.isSubsequence(s,t);
	return 0;
}
