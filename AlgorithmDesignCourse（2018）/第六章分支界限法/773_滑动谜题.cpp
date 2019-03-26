/* 题目：773. 滑动谜题
 * 要求：在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
		 0 与一个相邻的数字进行交换.最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
		给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
 * 来源：https://leetcode-cn.com/problems/sliding-puzzle/description/
 * 时间：2018-11-15
 */
 
/**
 *	思路：
 *		每个状态都有上下左右四个交换成新状态，用 set 记录状态 
 *		如果这个状态已经记录在 set 中，则不在已该状态进行下去
 *		直达达成解开谜题状态，或走完所有状态 结束算法
 *		使用广度优先BFS——队列，
 *			每走一步，获得所有状态，一旦有满足解题状态的，返回步数，结束算法 
 *		使用深度优先DFS——递归
 *			需要走遍所有解题方案，获得所有方案所需步数，并找出最小步数方案
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
		string des="123450"; //这是解开题的状态 
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[0].size();j++) 
				now+=to_string(board[i][j]); //初始状态 
				
		if (now==des) return 0;
		
		vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
		queue<pair<int,string>> q; // q用与广度优先遍历.string记状态，int记该状态是第几步 
		set<string> s; //s用于记录所有遍历的状态
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
				if(s.find(tmp)==s.end()) { //交换后的tmp是新状态 
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
