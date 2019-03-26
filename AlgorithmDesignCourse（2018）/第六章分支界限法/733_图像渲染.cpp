/* 题目：733. 图像渲染
 * 要求：给你一个坐标 (sr, sc) 表示起点和一个新的颜色值 newColor，让你重新上色这幅图像。
         将所有有与起点相连的，且数值与起点数值一样的这块区域数值 改为 newColor。
         输入: 
			[1,1,1]
			[1,1,0]
			[1,0,1]]
			sr = 1, sc = 1, newColor = 2
		输出: 
			[2,2,2]
			[2,2,0]
			[2,0,1]]
 * 来源：https://leetcode-cn.com/problems/flood-fill/description/
 * 时间：2018-11-8
 */
 
/**
 * 思路：
 *		暴力解法
 *		使用递归，从起点开始，朝四个方向改过去，不断更新迭代 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
	void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int oldColor){
		int r = image.size();
		int c = image[0].size(); 
		int dir[][2] = {{-1,0},{0,-1},{1,0},{0,1}}; //4个方向 
		image[sr][sc]=newColor;
		for(int i = 0; i < 4; ++i){
			int x = sr+dir[i][0];
			int y = sc+dir[i][1];
			if(x>=r||x<0||y>=c||y<0||image[x][y]!=oldColor) continue;
			dfs(image, x, y, newColor,oldColor);
		}
	}

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int oldColor = image[sr][sc];
		if(oldColor!=newColor)
		dfs(image,sr,sc,newColor,oldColor);
		return image;
	}
};

void output(vector<vector<int>> image) {
	for(auto line:image){
		for(auto e:line) cout<<e<<' ';
		cout<<endl;
	}
}

int main(){
	Solution solu;
	vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
	output(solu.floodFill(image, 1, 1, 2)) ;
	return 0;
}
