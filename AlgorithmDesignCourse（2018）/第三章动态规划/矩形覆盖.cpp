//��̬�滮
//�� 2*1 С������ 2*n����η����� �� f[0]��ֵΪ 1 
//f[1]=1 
//f[2]=f[1]+f[0]=2
//f[3]=f[2]+f[1]=3
//f[4]=f[3]+f[2]=5
//�����������̵�һ�飬�������������
//	���һ�������̣�ʣ�¿ռ�2*(n-1)��������Ϊf[n-1]��
//	������������̣�����̶�Ҫ�ٺ�����һ�飬ʣ�¿ռ� 2*(n-2)��������Ϊf[n-2]��
//	���Ե� n>=2ʱ��f[n]=f[n-1]+f[n-2] 

#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if(number<=0)  return 0;
		
		int f0=1,f1=1,f;
        while(number--){
			f=f0+f1;
			f0=f1;
			f1=f;
		}
		return f0; 
    }
};

int main(){
	Solution solu;
	cout << solu.rectCover(3);
	return 0;
} 
