/*
矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
a b c e 
s f c s 
a d e e 
这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径
*/


/**
一个递归遍历的例子
vis数组的回退思想 
还有二维数组以指针传递后只能当场一位来使用了，这一点要特别注意 
即 matrix[x][y] 要改成 matrix[x*rows+y]
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Solution {
public:
	int dir_x[4] = {1,0,-1,0};
	int dir_y[4] = {0,1,0,-1};
	bool hasPath(char* matrix, int rows, int cols, char* str, int* vis, int x, int y){
		if(strlen(str)==0) return true;
		
		for(int r=0; r<4; ++r){
			int nx = x+dir_x[r];
			int ny = y+dir_y[r];
			if(0<=nx && nx<rows && 0<=ny && ny<cols && matrix[nx*cols+ny]==*str && vis[nx*cols+ny]==0){
				vis[nx*cols+ny]=1; 
				if(hasPath(matrix, rows, cols, str+1, vis, nx, ny)) return true;
				vis[nx*cols+ny]=0;
			}
		}
		return false; 
	}
	
    bool hasPath(char* matrix, int rows, int cols, char* str){
		if(rows<=0||cols<=0) return false;
		if(strlen(str)==0) return true;
		
 		int *vis = new int[rows*cols]();
 		memset(vis, 0, sizeof(vis));
    	for(int i=0; i<rows; ++i){
    		for(int j=0; j<cols; ++j){
    			if(matrix[i*cols+j]!=*str){
    				vis[i*cols+j]=1;
    				if(hasPath(matrix, rows, cols, str+1, vis, i, j)) return true;
    				vis[i*cols+j]=0;
				} 
			}
		}
    	return false;
    }
};

int main(){
	class Solution solu;
	char *m = "abcesfcsadee";
	char *str="bcc";
	cout<<solu.hasPath(m, 3, 4, str);
	return 0;
}
