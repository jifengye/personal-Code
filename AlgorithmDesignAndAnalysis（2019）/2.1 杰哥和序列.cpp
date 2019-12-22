/*
�㷨�������� 2.1 �ܸ������
����Ŀ����
�ܸ�ϲ���������½������У���Ϊ���������������������С�
����ܸ�õ���һ������ΪN������D���������������鲻�ã��������ж������㣬Ҫ�������ɵ������½������С�
����Ի���A��λ��ʱ�佻���������������ڵ�Ԫ�أ���Ȼ����Ҳ����ѡ���һ������չ���
�����Ҫ�����л����ܸ磬��������ܸ緢��������ÿ��һ������ԣ��ͻ����ץ��ȥ��ѵ��B��λʱ�䡣
���뻨���ٵ�ʱ�䣨��������Ԫ��+�������ܸ�ѵ����ʱ�䣩������½���ˣ������ʱ���Ƕ��١�
����ԵĶ��壺������������i��j�������������Գ�Ϊ��һ������ԡ�

�������ʽ
�����һ��Ϊ�����ո������������ N��A��B���������г���ΪN��A��B�ĺ�������档
������һ���� N ����������i������ʾ���еĵ�


�������ʽ
�����Ҫ���ѵ�����ʱ�䡣

����������
2 1 2
2 1
���������
1
*/
/*
�鲢����Ĵ����������������
һ������ans����������Ҫ�� long long �� 
 
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
