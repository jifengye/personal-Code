/* 题目：63. 不同路径 II
 * 要求：一个 m x n 网格，一个机器人位于左上角，每次只能向下或者向右移动一步，机器人试图达到网格的右下角。
		现在考虑网格中有障碍物。
		总共有多少条不同的路径？
 * 来源：https://leetcode-cn.com/problems/unique-paths-ii/description/
 * 时间：2018/11/22
 */
 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if( obstacleGrid.empty() ) return 0;
		
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		
		if( obstacleGrid[0][0]==0 ) dp[1][1]=1; //在这里(1,1)表示起点 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(obstacleGrid[i-1][j-1]==0) {
					dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
				}
			}
		}
		
		return dp[n][m];
	}
};


int main() {
	Solution solu;
	vector<vector<int>> obstacleGrid = {{0,1,0},{0,1,0},{0,0,0}};
	cout << solu.uniquePathsWithObstacles(obstacleGrid);
	return 0;
} 
