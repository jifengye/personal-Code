/* ��Ŀ��542. 01 ����
 * Ҫ�󣺸���һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ��롣
		��������Ԫ�ؼ�ľ���Ϊ 1 ��
 * ��Դ��https://leetcode-cn.com/problems/01-matrix/description/
 * ʱ�䣺2018-11-13
 */
 

/**
 *	˼·��
 *		�ҵ����е� 0 ��ÿ�� 0 ������ dfs
 *		���¸� 0 ��ÿ�� 1 �ľ���
 *		ֱ����Χû�� 1 ���� ��Χ1�������0�ľ��� �������ڵ��� 0 ����ʱ��ֹͣdfs
 *
 *	����һ��
 *		ʹ��������� - �ݹ�
 *		����ǳ�ʱ�� 
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
 *	����һ��ʱ��
 *	˼·��û��ģ����ǲ�Ӧ��������ȣ�Ӧ�ù������
 *	��Ϊʹ��������ȵĻ�
 *		��һ�� 0 ��dfs ���ܻḲ��ǰһ�� 0 ��dfs
 *		������Ϊǰһ��ȷ���ľ��벻һ���ǵ������0�ľ���	 
 *		���������ʱ���ϵ��˷�
 *	
 *	��������ù�����ȵĻ�
 *		�ҵ��������0����Ϊ1�ĵ㣬��ǣ�����
 *		��������һ��0����Ϊ1�ĵ㣬��ǣ�����
 *		������
 *		�Ӿ���Ϊ1�ĵ�������ҵ���һ������0Ϊ2�ĵ㡣����
 *		���ԣ�һ����ľ��뱻ȷ����һ���ǵ������0�ľ���	
 *
 *	�������ʵ�ֿ����ã��ݹ�
 *	�������ʵ�ֿ����ã�����	
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
			if(matrix[i][j]==0) q.push({i,j}); //��������0��λ����Ϊ�ݹ���� 
			else  result[i][j]=-1; //���-1���Ǿ��뻹δȷ����		
		}

		while( !q.empty() ) { //������� 
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
