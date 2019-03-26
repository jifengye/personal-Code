/*
74. ������ά����
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������


ʾ�� 1:
����:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
���: true


ʾ�� 2:
����:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
���: false
*/

/*
˼·
	��Ҫ��������һ����ά����������ֱ�Ӱ�������һ���ź����һά�������Դ���
	ע������ת����matrix[i][j]  <=> matrix[a]   ����a=i*n+j�� i=a/n,  j=a%n; 
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
       
	    //���ֲ���Ŀ��ֵ
        int m = matrix.size(), n = matrix[0].size(), l= 0, r = m*n - 1;	
        while (l <= r){
            int mid = l + (r - l) / 2;
            if(target < matrix[mid/n][mid%n])  r = mid-1;
            else if(target > matrix[mid/n][mid%n]) l = mid+1;
            else return true;
        }
        return false;
    }
};

int main() {
	Solution solu;
	vector<vector<int>> matrix = {{1, 3}};
	cout<<solu.searchMatrix(matrix, 3);
	return 0;
}
