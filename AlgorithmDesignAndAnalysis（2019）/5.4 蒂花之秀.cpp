/*
�㷨�������� 5.4 �ٻ�֮��
����Ŀ����
��ͼΪһ��N��M�е���ͼ����ͼ��ĸ�����������һ���޷�ͨ�����ϰ���Ҳ������һ�����ָ�

���Դ���ͼ�ϵ�����һ�����ָ������ÿ������������֮һ�ķ�����һ�񣬵������ߵ��ϰ����У�Ҳ�����ظ�����һ�����ָ�

���ܲ��������ָ��յ�����ָ�;�������и��ϵ����ְ��շ���˳��������һ��õ�һ����������Ϊ�Լ�ѵ��������ָ�ꡣ

���ڸ��㺫������ѵ����ͼ�������������ŵ�ͼ���ܵõ����������ָ���Ƕ���?

�������ʽ
��������һ����T(T<=10)�������ܹ���T�����ݡ�

ÿ�����ݵ�1�а�����������N��M����ʾ��ͼΪN*M�����У�

������N��ÿ�а���M���ַ��������֡�1~9���͡�#����ɡ�

���뱣֤��ÿ����ͼ��������һ�����ָ�

�������ʽ
ÿ������һ�����������Ӧ��ͼ���ܵõ����������ָ�ꡣ

����������
1
6 3
122
789
685
7#5
941
48#
���������
9885514849767122

�����ݷ�Χ
50%�����ݣ�2<=N��M<=10��N*M<=10��
100%�����ݣ�2<=N��M<=15��N*M<=30
*/

/*
�������ƺ����Ǻܴ󣬳������ѱ���������ͼ 
*/ 

#include<bits/stdc++.h>
using namespace std;

int T,N,M;
char Map[16][16]; 
int  Vis[16][16];
int  Dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
string res,path;

void df(int x, int y){
	int end=1;
	for(int i=0; i<4; ++i){
		int nx=x+Dir[i][0], ny=y+Dir[i][1];
		if(1<=nx && nx<=N && 1<=ny && ny<=M && Vis[nx][ny]==0 && Map[nx][ny]!='#'){
			Vis[nx][ny]=1, path.push_back(Map[nx][ny]), end=0;
//			cout<<"("<<nx<<","<<ny<<")"<<path+Map[nx][ny]<<endl;
			df(nx, ny);
			Vis[nx][ny]=0, path.pop_back();
		}
	}
	if(end){
		if(path.length()>res.length()) res = path;
		else if(path.length()==res.length()) res = max(res, path);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>T;
	while(T--){
		cin>>N>>M;
		
		memset(Vis, 0, sizeof(Vis));
		memset(Map, 0, sizeof(Map));
		res="",path=""; 
		for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j) cin>>Map[i][j];
		
		for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j){
			if(Map[i][j]=='#') continue;
			Vis[i][j]=1, path.push_back(Map[i][j]);
			df(i, j);
			Vis[i][j]=0, path.pop_back();
		}
		
		cout<<res<<endl;
	}
	return 0;
} 
