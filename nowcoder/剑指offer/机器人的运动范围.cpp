/*
机器人的运动范围

地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？
*/

/*
没有说不能回退
求能够遍布的范围
使用深度递归遍历 
*/
#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
	int bitSum(int t){ //求数位和 
        int count = 0;
        while (t != 0){
            count += t%10;
            t /= 10;
        }
        return  count;
    }

	int vis[100][100];
	int dir_x[4] = {1,0,-1,0};
	int dir_y[4] = {0,1,0,-1};
	int movingCount(int threshold, int rows, int cols, int x, int y) {
       	int ans=1;
		for(int r=0; r<4; ++r){
			int nx = x+dir_x[r];
			int ny = y+dir_y[r];
			if(0<=nx && nx<rows && 0<=ny && ny<cols && bitSum(nx)+bitSum(ny)<=threshold && vis[nx][ny]==0){
				vis[nx][ny]=1; 
				ans += movingCount(threshold, rows, cols, nx, ny);
			}
		}
		return ans;
    }
	
    int movingCount(int threshold, int rows, int cols) {
    	if(threshold<0) return 0;
		memset(vis,0,sizeof(vis));
		vis[0][0]=1;
		return movingCount(threshold, rows, cols, 0, 0);
    }
};

int main(){
	class Solution solu;
	cout<<solu.movingCount(-10, 10, 10);
	return 0;
}
