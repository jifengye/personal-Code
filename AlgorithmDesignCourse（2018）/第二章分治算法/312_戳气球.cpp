/* 题目：312. 戳气球
 * 要求：每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
 		这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
		求所能获得硬币的最大数量。
 * 来源：https://leetcode-cn.com/problems/burst-balloons/description/
 * 时间：2018-11-19
 */
 
/*
	贪心算法 
	选择戳破气球原则： 
		当气球多于两个时，戳破从 (1,size()-2)中最小的气球
		当气球不多于两个时，戳破最小的气球
		但是方法不可行，例如 1,8,2 
	
	
	暴力算法：
		其实本题就是选择戳爆气球的顺序
		通过遍历出所有顺序得到最大值 
	
	
	分治算法
		为了让子体和整体有相同性质问题，我们逆向思考
		从戳爆最后一个气球往前看，这个气球的位置可以把整个气球数组分成两部分。
		需要注意的是本题二分法不在合适了 
		
		XXXXlOOOOiOOOrXXXXXXX   //假设i是子体OOOOiOOO中最后戳爆的 
		 	 OOOOiOOO
	   XXXXl OOOOiOOO rXXXXXXX	//那么戳爆i时应该这样算：l*i*r 
	         OOOO OOO			//那么该子体再分割子体后，就有了...... 
	         
		dp[i][j]表示把第 i 个气球和第 j 个气球之间最大能得到的分值 
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
		nums.push_back(1); 
		int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0)); 
		for (int length=3; length<=n; length++) { //从3个一组，到4个4个一组......到最后n个一组，不断更新dp数组 
			for (int i=0; i+length<=n; i++) {
				int j = i+length-1;
				dp[i][j] = -INT_MAX;
				for (int k=i+1; k<j; k++) {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
				}
			}
		}

        return  dp[0][n-1];
    }
};



int main() {
	Solution solu;
	vector<int> nums = {3,1,5,8};       
	cout<<solu.maxCoins(nums);
	return 0;
} 
