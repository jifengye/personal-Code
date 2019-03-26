/* ��Ŀ��417. ̫ƽ�������ˮ������
 * Ҫ�󣺸���һ�� m x n �ķǸ�������������ʾһƬ��½�ϸ�����Ԫ��ĸ߶ȡ���̫ƽ�󡱴��ڴ�½����߽���ϱ߽磬���������󡱴��ڴ�½���ұ߽���±߽硣
		�涨ˮ��ֻ�ܰ����ϡ��¡������ĸ�������������ֻ�ܴӸߵ��ͻ�����ͬ�ȸ߶���������
		���ҳ���Щˮ���ȿ�����������̫ƽ�󡱣������������������󡱵�½�ص�Ԫ�����ꡣ
 * ��Դ��https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 * ʱ�䣺2018-11-13
 */
 
/**
 *	˼·��
 *		һ�ֱȽ���Ȼ��˼·�����ζ�ÿ������� bfs �����Ƿ���ܵ���̫ƽ�����ܵ��������
 *		����˼·�ᵼ�����ܶ��ظ��Ĳ������³�ʱ
 *		
 *		ת��˼·����Ŀ�����ȥѰ��Դ�����Դ���̫ƽ��ʹ�����ֱ�����ڵĵ㣨Ҳ���Ǿ����Ե�ϵĵ㣩�������� bfs ȥ�������������еĵ�
 *		�������ĵ�϶����ܹ�����ĳ������ĵ�
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
 *	�������һ����ֻ�ǰ� visit �� bool �͸�Ϊ int ��
 *	�����ƽ̨�ϴ��������ٶȼ�������һ�� 
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
