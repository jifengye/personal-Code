/* 93. ��ԭIP��ַ
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 * ����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ(���ĶΣ�0~255 )
 * ����: "25525511135"
 * ���: ["255.255.11.135", "255.255.111.35"]
 * 2018/10/19
 */

/*
˼·��
	�õݹ��������������ϣ�������������ϼ���
	����ʵû�б������У��㷨�к��м�֦
	����˵���Ƿָ����Ķκ����ж��Ƿ����Ip��ַ��ʽ
	����ÿ��һ�Σ�part������Ҫ�жϸö��Ƿ���ϸ�ʽ  if(ok(part))
	���ϸ�ʽ�Ĳ��������������
	ֱ���ֵ����ĶΣ������� 
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool ok(string part) { //�ж��Ƿ�����Ϊip��ַ�Ӵ� 0~255
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
