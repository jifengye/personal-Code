/* 题目：861. 翻转矩阵后的得分
 * 要求：有一个二维矩阵 A，其中每个元素的值为 0 或 1 。
		 翻转是指选择任一行或列，该行或列中的每一个值 0 变 1，1 变 0 
		 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
		 求返回尽可能高的分数。
 * 来源：https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 * 时间：2018-11-04
 */
 
/**
 * 贪心思想
 *   每行的第一位必须是1 --> 行变换确定了，接下来是列变换 
 *   再考虑每一列，一旦该列0的个数多于1的个数，就翻转该列 
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 

class Solution {
private:
	void rot_row(int row, vector<vector<int> > &A){ //翻转行 
		for(int col=0; col<A[0].size(); col++){
			A[row][col] ^= 1;
		}
	}
	
	void rot_col(int col, vector<vector<int> > &A){ //翻转列 
		for(int row=0; row<A.size(); row++){
			A[row][col] ^= 1;
		}
	}

public:
    int matrixScore(vector<vector<int> >& A) {
        if(A.empty()) return 0;
        
        int row_number = A.size();
        int col_number = A[0].size();
		for(int i=0; i<row_number; i++){
        	if(A[i][0] == 0) rot_row(i, A); //每行的第一位必须是1 
		}
		
		for(int j=1; j<col_number; j++){ 
			int cnt_one = 0;
			for(int i=0; i<row_number; i++)
				cnt_one += A[i][j];
			if(cnt_one*2 < A.size()) rot_col(j, A); //一旦该列0的个数多于1的个数，就翻转该列 
		}
		
		int result = 0;
		for(int i=0; i<row_number; i++){ //计算分数 
			int line_score = 0;
			for(int j=0; j<col_number; j++){
				line_score += A[i][j]<<(col_number-j-1);
			}
			result += line_score;
		}
		return result;
    }
};

int main(){
	Solution Solu;
	vector<vector<int> > matrix = { {0,0,1,1},{1,0,1,0},{1,1,0,0} }; 
	cout <<  Solu.matrixScore(matrix);
	return 0;
}
