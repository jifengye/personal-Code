/*
算法设计与分析 5.3 数字排列
★题目描述
给两个正整数A和B，请问通过重新排列A获得小于或等于B的最大数字是多少(不含前导0)？

★输入格式
输入的第一行两个数字A和B，保证这两个数字在int范围内。

★输出格式
输出A重新排列后小于或等于B的最大整数(不含前导0)，若不存在输出-1。

★样例输入
1234 3456

★样例输出
3421
*/ 

/*
全排列用 prev_permutation 函数实现 
*/
#include<bits/stdc++.h>
using namespace std;

string A, B;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>A>>B;
	
	sort(A.begin(), A.end(), greater<char>());
	
	string res = "";
	int lenA = A.length(), lenB = B.length();
	if(lenA<lenB){ //所有排列统统小于B，只取字典序最大的排列即可 
		res = A;
	}
	else if(lenA==lenB){ //对A全排列 
		do{
			if(A.front()=='0') break; //不含前导0
			if(A<=B) res=max(res, A);
		}while(prev_permutation(A.begin(), A.end()));	
	}
	
	res=="" ? cout<<"-1"<<endl : cout<<res<<endl;
	return 0;
} 
