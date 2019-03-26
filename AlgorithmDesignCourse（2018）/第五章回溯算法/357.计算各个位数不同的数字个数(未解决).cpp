/* 357. �������λ����ͬ�����ָ���
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 * ����[0��10^n)��Χ���ж��ٸ����֣������λ������ͬ��
 * ����: 2
 * ���: 91 
 * ����: ��ӦΪ��ȥ 11,22,33,44,55,66,77,88,99 �⣬�� [0,100) �����ڵ��������֡�
 * 2018/10/20
 */
 
/*
˼·
	�����Ǹ���ͳ���е���������
	�е������� ��0~9�� 10 ���������� n �����һ��nλ�����м������з����� ���ֲ���ȫһ����  
	n=0����[0,1)��1���� 
	n=1����[0,10)��10����1 + 9 = 10 
	n=2����[0,100)��91���� 1 + 9 + 9*9 = 91 
	n=3����[0,1000)��739����1 + 9 + 9*9 + 9*9*8 =  739
	n=4����[0,10000)��5275����1 + 9 + 9*9 + 9*9*8 + 9*9*8*7 = 5275 
	... ...
	���� 
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

