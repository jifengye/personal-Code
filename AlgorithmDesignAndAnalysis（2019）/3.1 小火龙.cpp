/*
�㷨�������� 3.1 С����
����Ŀ����
����N����Ʒ����д��ۣ���i����Ʒ���ۺ�ļ۸�ΪCi��ԭ��ΪVi���ӵ�Ti�쿪ʼ���ۣ�ÿ����Ʒ�޹�һ����
����˿�����ʱ�����ڵ�Ti�죬���޷����������Ʒ��
��������֪����������ֻ�ڵ�X�����Y��Ǯȥһ�γ��У������Թ���ԭ���ܺ�Ϊ���ٵ���Ʒ��

�������ʽ
��һ�а�������������N��M����ʾ��N����Ʒ���д�������M������ѯ�ʡ�
��������N�У�ÿ�а�������������Ci, Vi, Ti, �ֱ��ʾÿ����Ʒ���ۺ�ۣ�ԭ�ۣ� �Ϳ��Ź�������ڡ�
��������M�У�ÿ�а�������������Xi��Yi����ʾ����֪����Xi�����Yiȥ�����������ԭ���ܺͶ��ٵ���Ʒ��

�������ʽ
�������M�У�ÿ��һ����������ʾ��Ӧ�Ĺ���ƻ�����������ԭ���ܺ͡�

����������
5 2
5 5 4
1 3 1
3 4 3
6 2 2
4 3 2
3 8
5 9
���������
10
12
*/

/*
��̬�滮�㷨

ÿһ�ι���ѯ�ʽ���һ�ζ�̬�滮���ҳ����Ž�

����Ʒ��ѯ��ͳһ�������򣬰�ʱ������ 

���￼�����ݵĴ�С�� Ci,Yi<=109, Vi<=300
��˽����õ� maxF[i][c] ��Ϊ minF[i][v]

��������ı��Ҫ�ڸ��µڶ��� 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int ti, ci, vi, yi, i, type;
	Node() {}
	Node(int c, int v, int t):ci(c), vi(v), ti(t), type(0) {} //������Ʒ 
	Node(int x, int y): ti(x), yi(y), type(1) {}//����ѯ�� 
	bool operator < (const Node &b) const {return ti==b.ti ? type<b.type : ti<b.ti;} //��ʱ�䣬�ڵ��������� 
}node[100301]; 

int Vans=0;
long F[100000]; //��ֵ --> ����
int res[100001]; 

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	
	int c,v,t;
	for(int i=0; i<N; ++i){
		scanf("%d%d%d",&c, &v, &t);
		node[i] = Node(c, v, t); //������Ʒ
		Vans += v;
	}
 	
 	int x,y;
	for(int i=0; i<M; ++i){
		scanf("%d%d",&x, &y);
		node[i+N] = Node(x, y); //����ѯ�� 
		node[i+N].i = i;
	}
 	
 	sort(node, node+N+M); //��ʱ�䣬�ڵ��������� 
 	
	memset(F, 0x3f, sizeof(F)); F[0]=0;
	for(int i=0; i<N+M; ++i){
		if(node[i].type==0){ //����Ʒ������F
			for(int v=Vans; v>=node[i].vi; --v) F[v] = min(F[v],F[v-node[i].vi]+node[i].ci);
			for(int v=Vans; v>=0; --v) F[v]=min(F[v], F[v+1]); //�ص㣬�ٸ���һ�顣��Ȼ����F[v+1]�ܻ��V+1��ֵ����ôv��ֵҲ�϶����� 
		} 
		else{
			res[node[i].i] = upper_bound(F, F+Vans, node[i].yi)-F-1;  //�ҵ��˻���������ֵ��F���Ͻ�λ��v) 
		}
	}
	
	for(int i=0; i<M; ++i){
		printf("%d\n", res[i]);
	}
	return 0; 
}
