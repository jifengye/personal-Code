/*
�㷨�������� 5.2 �������Χ��
����Ŀ����
��n�鳤�Ȳ�ͬ��ľ�壬��������Щľ��ƴ��һ���ȱ������ε�Χ����
���ڣ�������n��ľ��ĳ��ȣ���������֪�����ܷ�ƴ�����Χ����
Ҫ��n��ľ�嶼�����ϡ�

�������ʽ
��һ��Ϊһ��������T����ʾ��T��������ݡ�
����ÿ��������ݣ���һ��Ϊһ��������n����ʾľ�������
�ڶ��а���n������������ʾÿ��ľ��ĳ��ȡ�

����60%�����ݣ�1<=T<=5��3<=n<=5��ÿ��ľ�峤�ȴ��ڵ���1С�ڵ���100��
����100%�����ݣ�1<=T<=5��3<=n<=10��ÿ��ľ�峤�ȴ��ڵ���1С�ڵ���100��

�������ʽ
�����ƴ��Χ�����Yes���������No��

����������
2
4
1 2 3 4
4
1 2 3 3
���������
No
Yes
*/

#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int side[3],RSide = 0;
int Len[11]; 

bool cmp(const int a, const int b){
	return a>b;
}


int dfs(int step){
	if(step==n){
//		cout<<side[0]<<side[1]<<side[2]<<endl;
		return side[0]==RSide && side[1]==RSide && side[2]==RSide;
	}
	for(int i=0; i<3; ++i){
		if(side[i]+Len[step]<=RSide){
			side[i]+=Len[step];
			if(dfs(step+1)) return 1;
			side[i]-=Len[step];
		}
	}
	return 0;
}

int fun(){
	scanf("%d",&n);
	int sum=0;
	memset(side, 0, sizeof(side));
	for(int i=0; i<n; ++i){
		scanf("%d", &Len[i]);
		sum += Len[i];
	}
	if(sum%3!=0) return 0;
	RSide = sum/3;
	
	sort(Len, Len+n);
	
	if(Len[0]>RSide) return 0;
	
	return dfs(0); 
}

int main(){
	scanf("%d",&T);
	while(T--){
		fun()==1 ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
