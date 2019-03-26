//动态规划
//用 2*1 小矩形铺 2*n大矩形方案数 。 f[0]设值为 1 
//f[1]=1 
//f[2]=f[1]+f[0]=2
//f[3]=f[2]+f[1]=3
//f[4]=f[3]+f[2]=5
//分析。考虑铺第一块，有如下两种情况
//	情况一：竖着铺，剩下空间2*(n-1)，方案数为f[n-1]。
//	情况二：横着铺，下面固定要再横着铺一块，剩下空间 2*(n-2)，方案数为f[n-2]。
//	所以当 n>=2时，f[n]=f[n-1]+f[n-2] 

#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if(number<=0)  return 0;
		
		int f0=1,f1=1,f;
        while(number--){
			f=f0+f1;
			f0=f1;
			f1=f;
		}
		return f0; 
    }
};

int main(){
	Solution solu;
	cout << solu.rectCover(3);
	return 0;
} 
