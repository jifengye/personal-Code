/* ��Ŀ��62. ��ͬ·��
 * Ҫ��һ�� m x n ����һ��������λ�����Ͻǣ�ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǡ�
		�ܹ��ж�������ͬ��·����
 * ��Դ��https://leetcode-cn.com/problems/unique-paths/description/
 * ʱ�䣺2018/11/22
 */

/**
	��̬�滮
	ֻ�����»��������ƶ� 
		-> �����ϱ߽����߽�ֻ��һ�ַ����ܵ���
		����1�� ����(0,j)��(i,0)�㷽���� dp[i,j] =  1
		-> Ҫ��������ĳ���㣬ֻ��ͨ���õ���߻��ϱߵĸ��ӳ���
	 	����2������(i,j)�㷽���� dp[i,j] =  dp[i-1,j] + dp[i,j-1]
	Ϊ����������ͳһ��ʽ������ʹ��n+1*m+1���飬�ϡ���߽���0��ʾ������Ϊ��1,1��
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0) return 0;
		
		vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 

		dp[1][1]=1; //������(1,1)��ʾ��� 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
			}
		}
		
		return dp[n][m];
	}
};


int main() {
	Solution solu;
	cout << solu.uniquePaths(3,2);
	return 0;
} 





/*
	��ʵ���������ѧ�еĸ���ͳ��
	һ��Ҫ������ n-1 ���������� m-1 �����ȼ��� (n-1)+(m-1) �������� n-1 ������
	��Ϊ�����C(n-1)(n+m-1) 
	��Ϲ�ʽ C(m,n)=n!/(m!*(n-m)!) = factorial(n)/(factorial(m)*factorial(n-m))
	�����ǣ��׳��������̫���ˣ�long��Ҳ�޷����� 
*/
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	long factorial(long number){ //�õݹ�ʵ�ֽ׳� 
//		return number<=1 ? 1:number*factorial(number-1);
//		cout << number; 
//	}
//	
//	int uniquePaths(int m, int n) {
//		if (m==0 || n==0) return 0;
//		return factorial(n+m-2)/(factorial(m-1)*factorial(n-1));
//	}
//};
//
//
//int main() {
//	Solution solu;
//	cout << solu.uniquePaths(1,100);
//	return 0;
//}

