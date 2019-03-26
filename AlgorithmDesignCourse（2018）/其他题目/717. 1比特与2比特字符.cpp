/*
717. 1������2�����ַ�
��һ����0�������ַ������룬��֪��������� a=0��b=10��c=11�������һ���ַ�0�Ƿ��Ǳ�ʾa��
https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/
2018-11-29
*/


/*
����
�ɹ���������֪ʶ��֪���ֱ�����Ψһ��(����ǹ����������еı䳤��) 
if ��1��ɾ�������ַ�
else ��0��ɾ��һ���ַ�
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	int n = bits.size();
    	int i = 0;
    	
    	//ֻ�Ƶ������ڶ����ַ���
		//��������ڶ����ַ������һ���ַ�0��һ��ģ����i���2����n
		//�������һ��ģ�i��ͣ�������һ���ַ�λ���ϣ�����n-1 
        while(i<n-1) {
        	if(bits[i]==1) i += 2;  //��1������
			else i++; //��0��һ�� 
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
