/*
�㷨�������� 4.2 �����������繥��ս

����Ŀ����
��n���ڿ�Ϯ��������˾���˻�����i���ڿ�ÿ���ӿ��Դ��˻��е�ȡciԪ���Ը���i���ڿ���Ҫ2*tiʱ�� 
һ��������Ե�i���ڿͿ�ʼ���й������úڿͽ��޷�������ȡǮ�ƣ�������δ�������ĺڿͿ��Լ�����ȡǮ�ơ�
��n���ڿʹӵ�0ʱ�̿�ʼ����Ϯ������������֪���Ը�����n���ڿͺ󱻵�ȡ�Ľ����С�Ƕ��٣�

�������ʽ
��һ��Ϊһ��������n����ʾ�ڿ͵�������
������n�У�ÿ������������ci��ti����ʾ��i���ڿͣ�
����60%�����ݣ�1<=n<=103��
����100%�����ݣ�1<=n<=105��1<=ci��ti<=103��

�������ʽ
���һ������������ʾ����ȡ����С��

����������
5
1 1
2 2
3 3
4 4
5 5
���������
170
*/

/*
���Ȳ����Ȱ�ci���Ŀ�������Ϊ������ci-1�ĺڿ�ֻ��Ҫ1���� 
Ҳ�����Ȱ�ti��С�Ŀ�������Ϊ��tk���ĺڿ���ck��105������
��ô��ʱ�� ci/ti ��ʾʲô��
�Ƿ���� ci/ti �������� 
*/ 
#include<bits/stdc++.h>
using namespace std;
long long ID[100005];
long long C[100005];
long long T[100005];
long long ans=0;
long long res=0; 
int n;

bool cmp(const long long a, const long long b){
	return C[a]*T[b] > C[b]*T[a];
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		scanf("%lld%lld", &C[i], &T[i]);
		ID[i]=i;
		ans+=C[i];
	}
	
	sort(ID, ID+n, cmp);
	
	for(int i=0; i<n; ++i){
		ans-=C[ID[i]];
		res+=ans*T[ID[i]]*2;
	}
	printf("%lld\n",res);
	return 0;
}
/*
3
6 3
5 2
4 1
*/





/**
���� 
*/

//#include<bits/stdc++.h>
//using namespace std;
//int Order[100005];
//int C[100005];
//int T[100005];
//long long ans=0;
//long long minres=0x3f3f3f3f; 
//int n;
//
//void dfs(int step, long long res){
//	if(ans>res) return;
//	if(step==n){
//		if(res<=minres){			
//			printf("minres=%d, solve order: ",res);
//			for(int i=0; i<n; ++i){
//				printf("%d ",Order[i]);
//			}
//			printf("\n");
//		}
//		minres = min(minres, res);
//		return;
//	}
//	for(int i=step; i<n; ++i){
//		swap(Order[step], Order[i]);
//		ans -= C[Order[step]];
//		dfs(step+1, res+(ans*2*T[Order[step]]));
//		ans += C[Order[step]];
//		swap(Order[step], Order[i]);
//	}
//} 
//
//int main(){
//	scanf("%d",&n);
//	for(int i=0; i<n; ++i){
//		scanf("%d%d", &C[i], &T[i]);
//		Order[i]=i;
//		ans+=C[i];
//	}
//	
//	
//	for(int i=0; i<n; ++i){
//		swap(Order[0], Order[i]);
//		ans -= C[Order[0]];
//		dfs(1, ans*2*T[Order[0]]);
//		ans += C[Order[0]];
//		swap(Order[0], Order[i]);
//	}
//	printf("%d\n",minres);
//	return 0;
//}
/*
8
6 6
3 2
4 1
4 4
7 2
4 8
2 5
1 2
2 4 1 0 3 5 7 6
*/ 

