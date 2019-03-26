//动态规划
//没有0号台阶，是起点，dp[0]不是。dp[0]值为 1 
//到 1 号台阶方法有 dp[1] = 1 = 2^0   
//到 2 号台阶方法有 dp[2] = dp[1] + dp[0] = 2 = 2^1
//到 3 号台阶方法有 dp[3] = dp[2] + dp[1] + dp[0] = 4 = 2^2
//到 4 号台阶方法有 dp[4] = dp[3] + dp[2] + dp[1] + dp[0] = 8 = 2^3
//到 5 号台阶方法有 dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + dp[0] = 16 = 2^4
//到 6 号台阶方法有 dp[6] = dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + dp[0] = 32 = 2^5
// ....
// 当n>=1时有 dp[n]=2^(n-1)
#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        int f0=1; 
        return f0<<(number-1); //2的幂次可用移位操作 
    }
};

int main(){
	class Solution solu;
	cout<<solu.jumpFloorII(4);
	return 0;
}
