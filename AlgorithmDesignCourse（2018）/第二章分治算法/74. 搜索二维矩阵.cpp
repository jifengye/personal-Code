/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。


示例 1:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true


示例 2:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

/*
思路
	不要把它当成一个二维数组来看，直接把它当成一个排好序的一维数组来对待：
	注意坐标转换：matrix[i][j]  <=> matrix[a]   其中a=i*n+j， i=a/n,  j=a%n; 
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
       
	    //二分查找目标值
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
