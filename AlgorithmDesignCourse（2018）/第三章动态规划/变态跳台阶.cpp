//��̬�滮
//û��0��̨�ף�����㣬dp[0]���ǡ�dp[0]ֵΪ 1 
//�� 1 ��̨�׷����� dp[1] = 1 = 2^0   
//�� 2 ��̨�׷����� dp[2] = dp[1] + dp[0] = 2 = 2^1
//�� 3 ��̨�׷����� dp[3] = dp[2] + dp[1] + dp[0] = 4 = 2^2
//�� 4 ��̨�׷����� dp[4] = dp[3] + dp[2] + dp[1] + dp[0] = 8 = 2^3
//�� 5 ��̨�׷����� dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + dp[0] = 16 = 2^4
//�� 6 ��̨�׷����� dp[6] = dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + dp[0] = 32 = 2^5
// ....
// ��n>=1ʱ�� dp[n]=2^(n-1)
#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        int f0=1; 
        return f0<<(number-1); //2���ݴο�����λ���� 
    }
};

int main(){
	class Solution solu;
	cout<<solu.jumpFloorII(4);
	return 0;
}
