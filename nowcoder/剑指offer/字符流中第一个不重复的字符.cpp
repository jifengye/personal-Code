/*
字符流中第一个不重复的字符

请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
 
/*
使用哈希
所有的char字符按照ASCII码编码总共128个，其编码值转为十进制就是0~127 
遍历插入的字符（按照插入的顺序，可方便的得到第一个），hash表中个数为1的输出，否则返回#
*/
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    string str;
    char hash[128] = {0};
    void Insert(char ch) {
        str += ch;
        hash[ch]++;
    }
    
    
    char FirstAppearingOnce() {
        for(char ch : str)
            if(hash[ch] == 1) return ch;
        return '#';
    }
};

int main(){
	class Solution solu;
	string str="898";
	for(int i=0; i<str.length(); ++i){
		solu.Insert(str[i]);
	} 
	printf("%c\n",solu.FirstAppearingOnce());
	return 0;
}

