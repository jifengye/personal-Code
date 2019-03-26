/* 17. �绰�������ĸ���
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 * ����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
 * ���룺"23"
 * �����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 2018/10/18
 */
 
/* ʹ�õݹ�����ѭ���� 
 * ˼·�ܼ򵥣�������ϣ� 2-abc  3-def 
 * a  ->  ad
          ae
	      af
   b      bd
          be
          bf
   c      cd  
          ce
          cf
 */        
//#include <vector>
//#include <string>
//#include <iostream>
//using namespace std;
//
//class Solution {
//private:
//	void dfs(int current, string &digits, string tmp, vector<string> &result) {
//		if (current == digits.size()) {
//			result.push_back(tmp);
//			return;
//		}
//		for (int i = 0; i < 3 + (digits[current] == '7' || digits[current] == '9'); i++) {
//			char ch = digits[current];
//			tmp.push_back('a' + 3 * (ch - '2') + i + (ch >= '8'));
//			dfs(current + 1, digits, tmp, result);
//			tmp.pop_back();
//		}
//	}
//public:
//	vector<string> letterCombinations(string digits) {
//		vector<string> result;
//		if (digits.empty()) {
//			return result;
//		}
//		dfs(0, digits, "", result);
//		return result;
//	}
//};
//
//void output(vector<string> phrase){
//	cout << '[';
//	for(auto elem : phrase){
//		cout << elem << ',';
//	}
//	cout << ']' << endl;
//}
//
//int main(){
//	Solution solu;
//	output(solu.letterCombinations("23"));
//	return 0;
//}





#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(string digits, vector<string> &phoneletter, string phrase, vector<string> &result){
		if(digits.empty()) {
			result.push_back(phrase);
			return;
		}
        
		int i=digits.front()-'0'; digits.erase(digits.begin());//��ͷ������Ԫ�� 
        for(auto c : phoneletter[i]){
			dfs(digits, phoneletter, phrase+c, result);
        }
    }

    vector<string> letterCombinations(string digits){		
		if(digits.empty()) return {};
		
		vector<string> phoneletter = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> result;
		dfs(digits, phoneletter, "", result);
		return result;
    }
};

void output(vector<string> phrase){
	for(auto elem : phrase)  cout << elem << ' ';
}

int main(){
	Solution solu;
	output(solu.letterCombinations("23"));
	return 0;
}
