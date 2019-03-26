/* ��Ŀ��338. ����λ����
 * Ҫ�󣺸���һ���Ǹ����� num������ 0 �� i �� num ��Χ�е�ÿ������ i ����������������е� 1 ����Ŀ����������Ϊ���鷵�ء�
 * ��Դ��https://leetcode-cn.com/problems/counting-bits/description/
 * ʱ�䣺2018-11-23
 */

/*
	���� ��O(n*sizeof(integer)) 
	
	���ǣ����ҹ��� �� O(n)��� 
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
	���ⷽ��
		ֱ�ӴӶ����Ƶ��ص���� 
		(-i) ������i �����Ƶ� ���룬����iԭ��ȡ����1������ i=6=110��(-i) = 010
		(i&-i)  ��ֵΪi�Ķ���������ʾ�����λ�ģ���Ȩֵ������ i=6=110��(i&-i)=10=2 
		i-(i&-i) �� ���� i ȥ��������Ʊ�ʾ�����λ��1�������
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
