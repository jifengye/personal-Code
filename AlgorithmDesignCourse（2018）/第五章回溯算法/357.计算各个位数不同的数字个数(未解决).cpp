/* 357. 计算各个位数不同的数字个数
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 * 计算[0，10^n)范围中有多少个数字，满足各位数都不同。
 * 输入: 2
 * 输出: 91 
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 * 2018/10/20
 */
 
/*
思路
	本题是概率统计中的排列问题
	有点类似于 从0~9这 10 个数中挑出 n 个组成一个n位数，有几种排列方案， 但又不完全一样，  
	n=0，即[0,1)：1个， 
	n=1，即[0,10)：10个，1 + 9 = 10 
	n=2，即[0,100)：91个， 1 + 9 + 9*9 = 91 
	n=3，即[0,1000)：739个，1 + 9 + 9*9 + 9*9*8 =  739
	n=4，即[0,10000)：5275个，1 + 9 + 9*9 + 9*9*8 + 9*9*8*7 = 5275 
	... ...
	利用 
		f(1)=9
		f(2)=9*9=f(1)*9
		f(3)=9*9*8=f(2)*8 
*/
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int result = 1;
		if(n>=1) result += 9;
		int f = 9;//f(1)=9  f(2)=9*9   f(3)=9*9*8
        for(int i = 2; i <= n; i++){
            f *= 11-i;
            result += f;
        }
		return result;
	}
};

int main(){
	Solution solu;
	cout << solu.countNumbersWithUniqueDigits(9);
	return 0;
}

