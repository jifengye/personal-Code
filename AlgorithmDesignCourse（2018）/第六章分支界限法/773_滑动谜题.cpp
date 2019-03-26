/* ��Ŀ��773. ��������
 * Ҫ����һ�� 2 x 3 �İ��ϣ�board���� 5 ��ש�ߣ������� 1~5 ����ʾ, �Լ�һ���ȱ�� 0 ����ʾ.
		 0 ��һ�����ڵ����ֽ��н���.���յ��� board �Ľ���� [[1,2,3],[4,5,0]] �հ屻�⿪��
		����һ���հ�ĳ�ʼ״̬���������ٿ���ͨ�����ٴ��ƶ��⿪�հ壬������ܽ⿪�հ壬�򷵻� -1 ��
 * ��Դ��https://leetcode-cn.com/problems/sliding-puzzle/description/
 * ʱ�䣺2018-11-15
 */
 
/**
 *	˼·��
 *		ÿ��״̬�������������ĸ���������״̬���� set ��¼״̬ 
 *		������״̬�Ѿ���¼�� set �У������Ѹ�״̬������ȥ
 *		ֱ���ɽ⿪����״̬������������״̬ �����㷨
 *		ʹ�ù������BFS�������У�
 *			ÿ��һ�����������״̬��һ�����������״̬�ģ����ز����������㷨 
 *		ʹ���������DFS�����ݹ�
 *			��Ҫ�߱����н��ⷽ����������з������貽�������ҳ���С��������
 */
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		string now="";
		string des="123450"; //���ǽ⿪���״̬ 
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[0].size();j++) 
				now+=to_string(board[i][j]); //��ʼ״̬ 
				
		if (now==des) return 0;
		
		vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
		queue<pair<int,string>> q; // q���������ȱ���.string��״̬��int�Ǹ�״̬�ǵڼ��� 
		set<string> s; //s���ڼ�¼���б�����״̬
		s.insert(now);
		q.push({0,now});
		while (!q.empty()) {

			for(auto &v:dir) {
				auto step = q.front().first;
				auto tmp  = q.front().second;
				int pos = tmp.find('0');
				int x = int(pos/3)+v.first;
				int y = int(pos%3)+v.second;
				if (x<0 || 2<=x || y<0 || 3<=y) continue;
				
				swap(tmp[pos],tmp[x*3+y]);
				if(tmp==des) return step+1;
				if(s.find(tmp)==s.end()) { //�������tmp����״̬ 
					s.insert(tmp);
					q.push({step+1,tmp});
				}
			}
			q.pop();	
		}
		return -1;
	}
};

int main() {
	Solution solu;	
	vector<vector<int>> matrix({{4,1,2},{5,0,3}});	
	cout << solu.slidingPuzzle(matrix);
	return 0;
}
