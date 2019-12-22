/*
算法设计与分析 4.1 洪尼玛与巧克力工厂
★题目描述
洪尼玛的巧克力工厂准备进行n天的生产，第i天生产1块巧克力的花费为ci元，第i天需要交付给客户ai块巧克力。

洪尼玛有一个冰柜可以存放无限多块巧克力（保证巧克力不会坏掉），但是存放每块巧克力每天的花费为s元。

洪尼玛想知道完成这n天所有订单的最小花费是多少？


★输入格式
第一行为两个正整数n、s，表示总天数和存储每块巧克力每天的花费；

接下来n行，每行两个正整数ci、ai，表示第i天生产1块巧克力的花费和需要交付给客户的巧克力数量；

对于60%的数据，1<=n<=103；

对于100%的数据，1<=n<=106、1<=s<=102、1<=ci、ai<=103。


★输出格式
输出一个正整数，表示最小花费。


★样例输入
3 1
1 1
3 2
2 3
★样例输出
11
*/

/*
假设当前时第 cnt 天 
第i天生产1块所需花费 p = ci + (cnt-i)*s  
*/

#include<bits/stdc++.h>
using namespace std;

int n,s;
int c_min=0X3FFFFF;
long ans=0;

int main(){
	scanf("%d%d",&n,&s);
	
	int c, a;
	for(int i=0; i<n; i++){
		scanf("%d%d",&c,&a);
		c_min = min(c_min+s, c);
		ans += a*c_min;
	} 
	
	printf("%ld\n",ans);
	return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAX = 1000000 + 5;
//int a,c;
//
//int main(){
//  int c1, n, s, temp;
//  long long sum = 0;
//  scanf("%d%d",&n,&s);
//  scanf("%d %d", &c, &a);
//  sum = c * a;
//  temp = c;
//  for(int i = 1;i < n; i++){
//    scanf("%d %d", &c, &a);
//    temp = min(c, temp+s);
//    sum += temp * a;
//  }
// 
//  printf("%lld\n",sum);
//
//  return 0;
//}

