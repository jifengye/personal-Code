/* 93. 复原IP地址
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式(分四段，0~255 )
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 2018/10/19
 */

/*
思路：
	用递归遍历例举所有组合，满足条件的组合加入
	但其实没有遍历所有，算法中含有剪枝
	就是说不是分割完四段后再判断是否符合Ip地址格式
	而是每分一段（part），都要判断该段是否符合格式  if(ok(part))
	符合格式的才拿来再往下组合
	直到分到第四段，。。。 
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool ok(string part) { //判断是否能作为ip地址子串 0~255
		if(part.empty() || part.size()>3 || (part.size()>1&&part[0]=='0')) return false;
		return stoi(part) <= 255;
	}
	void dfs(int step, string s, string temp, vector<string> &result) {
		if(step == 4) {
			if(ok(s)) result.push_back(temp + s);
			return;
		}
		for(int len=1; len<=min(3, (int)s.size()); len++) {
			string part = s.substr(0, len);
			if(ok(part)) dfs(step+1, s.substr(len), temp+part+".", result);
		}
	}
	vector<string> restoreIpAddresses(string s){
		vector<string> result;
		dfs(1, s, "", result);
		return result;
	}
};

void output(vector<string> text){
	for(auto line : text)  cout << line << endl;
}

int main(){
	Solution solu;
	output(solu.restoreIpAddresses("25525511135"));
	return 0;
}
