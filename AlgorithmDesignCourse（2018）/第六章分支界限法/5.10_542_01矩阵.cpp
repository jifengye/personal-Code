/* 题目：542. 01 矩阵
 * 要求：给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
		两个相邻元素间的距离为 1 。
 * 来源：https://leetcode-cn.com/problems/01-matrix/description/
 * 时间：2018-11-13
 */
 

/**
 *	思路：
 *		找到所有的 0 ，每个 0 都进行 dfs
 *		更新该 0 到每个 1 的距离
 *		直到周围没有 1 或者 周围1到最近的0的距离 都不大于到该 0 距离时，停止dfs
 *
 *	做法一：
 *		使用深度优先 - 递归
 *		结果是超时了 
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
//	void dfs(vector<vector<int>> &result, pair<int, int> tmp) {
//		
//		for(auto &v:dir) {
//			int x = tmp.first + v.first;
//			int y = tmp.second + v.second;
//			if (x<0 || n<=x || y<0 || m<=y) continue;
//			
//			if (result[tmp.first][tmp.second]+1 < result[x][y]) {
//				result[x][y] = result[tmp.first][tmp.second]+1;
//				dfs(result, {x,y});
//			}
//		}
//	
//	}
//	
//public:
//    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//		if ( matrix.empty() ) return matrix;
//		
//		n = matrix.size();
//		m = matrix[0].size();
//		vector<vector<int>> result(n, vector<int>(m, INT_MAX )); 
//		
//		for (int i=0; i<n; i++)
//			for (int j=0; j<m; j++)
//				if (matrix[i][j]==0) {
//					result[i][j]=0;
//					dfs(result, {i,j});
//				}
//
//		return result;
//    }
//};
//
//
//void output_2V(vector<vector<int>> matrix){
//	for (auto line:matrix){
//		for (auto e:line) cout<<e;
//		cout<<endl;		
//	}
//}
//
//int main() {
//	Solution solu;
//	
//	vector<vector<int>> matrix({{0,0,0},{0,1,0},{1,1,1}});
//	
//	output_2V(solu.updateMatrix(matrix));
//	return 0;
//}



/**
 *	做法一超时了
 *	思路是没错的，但是不应用深度优先，应用广度优先
 *	因为使用深度优先的话
 *		下一个 0 的dfs 可能会覆盖前一个 0 的dfs
 *		这是因为前一个确定的距离不一定是到最近的0的距离	 
 *		这样就造成时间上的浪费
 *	
 *	但是如果用广度优先的话
 *		找到所有与该0距离为1的点，标记，结束
 *		再找与下一个0距离为1的点，标记，结束
 *		。。。
 *		从距离为1的点出发，找到下一个距离0为2的点。。。
 *		所以，一旦点的距离被确定就一定是到最近的0的距离	
 *
 *	深度优先实现可以用：递归
 *	广度优先实现可以用：队列	
 * 	
 */
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if ( matrix.empty() ) return {};
		
		vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
		int n=matrix.size(), m=matrix[0].size();
		vector<vector<int>> result(n, vector<int>(m,0) );
		
		queue<pair<int, int>> q;
		for(int i=0; i<n; i++)  for(int j=0; j<m; j++){
			if(matrix[i][j]==0) q.push({i,j}); //纳入所有0的位置作为递归起点 
			else  result[i][j]=-1; //标记-1的是距离还未确定的		
		}

		while( !q.empty() ) { //广度优先 
			auto tmp = q.front(); q.pop();

			for(auto v:dir) {
				int x = tmp.first + v.first;
				int y = tmp.second + v.second;
				if (x<0 || n<=x || y<0 || m<=y) continue;
			
				if (result[x][y]==-1) {
					result[x][y] = result[tmp.first][tmp.second]+1;
					q.push({x,y});
				}
			}
		}
		return result;
	}

};


void output_2V(vector<vector<int>> matrix){
	for (auto line:matrix){
		for (auto e:line) cout<<e;
		cout<<endl;		
	}
}

int main() {
	Solution solu;
	vector<vector<int>> matrix({{0,0,0},{0,1,0},{1,1,1}});
	output_2V(solu.updateMatrix(matrix));
	return 0;
} 
