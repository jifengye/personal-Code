/* 题目：338. 比特位计数
 * 要求：给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 * 来源：https://leetcode-cn.com/problems/counting-bits/description/
 * 时间：2018-11-23
 */

/*
	暴力 ，O(n*sizeof(integer)) 
	
	但是，需找规律 用 O(n)解决 
	0  0000  0

	1  0001  1  = dp[0]+1 
	
	2  0010  1  = dp[0]+1
	3  0011  2  = dp[1]+1
	
	4  0100  1  = dp[0]+1
	5  0101  2  = dp[1]+1
	6  0110  2  = dp[2]+1
	7  0111  3  = dp[3]+1

	8  1000  1  = dp[0]+1
	9  1001  2  = dp[1]+1
   10  1010  2  = dp[2]+1
   11  1011  3  = dp[3]+1
   12  1100  2  = dp[4]+1
   13  1101  3  = dp[5]+1
   14  1110  3  = dp[6]+1
   15  1111  4  = dp[7]+1
   
*/
//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> countBits(int num) {
//    	vector<int> dp;
//		dp.push_back(0);
//		if(num==0) return dp;
//    	
//    	while(1) {
//    		int n = dp.size();
//    		for (int j=0; j<n; j++) {
//    			dp.push_back( dp[j]+1 );
//    			if(--num==0) return dp;
//			}
//		}
//        
//    }
//};
//
//void output(vector<int> nums) {
//	for (auto e:nums) {
//		cout << e << " ";
//	}
//} 
//
//int main() {
//	Solution solu;
//	output(solu.countBits(5));
//	return 0;
//} 



/*
	另外方法
		直接从二进制的特点出发 
		(-i) 是数字i 二进制的 补码，即对i原码取反加1。例如 i=6=110，(-i) = 010
		(i&-i)  数值为i的二进制数表示下最低位的１的权值。例如 i=6=110，(i&-i)=10=2 
		i-(i&-i) 是 数字 i 去掉其二进制表示下最低位的1后的数字
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result(num + 1, 0);
		for (int i = 1; i <= num; i++) {
			//cout << i << ' '<< (i&-i) << ' '<< (i|-i) <<endl;
			result[i] = result[i-(i&-i)] + 1;
		}
		return result;
	}
};


void output(vector<int> nums) {
	for (auto e:nums) {
		cout << e << " ";
	}
} 

int main() {
	Solution solu;
	output(solu.countBits(15));
	return 0;
}   
