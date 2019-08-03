/*
求1+2+3+...+n

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

使用递归算法实现 
*/
#include<bits/stdc++.h> 

class Solution {
public:
    int Sum_Solution(int n) {
    	int a = n;
    	a>0 && (a += Sum_Solution(n-1));
    	return a; 
    }
};

int main(){
	class Solution solu;
	printf("%d",solu.Sum_Solution(3));
	return 0;
}
