/*
�㷨�������� 5.5 ��-�׸���
����Ŀ����
����1-n��һ�����У�Ҫ���㽫�������ţ�ʹ�������������ڵ����ĺ�Ϊ������

�������ʽ
һ��������n��n<=20��

�������ʽ
���һ��һ��1-n�����У��������ڵ����������Ϊ������
����ж���⣬����ֵ�����С����һ����
����޽⣬���-1��

����������1
2
���������1
1 2
����������2
3
���������2
1 2 3
*/
/*
�Ż�һ��
	һ��һż���� 
*/


#include<bits/stdc++.h>
using namespace std;
int n;
int res[21];

int isPrime(int num){ 
    if(num==2) return true; //2���⴦�� 
    if(num<2 || num%2 == 0) return false; //ʶ��С��2������ż�� 
	for(int i=3; i*i<=num; i+=2){
		if(num%i==0) return false;
	}
	return true;
}

void dfs(int step){
	if(step==n+1){
		for(int i=1; i<=n; ++i) printf("%d ",res[i]);
		exit(0);
	}
	for(int i=step; i<=n; i+=2){
		swap(res[step], res[i]);
		if(isPrime(res[step]+res[step-1])) dfs(step+1);
		swap(res[step], res[i]);
	}
} 

int main(){
	scanf("%d",&n);
 
	for(int i=1; i<=n; ++i){
		res[i]=i;
	}
	
	for(int i=1; i<=n; i+=2){
		swap(res[1], res[i]);
		dfs(2);
		swap(res[1], res[i]);
	}
	printf("-1\n"); 
	return 0;
}




//
///** ������ **/
////https://www.luogu.org/problem/UVA524
// 
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int res[21];
//
//int isPrime(int num){ 
//    if(num==2) return true; //2���⴦�� 
//    if(num<2 || num%2 == 0) return false; //ʶ��С��2������ż�� 
//	for(int i=3; i*i<=num; i+=2){
//		if(num%i==0) return false;
//	}
//	return true;
//}
//
//void dfs(int step){
//	if(step==n+1){
//		if(isPrime(res[n]+res[1])){
//			for(int i=1; i<=n; ++i) printf("%d ",res[i]);
//			printf("\n");
//		}
//	}
//	for(int i=step; i<=n; i+=2){
//		swap(res[step], res[i]);
//		if(isPrime(res[step]+res[step-1])) dfs(step+1);
//		swap(res[step], res[i]);
//	}
//} 
//
//int main(){
//	int id=1; 
//	while(~scanf("%d",&n)){	
//		if(id>=2) {     //�ڶ����Ҫ��ʼ��������ˡ���
//            printf("\n");
//        }
//		for(int i=1; i<=n; ++i){
//			res[i]=i;
//		}
//		printf("Case %d:\n",id++);
//		dfs(2);
//	}
//	return 0;
//}
