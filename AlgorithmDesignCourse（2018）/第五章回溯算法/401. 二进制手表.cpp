/* 401. �������ֱ�
 * https://leetcode-cn.com/problems/binary-watch/description/
 * ����һ���Ǹ����� n ����ǰ LED ���ŵ��������������п��ܵ�ʱ�䡣
 * ����: n = 1
 * ����: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * 2018/10/11
 */


/* �ֱ�����һ��ʱ�ӣ�12Сʱ��ÿСʱ60���ӣ� 12 * 60 = 7200�� 
	�����ǣ�int ת string �ķ��� : string s = to_string(i)
			������תΪ�������л��м���1 : __builtin_popcount
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	string gao(int h, int m) {
        string result;
        result += to_string(h) + ":";
        if(m<10) result += "0";
        result += to_string(m);
        return result;
	}
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int h = 0; h < 12; h++) {
			for (int m = 0; m < 60; m++)
				if (__builtin_popcount(h) + __builtin_popcount(m) == num)
					result.push_back(gao(h, m));
		}
		return result;
	}
};

void output(vector<string> str){
	for(int i=0; i<str.size(); i++){
		cout<<str[i]<<endl;
	}
}

int main(){
	int n = 2;
	Solution solu;
	output(solu.readBinaryWatch(1));
	return 0;
}

