/* ��Ŀ��64. ��С·����
 * Ҫ�󣺸���һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
 * ��Դ��https://leetcode-cn.com/problems/minimum-path-sum/description/
 * ʱ�䣺2018-11-23
 */

/*
	˼·
		�����Ŀ ��ͬ·�� ��ͬ·��II
		�����Ͻǵ����½Ǳ���
		���㹫ʽ��grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
		���ϸ���ÿ���������ֺ�
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
