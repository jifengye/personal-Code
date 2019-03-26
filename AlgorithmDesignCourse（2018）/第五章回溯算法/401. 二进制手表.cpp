/* 401. 二进制手表
 * https://leetcode-cn.com/problems/binary-watch/description/
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * 2018/10/11
 */


/* 粗暴遍历一个时钟（12小时，每小时60分钟） 12 * 60 = 7200次 
	亮点是：int 转 string 的方法 : string s = to_string(i)
			计算数转为二进制中会有几个1 : __builtin_popcount
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

