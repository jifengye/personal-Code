/*
算法设计与分析 2.1 杰哥和序列
★题目描述
杰哥喜欢单调不下降的序列，因为他觉得这样的序列有美感。
今天杰哥得到了一个长度为N的序列D，但是他今天心情不好，他把序列丢给了你，要你把他变成单调不下降的序列。
你可以花费A单位的时间交换序列中两个相邻的元素，当然，你也可以选择干一半摸鱼罢工。
最后你要把序列还给杰哥，但是如果杰哥发现序列中每有一个逆序对，就会把你抓过去，训话B单位时间。
你想花最少的时间（主动交换元素+被动被杰哥训话的时间）把这个事解决了，问这个时间是多少。
逆序对的定义：存在两个整数i和j，满足这个有序对称为的一个逆序对。

★输入格式
输入第一行为三个空格隔开的正整数 N、A、B，代表序列长度为N，A和B的含义见题面。
接下来一行有 N 个整数，第i个数表示序列的第


★输出格式
输出你要花费的最少时间。

★样例输入
2 1 2
2 1
★样例输出
1
*/
/*
归并排序的次数就是逆序对数量
一个坑是ans的数据类型要用 long long 型 
 
*/
#include<bits/stdc++.h>
using namespace std;
#define min(a,b) (a<b?a:b) 
long long ans=0;
int A[100001];
int B[100001];

void Merge(int low, int mid, int top){
	int i=low;
	int j=mid+1;
	int k=low;
	while(i<=mid && j<=top){
		if(A[i]<=A[j]) B[k++]=A[i++];
		else{
			B[k++]=A[j++];
			ans += mid-i+1;
		} 
	}
	while(i<=mid)  B[k++]=A[i++];
	while(j<=top)  B[k++]=A[j++];
	
	for(int t=low; t<=top; t++) A[t]=B[t];
} 

void MergeSort(int low, int top){
	if(low>=top) return;
	
	int mid = (low+top)>>1;
	MergeSort(low,mid);
	MergeSort(mid+1,top);
	
	Merge(low,mid,top);
} 

int main(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	
	for(int i=0; i<n; ++i){
		scanf("%d",&A[i]);
	}
	
	MergeSort(0,n-1);

	//printf("%ld\n",ans*min(a,b));
	cout<<ans*min(a,b)<<endl;
	return 0;
}
