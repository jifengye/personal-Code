/*
�����е�·��

�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� 
a b c e 
s f c s 
a d e e 
������3 X 4 �����а���һ���ַ���"bcced"��·����
���Ǿ����в�����"abcb"·��
*/


/**
һ���ݹ����������
vis����Ļ���˼�� 
���ж�ά������ָ�봫�ݺ�ֻ�ܵ���һλ��ʹ���ˣ���һ��Ҫ�ر�ע�� 
�� matrix[x][y] Ҫ�ĳ� matrix[x*rows+y]
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
