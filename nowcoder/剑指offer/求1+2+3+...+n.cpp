/*
��1+2+3+...+n

��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

ʹ�õݹ��㷨ʵ�� 
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
