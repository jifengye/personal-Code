/* ��Ŀ��130. ��Χ�Ƶ�����
 * Ҫ�󣺸���һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O�����ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣
		��Χ�Ƶ����䲻������ڱ߽���
		�κα߽��ϵ� O �����ᱻ���Ϊ X
		�κβ��ڱ߽��ϣ�����߽��ϵ� O ������ O ���ն��ᱻ���Ϊ X
 * ��Դ��https://leetcode-cn.com/problems/surrounded-regions/description/
 * ʱ�䣺2018-11-12
 */
 
/**
 *	˼·��
 *		�����������飬����O�ַ�ʱ
 *		ͨ���ݹ��ҵ������O�������������
 *		�ж���������Ƿ��Ǳ�Χ�Ƶ�
 *	----------
 *		����˼�����ӱ߽�ĵ����
 *		ֱ�����ıߵ�O�ַ���ֱ�Ӹ�ΪN�ַ���Ϊ���
 *		�ݹ��ҵ�������O�ַ���Ҳֱ�Ӹ�ΪN�ַ�
 *		���
 *		���ıߵ�O�ַ��������������ʣ�µ�O�ַ����Ǳ�Χ�Ƶ���
 *		 �������������飬O�ַ���ΪX����Ҫ���ǰ�N�ַ��Ļ�O 
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
