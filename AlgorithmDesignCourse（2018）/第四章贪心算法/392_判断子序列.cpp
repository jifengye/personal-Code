/* ��Ŀ��392.�ж�������
 * Ҫ�󣺸����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
		 s �� t �н�����Ӣ��Сд��ĸ��
		�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ�����
		�����磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
 * ��Դ��https://leetcode-cn.com/problems/is-subsequence/description/
 * ʱ�䣺2018-11-05
 */
 

/* ֱ�ӱ����� */ 
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
