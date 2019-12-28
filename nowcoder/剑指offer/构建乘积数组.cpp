/*
构建乘积数组

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        vector<int> b(n);
        int ret=1;
        for(int i=0;i<n;ret*=A[i++]){
            b[i]=ret;
        }
        ret=1;
        for(int i=n-1;i>=0;ret*=A[i--]){
            b[i]*=ret;
        }
        return b;
    }
};


int main(){
	class Solution solu;
	vector<int> A = {1,2,3,4,5};
	vector<int> B = solu.multiply(A);
	for(auto e:B) cout<<e<<endl;
	return 0;
}
