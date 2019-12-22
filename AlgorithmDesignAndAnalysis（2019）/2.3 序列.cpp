/*
算法设计与分析 2.3 01序列
★题目描述
给定一个序列，刚开始只有一个数N。
序列里大于1的数X会进行分裂，
即在序列中删除X，并在原来X的位置插入 下取整X/2，X mod 2, 下取整X/2三个数，直到序列中只有0和1。
问最后序列中第L个数到第R个数之间有多少个1。

★输入格式
数据保证R不大于最后序列的长度。

★输出格式
一个整数，最后序列中第L个数到第R个数之间有多少个1。

★样例输入
4 3 6
★样例输出
2
★提示
样例中，序列变化如下：
4→202→1010101
第3个数到第6个数之间有2个1。
*/

/*
先计算01序列长度和n大小的关系
0  0
1  1 
2  101 
3  111 
4  1010101
5  1011101
6  1110111
7  1111111
8  101010101010101 
9  101010111010101
10 101110101011101 
11 101110111011101
12 111011101110111
13 111011111110111
14 111111101111111
15 111111111111111
16 1010101010101010101010101010101 

所以长度关系为
	L=2^0+2^1+ ……+2^t        2t  ≤n 
 

这个是分治算法 
这个01序列是根据分治思想左右对称的 

*/
#include<bits/stdc++.h>
using namespace std;

int N,L,R;

int df(int n, long long Len, int pos){
//	cout<<" n="<<n<<" ("<<pos-Len/2<<","<<pos<<","<<pos+Len/2<<" )"<<endl;
	if(R<pos-Len/2 || pos+Len/2<L) return 0;
	if(Len==1) return  n%2;
	
	int dis = (Len+1)/4;
	if(L<=pos && pos<=R) return df(n/2, Len/2, pos-dis) + n%2 + df(n/2, Len/2, pos+dis);
	if(R<pos) return df(n/2, Len/2, pos-dis);
	if(pos<L) return df(n/2, Len/2, pos+dis);
} 


int main(){
	cin>>N>>L>>R;

	long long Len=0;
	for(int i=0; pow(2,i)<=N; ++i) Len+=pow(2,i);

	cout<<df(N, Len, (1+Len)/2)<<endl;
	
	return 0;
}
