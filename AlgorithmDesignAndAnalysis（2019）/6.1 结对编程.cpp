/*
�㷨�������� ��Ա��
����Ŀ����
������n�������ֺ�m���۲��ߣ�ֻ���໥��Ϥ�Ĵ����ֺ͹۲��߲��ܽ������õĽ�Ա�̡�
��������������������Ľ�Ա�����

�������ʽ
����ĵ�һ����������n��m��k(1<=n��m<=100��1<=k<=n*m)����ʾ�������������۲�����������ʶ�Ĺ�ϵ��Ŀ��
������k��ÿ����������a(1<=a<=n)��b(1<=b<=m)�����aλ���������bλ�۲����໥��ʶ��

�������ʽ
���һ��������ʾ���Ľ�Ա����ϡ�

����������
2 2 2
1 1
2 2
���������
2
*/

/*
���ڽӱ��¼��ϵ 
��һ���������ƥ��ģ��
n�������ֵַ�A�Ӽ��� 
m���۲��߷ֵ�B�Ӽ��� 
*/ 
#include<bits/stdc++.h>
using namespace std;

int Match[100+5]; //��¼����B�Ӽ����۲��ߣ��Ƿ��Ѿ�ƥ���� 
int Visit[100+5]; //��¼����B�Ӽ����۲��ߣ��Ƿ��Ѿ��ʹ��� 

int H[100+5]; //��¼����A�Ӽ��������֣���ʶ�Ĺ۲��� 
struct Edge{
	int end,nxt; 
}E[10000+5]; //���ձ�ż�¼��ʶ��ϵ 

int idx=0;
void AddEdge(int u, int v){ //���ڽӱ�ʽ��¼��ϡ��ͼ 
    idx++;
    E[idx].end = v;
    E[idx].nxt = H[u];
    H[u] = idx;
}

int find(int x){
	for(int i=H[x]; i!=0; i=E[i].nxt){
		int e=E[i].end;
		if(Visit[e]==0){
			Visit[e]=1;
			if(Match[e]==0 || find(Match[e])){
				Match[e]=x;
				return 1;
			}
		}
	}
	return 0;//�Լ������ȫ������Ԥ���ˡ����ʧ�ܡ�
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int u,v;
	while(k--){
		cin>>u>>v;
		AddEdge(u,v);
	}
	
	int res=0;
	memset(Match, 0, sizeof(Match));
	for(int i=1; i<=n; ++i){ //��Ϊ�ڽӱ��ǴӴ���ѡ�ֽǶȼ�¼�ģ����ԴӴ���ѡ�ֽǶȳ�������� 
		memset(Visit, 0, sizeof(Visit));
		res += find(i);
	}
	
	cout<<res<<endl;
    return 0;
} 
