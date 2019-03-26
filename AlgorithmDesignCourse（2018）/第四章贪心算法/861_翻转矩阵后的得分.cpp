/* ��Ŀ��861. ��ת�����ĵ÷�
 * Ҫ����һ����ά���� A������ÿ��Ԫ�ص�ֵΪ 0 �� 1 ��
		 ��ת��ָѡ����һ�л��У����л����е�ÿһ��ֵ 0 �� 1��1 �� 0 
		 ����������������ƶ��󣬽��þ����ÿһ�ж����ն������������ͣ�����ĵ÷־�����Щ���ֵ��ܺ͡�
		 �󷵻ؾ����ܸߵķ�����
 * ��Դ��https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 * ʱ�䣺2018-11-04
 */
 
/**
 * ̰��˼��
 *   ÿ�еĵ�һλ������1 --> �б任ȷ���ˣ����������б任 
 *   �ٿ���ÿһ�У�һ������0�ĸ�������1�ĸ������ͷ�ת���� 
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 

class Solution {
private:
	void rot_row(int row, vector<vector<int> > &A){ //��ת�� 
		for(int col=0; col<A[0].size(); col++){
			A[row][col] ^= 1;
		}
	}
	
	void rot_col(int col, vector<vector<int> > &A){ //��ת�� 
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
        	if(A[i][0] == 0) rot_row(i, A); //ÿ�еĵ�һλ������1 
		}
		
		for(int j=1; j<col_number; j++){ 
			int cnt_one = 0;
			for(int i=0; i<row_number; i++)
				cnt_one += A[i][j];
			if(cnt_one*2 < A.size()) rot_col(j, A); //һ������0�ĸ�������1�ĸ������ͷ�ת���� 
		}
		
		int result = 0;
		for(int i=0; i<row_number; i++){ //������� 
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
