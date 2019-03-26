/* ��Ŀ��63. ��ͬ·�� II
 * Ҫ��һ�� m x n ����һ��������λ�����Ͻǣ�ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǡ�
		���ڿ������������ϰ��
		�ܹ��ж�������ͬ��·����
 * ��Դ��https://leetcode-cn.com/problems/unique-paths-ii/description/
 * ʱ�䣺2018/11/22
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
		
		if( obstacleGrid[0][0]==0 ) dp[1][1]=1; //������(1,1)��ʾ��� 
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
