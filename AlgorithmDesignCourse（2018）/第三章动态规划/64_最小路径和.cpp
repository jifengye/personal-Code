/* 题目：64. 最小路径和
 * 要求：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 来源：https://leetcode-cn.com/problems/minimum-path-sum/description/
 * 时间：2018-11-23
 */

/*
	思路
		结合题目 不同路径 不同路径II
		从左上角到右下角遍历
		计算公式：grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
		不断更新每个方格数字和
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if( grid.empty() ) return 0;

		int n = grid.size();
		int m = grid[0].size();
		
		for(int i=1; i<n; i++)	grid[i][0] += grid[i-1][0];
		for(int j=1; j<m; j++)	grid[0][j] += grid[0][j-1];
		
		for(int i=1; i<n; i++) {
			for(int j=1; j<m; j++) {
				grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
			}
		}
		return grid[n-1][m-1];
	}
};


int main() {
	Solution solu;
	vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
	cout<<solu.minPathSum(grid);
	return 0;
} 
