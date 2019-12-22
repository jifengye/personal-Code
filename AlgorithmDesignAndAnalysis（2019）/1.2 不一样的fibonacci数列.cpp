/*
算法设计与分析 1.2 不一样的fibonacci数列
★题目描述
fibonacci 数列的递推公式是F(n) = F(n-1) + F(n-2)（n >= 2 且 n 为整数）。
将这个递推式改为F(n) = a*F(n-1) + b*F(n-2)（n >= 2 且 n 为整数）时得到的是怎样的数列。
注意，这里我们依然令 F（0）=F（1）=1。

★输入格式
输入第一行三个正整数 q, a, b。
接下来有 q 行，每行一个自然数 n。
对于50%的数据，1 <= q、n <= 1000。
对于80%的数据，1 <= q、n <= 100000。
对于100%的数据，1 <= q <= 100000,1 <= n <= 1000000000,1 <= a、b <= 1000。

★输出格式
输出一行一个整数 F（n），输出结果对 2013 取模。

★样例输入
5 4 5
2
4
8
16
32
★样例输出
9
209
1377
182
9
*/

/*
可以使用递归或用数组+循环的方法
但是这种方法必定超时

所以必须优化，使用矩阵求法
进行公式推导： 
 f[n]        [a b]    f[n-1]     [a  b]^n-1   f[1]
       =           *          =             * 
f[n-1]       [1 0]    f[n-2]     [1  0]       f[0]

所以核心是 
[a  b]^n-1
[1  0]

现在问题转化为快速求矩阵的幂 
A8 = A4*A4 = A2*A2*A4   时间降为log(n) 
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//int q,a,b;
//const int mod=2013;
//
//class Matrix{
//private:
//	int a11,a12,a21,a22; 
//	
//public:
//	Matrix(){}
//	Matrix(int a,int b,int c,int d){
//		a11=a%mod;
//		a12=b%mod;
//		a21=c%mod;
//		a22=d%mod;
//	}
//	Matrix operator *(const Matrix &m){
//		return Matrix(a11*m.a11+a12*m.a21, a11*m.a12+a12*m.a22,
//					  a21*m.a11+a22*m.a21, a21*m.a12+a22*m.a22); 
//	}
//	int getRes(){
//		return (a11*1+a12*1)%mod; 
//	}
//}; 
//
//int fib(int n){
//	Matrix resM(1,0,0,1); //单元矩阵 
//	Matrix M(a,b,1,0);
//	while(n>0){
//		if(n&1) resM = resM*M;//如果n不是偶数
//		M=M*M;
//		n>>=1; //n缩小2倍 
//	}
//	return resM.getRes(); 
//}
//
//int main(){	
//	cin>>q>>a>>b;
//	
//	int n;
//	while(q--){
//		scanf("%d",&n);
//		printf("%d\n",fib(n-1));	
//	}
//	return 0;
//}


/*
此外因为时模2013
所以是一个不断循环的数组
可以找出这个循环 
*/

