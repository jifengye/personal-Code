/* 89. 格雷编码
 * https://leetcode-cn.com/problems/gray-code/description/
 * 给定一个非负整数 n，代表格雷编码的位数，要求打印其格雷编码序列。格雷编码序列必须以 0 开头。
 * 输入: n = 2
 * 输出: [0,1,3,2]
 * 2018/10/18
 */
 
/* 方法一：递归
	有如下规律：长度 1 的格雷码序列是 0、1	
		把长度 1 的格雷码镜像复制一份，并在所有复制上最高位补一个0，这个序列为 00、01 
		把长度 1 的格雷码镜像复制一份，并在所有复制上最高位补一个1，序列改为倒序，这个序列为 11、10  
	所以长度为 2 的格雷码序列 即 00、01、11、10 
	... ...
	根据这个规律不断迭代 
   n=0   n=1   n=2   n=3 
   0     0     00    000
         1     01    001
               11    011
               10    010
                     110
                     111
                     101
                     100
 */
 
 
/* vector.push_back(a)  尾部加入一个元素
 * 1 << 3   移位运算，比如 1 二进制为 0001，那么 1<<3 就是 1000 
 * (1<<(n-1) | result[i])  含义是result[i]的最高位补一个1 
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		if(n==0){
			return {0};
		}
		auto result = grayCode(n - 1);
		for(int i=result.size()-1; i>=0; i--) {
			result.push_back(1 << (n - 1) | result[i]); //(1<<(n-1)|result[i])含义是result[i]的最高位补一个1 
		}
		return result;
	}
};

void output(vector<int> nums){
	for(auto elem : nums) cout << elem << ' ';
}

int main(){
	Solution solu;
	output(solu.grayCode(3));
	return 0;
}


/* 方法二：递归改用循环
 */ 
//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> grayCode(int n) {
//		vector<int> result({0}); 
//		
//		for(int r=0; r<n; r++){
//			for(int i = result.size() - 1; i >= 0; i--) {
//				result.push_back(1<<r | result[i]);
//			}
//		}
//
//		return result;
//	}
//};
//
//void output(vector<int> nums){
//	cout << '[';
//	for(auto elem : nums){
//		cout << elem << ',';
//	}
//	cout << ']' << endl;
//}
//
//int main(){
//	Solution solu;
//	output(solu.grayCode(3));
//	return 0;
//}
