/* ��Ŀ��733. ͼ����Ⱦ
 * Ҫ�󣺸���һ������ (sr, sc) ��ʾ����һ���µ���ɫֵ newColor������������ɫ���ͼ��
         ������������������ģ�����ֵ�������ֵһ�������������ֵ ��Ϊ newColor��
         ����: 
			[1,1,1]
			[1,1,0]
			[1,0,1]]
			sr = 1, sc = 1, newColor = 2
		���: 
			[2,2,2]
			[2,2,0]
			[2,0,1]]
 * ��Դ��https://leetcode-cn.com/problems/flood-fill/description/
 * ʱ�䣺2018-11-8
 */
 
/**
 * ˼·��
 *		�����ⷨ
 *		ʹ�õݹ飬����㿪ʼ�����ĸ�����Ĺ�ȥ�����ϸ��µ��� 
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
		int dir[][2] = {{-1,0},{0,-1},{1,0},{0,1}}; //4������ 
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
