/*
算法设计与分析 1.3 杰哥和数字
★题目描述
杰哥特别喜欢和数字打交道，现在他有一个正整数X,他想知道有多少个满足要求的正整数D存在，要求是D是X的因子，并且D和X至少有一位相同。

★输入格式
只有一行，一个正整数X。

对于30%的数据，X<=100。

对于50%的数据，X<=200。

对于100%的数据，X<=1000000000。

★输出格式
只有一行，一个整数表示满足要求的数字D的个数。

★样例输入
10
★样例输出
2
*/

/*
因子就是所有可以整除这个数的数,但是不包括这个数自身.

先搜索是因子的整数，再判断是否有重复数字 （v）
先搜索重复数字整数，再判断是否为因子 （x）
*/
#include<bits/stdc++.h>
int book[10]={0};

int isbaohan(int a){
	while(a!=0){ 
		if(book[a%10]) return 1;
		a=a/10;
	}	
	return 0;
}

int main(){
	int X; 
	scanf("%d",&X);
	
	
	int n=X;
	while(n!=0){
		book[n%10]=1;
		n=n/10;
	}
	
//	for(int j=0; j<10; ++j){
//		printf("%d",book[j]);
//	}
	
	
	int ans = 0, a, b;
	for(int i=1; i*i<=X; ++i){
		if(X%i!=0) continue;
		a=i;
		b=X/i;
		if(a==b){
			if(isbaohan(a)) ans++;
		} else {
			if(isbaohan(a)) ans++;
			if(isbaohan(b)) ans++;
		}
	}
	printf("%d",ans);
	return 0;	
}
