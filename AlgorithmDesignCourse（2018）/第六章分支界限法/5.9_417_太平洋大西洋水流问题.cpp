/* 题目：417. 太平洋大西洋水流问题
 * 要求：给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
		规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
		请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 * 来源：https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 * 时间：2018-11-13
 */
 
/**
 *	思路：
 *		一种比较自然的思路是依次对每个点进行 bfs 看其是否既能到达太平洋又能到达大西洋
 *		这种思路会导致做很多重复的操作以致超时
 *		
 *		转换思路，从目标出发去寻找源，可以从与太平洋和大西洋直接相邻的点（也就是矩阵边缘上的点）出发进行 bfs 去遍历矩阵中所有的点
 *		遍历到的点肯定是能够到达某个海洋的点
 */
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:	
	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
	int n , m;

	void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visit, pair<int, int> tmp) {
		if(visit[tmp.first][tmp.second]==true) return;
		visit[tmp.first][tmp.second] = true; 
		
		for(auto &v:dir) {
			int x = tmp.first + v.first;
			int y = tmp.second + v.second;
			if (x<0 || n<=x || y<0 || m<=y) continue;
			
			if (visit[x][y]==false && matrix[x][y]>=matrix[tmp.first][tmp.second]) 
				bfs(matrix, visit, make_pair(x,y));
		}
	}    
	
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> result;
		if ( matrix.empty() ) return result;
		
		n = matrix.size();
		m = matrix[0].size();
		vector<vector<bool>> pVisit(n, vector<bool>(m, false)); // Pacific
		vector<vector<bool>> aVisit(n, vector<bool>(m, false)); // Atlantic	
		for (int j = 0; j < m; j++) {
			bfs(matrix, pVisit, {0,j} );
			bfs(matrix, aVisit, {n-1,j} );
		}
			
		for (int i = 0; i < n; i++) {
			bfs(matrix, pVisit, make_pair(i,0));
			bfs(matrix, aVisit, {i,m-1});
		}
			
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (pVisit[i][j] && aVisit[i][j])
					result.push_back({i, j});
		return result;
	}
};

void output_pair(vector<pair<int, int>> matrix){
	for(auto e:matrix)
		cout<<e.first<<e.second<<endl;
}

int main() {
	Solution solu;
	vector<vector<int>> matrix({{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}});
	output_pair(solu.pacificAtlantic(matrix));
	return 0;
}









/**
 *	和上面的一样，只是把 visit 的 bool 型改为 int 型
 *	结果在平台上代码运行速度几乎快了一倍 
 */
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//private:
//	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//	int n , m;
//	
//	void bfs(vector<vector<int>>& matrix, vector<vector<int>>& visit, pair<int, int> tmp) {
//		if(visit[tmp.first][tmp.second]==1) return;
//		visit[tmp.first][tmp.second] = 1; 
//		
//		for(auto &v:dir) {
//			int x = tmp.first + v.first;
//			int y = tmp.second + v.second;
//			if (x<0 || n<=x || y<0 || m<=y) continue;
//			
//			if (visit[x][y]==0 && matrix[x][y]>=matrix[tmp.first][tmp.second]) 
//				bfs(matrix, visit, make_pair(x,y));
//		}
//	}    
//
//
//public:	
//	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
//		vector<pair<int, int>> result;
//		if ( matrix.empty() ) return result;
//		
//		n = matrix.size();
//		m = matrix[0].size();
//		vector<vector<int>> pVisit(n, vector<int>(m, 0)); // Pacific
//		vector<vector<int>> aVisit(n, vector<int>(m, 0)); // Atlantic	
//		for (int j = 0; j < m; j++) {
//			bfs(matrix, pVisit, {0,j} );
//			bfs(matrix, aVisit, {n-1,j} );
//		}
//			
//		for (int i = 0; i < n; i++) {
//			bfs(matrix, pVisit, make_pair(i,0));
//			bfs(matrix, aVisit, {i,m-1});
//		}
//			
//			
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				if (pVisit[i][j] && aVisit[i][j])
//					result.push_back({i, j});
//		return result;
//	}
//};
//
//
//void output_pair(vector<pair<int, int>> matrix){
//	for(auto e:matrix)
//		cout<<e.first<<e.second<<endl;
//}
//
//int main() {
//	Solution solu;
//	
//	vector<vector<int>> matrix({{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}});
//	
//	output_pair(solu.pacificAtlantic(matrix));
//	return 0;
//}
