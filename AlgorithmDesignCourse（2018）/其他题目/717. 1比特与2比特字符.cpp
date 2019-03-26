/*
717. 1比特与2比特字符
对一串由0结束的字符串解码，已知编码规则是 a=0，b=10，c=11，问最后一个字符0是否是表示a。
https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/
2018-11-29
*/


/*
暴力
由哈夫曼编码知识可知这种编码是唯一的(这就是哈夫曼编码中的变长码) 
if 是1：删除两个字符
else 是0：删除一个字符
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	int n = bits.size();
    	int i = 0;
    	
    	//只计到倒数第二个字符处
		//如果倒数第二个字符和最后一个字符0是一体的，最后i会加2等于n
		//如果不是一体的，i就停留在最后一个字符位置上，等于n-1 
        while(i<n-1) {
        	if(bits[i]==1) i += 2;  //是1跳两个
			else i++; //是0跳一个 
		}
		return i==n-1;
    }
};

int main() {
	Solution solu;
	vector<int> bits = {1, 0, 1, 0};
	cout << boolalpha << solu.isOneBitCharacter(bits);
	return 0; 
} 
