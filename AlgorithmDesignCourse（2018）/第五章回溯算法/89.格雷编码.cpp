/* 89. ���ױ���
 * https://leetcode-cn.com/problems/gray-code/description/
 * ����һ���Ǹ����� n��������ױ����λ����Ҫ���ӡ����ױ������С����ױ������б����� 0 ��ͷ��
 * ����: n = 2
 * ���: [0,1,3,2]
 * 2018/10/18
 */
 
/* ����һ���ݹ�
	�����¹��ɣ����� 1 �ĸ����������� 0��1	
		�ѳ��� 1 �ĸ����뾵����һ�ݣ��������и��������λ��һ��0���������Ϊ 00��01 
		�ѳ��� 1 �ĸ����뾵����һ�ݣ��������и��������λ��һ��1�����и�Ϊ�����������Ϊ 11��10  
	���Գ���Ϊ 2 �ĸ��������� �� 00��01��11��10 
	... ...
	����������ɲ��ϵ��� 
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
 
 
/* vector.push_back(a)  β������һ��Ԫ��
 * 1 << 3   ��λ���㣬���� 1 ������Ϊ 0001����ô 1<<3 ���� 1000 
 * (1<<(n-1) | result[i])  ������result[i]�����λ��һ��1 
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
			result.push_back(1 << (n - 1) | result[i]); //(1<<(n-1)|result[i])������result[i]�����λ��һ��1 
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


/* ���������ݹ����ѭ��
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
