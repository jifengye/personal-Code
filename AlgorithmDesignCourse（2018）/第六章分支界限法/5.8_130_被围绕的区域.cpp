/* 题目：130. 被围绕的区域
 * 要求：给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
		被围绕的区间不会存在于边界上
		任何边界上的 O 都不会被填充为 X
		任何不在边界上，或不与边界上的 O 相连的 O 最终都会被填充为 X
 * 来源：https://leetcode-cn.com/problems/surrounded-regions/description/
 * 时间：2018-11-12
 */
 
/**
 *	思路：
 *		遍历整个数组，遇到O字符时
 *		通过递归找到与这个O相连的这块区域，
 *		判断这块区域是否是被围绕的
 *	----------
 *		逆向思考，从边界的点出发
 *		直接找四边的O字符，直接改为N字符作为标记
 *		递归找到相连的O字符，也直接改为N字符
 *		如此
 *		当四边的O字符都这样处理完后，剩下的O字符都是被围绕的了
 *		 最后遍历整个数组，O字符改为X，不要忘记把N字符改回O 
 *		 
 *
 */
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& board, vector<pair<int, int>> &dir, pair<int,int> p) {
		board[p.first][p.second] = 'N';

		for (auto e:dir) {
			int x = p.first + e.first;
			int y = p.second + e.second;
			if (x<0 || board.size()<=x || y<0 || board[0].size()<=y) continue;
			
			if (board[x][y] == 'O')	 dfs(board, dir, make_pair(x,y));
		}
	}
    void solve(vector<vector<char>>& board) {
        if ( board.empty() ) return;
        
		vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
		int n = board.size(), m = board[0].size();
		for (int j = 0; j < m; j++) {
			if(board[0][j]=='O')    dfs(board, dir, make_pair(0,j));
			if(board[n-1][j]=='O')  dfs(board, dir, make_pair(n-1,j));
		}
		for (int i = 0; i < n; i++) {
			if(board[i][0]=='O')    dfs(board, dir, make_pair(i,0));
			if(board[i][m-1]=='O')  dfs(board, dir, make_pair(i,m-1));
		}
		
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] = (board[i][j] == 'N' ? 'O' : 'X');
	}
};

void output_2V(vector<vector<char> > matrix){
	for(auto nums:matrix){
		for(auto e:nums) cout<<e;
		cout<<endl;
	}
}

int main(){
	Solution solu;
	vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	solu.solve(board);
	output_2V(board);
	return 0;
}
