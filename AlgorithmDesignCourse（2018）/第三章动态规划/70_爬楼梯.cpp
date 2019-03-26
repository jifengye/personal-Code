/* ��Ŀ��70. ��¥��
 * Ҫ���� n ��¥�ݣ�ÿ��ֻ���� 1 �� 2 ��̨�ס��ж����ֲ�ͬ�ķ�����������¥���أ�
 * ��Դ��https://leetcode-cn.com/problems/climbing-stairs/description/
 * ʱ�䣺2018/9/27
 */
 
 
/**
	��̬�滮 O(n)
		ʵ�ʾ���쳲��������� 
		
		ע��û��0��̨�ף�����㣬dp[0]���ǡ�dp[0]ֵΪ 1 
		�� 1 ��̨�׷����� dp[1] = 1   
		�� 2 ��̨�׷����� dp[2] = dp[1] + dp[0]  // ��1��̨����ȥ��������ȥ
		�� 3 ��̨�׷����� dp[2] = dp[2] + dp[1]  // ��2��̨����ȥ���1��̨����ȥ
		... ...
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        if(n<=0)  return 0;
		
		int f0=1,f1=1,f;
        while(n--){
			f=f0+f1;
			f0=f1;
			f1=f;
		}
		return f0; 
	}
};

int main(){
	Solution solu;
	cout << solu.climbStairs(3);
	return 0;
}

