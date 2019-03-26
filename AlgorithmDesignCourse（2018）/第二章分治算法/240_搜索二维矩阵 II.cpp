/* ��Ŀ��240.������ά����II 
 * Ҫ�������������Ƿ���Ҫ���ҵ�targetֵ������Ԫ�ش����Ҵ��ϵ����������С� 
 * ��Դ��https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/ 
 * ���룺2 2 1 1 5 6 1 2 2 1 1
 * �����1 
 * ʱ�䣺2018/9/23
 */
 
/* ����һ�����ƻ���������
 * ʱ�临�Ӷȣ� O(n) 
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//using namespace std;
//
//class Solution {
//	public:
//		bool searchMatrix(vector<vector<int> >& matrix, int target) {
//			if (matrix.empty() || matrix[0].empty()) return false;
//			
//			int n = matrix.size();
//			int m = matrix[0].size();
//	        for(int i = 0, j = m - 1; j >=0 && i < n;) {
//	            if(matrix[i][j] == target) return true;
//	            else if(matrix[i][j] < target) i++;
//	            else if(matrix[i][j] > target) j--;
//	        }
//	        return false;
//		}
//};
//
//int main(){
//    Solution solu;
//    vector<vector<int> > matrix = {{1,   4,  7, 11, 15},{2,   5,  8, 12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
//    cout << boolalpha << solu.searchMatrix(matrix,15);
//    return 0;
//}

/* ������������
 * ʱ�临�Ӷȣ�  
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//using namespace std;
//
//class Solution {
//	private:
//		void output(vector<vector<int> >& matrix){
//			for(int i=0; i<matrix.size(); i++){
//				for(int j=0; j<matrix[0].size(); j++){
//					cout << matrix[i][j];
//				}
//				cout<<endl;
//			}
//		}
//		
//	public:
//		bool searchMatrix(vector<vector<int> > matrix, int target) {
//			if (matrix.empty() || matrix.begin()->empty()) return false;
//			
//			int n = matrix.size();
//			int m = matrix[0].size();
//			if( matrix[0][0]>target || matrix[n-1][m-1]<target ) return false;
//			if(n==1 && m==1 && matrix[0][0]==target) return true;
//			
//			
//			
//			//��һ���������Ϊ4���Ӿ������ʵ���д��Ľ�����forѭ����ֵ��ʱ 
//			int c_n = n >> 1;
//			int c_m = m >> 1;
//			vector<vector<int> > matrix1(c_n, vector<int>(c_m));
//			vector<vector<int> > matrix2(c_n, vector<int>(m-c_m));
//			vector<vector<int> > matrix3(n-c_n, vector<int>(c_m));
//			vector<vector<int> > matrix4(n-c_n, vector<int>(m-c_m));
//			for(int i=0; i<matrix1.size(); i++)
//				for(int j=0; j<matrix1[0].size(); j++)
//					matrix1[i][j] = matrix[i][j];
////			cout<<"matrix1  ";output(matrix1);
//			for(int i=0; i<matrix2.size(); i++)
//				for(int j=0; j<matrix2[0].size(); j++)
//					matrix2[i][j] = matrix[i][j+c_m];
////			cout<<"matrix2  ";output(matrix2);
//			for(int i=0; i<matrix3.size(); i++)
//				for(int j=0; j<matrix3[0].size(); j++)
//					matrix3[i][j] = matrix[i+c_n][j];
////			cout<<"matrix3  ";output(matrix3);
//			for(int i=0; i<matrix4.size(); i++)
//				for(int j=0; j<matrix4[0].size(); j++)
//					matrix4[i][j] = matrix[i+c_n][j+c_m];	
////			cout<<"matrix4  ";output(matrix4);
//
//
//
//			if(searchMatrix(matrix1,target) || searchMatrix(matrix2,target) || searchMatrix(matrix3,target) || searchMatrix(matrix4,target))
//				return true;
//			else
//				return false;
//		}
//};
//
//int main(){
//    Solution solu;
//    vector<vector<int> > matrix = {{1,   4,  7, 11, 15},{2,   5,  8, 12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
//    cout << boolalpha << solu.searchMatrix(matrix,15);
//    return 0;
//}
