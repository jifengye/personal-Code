#include<iostream>
#include<cstdio>
using namespace std;
int f[50001],d[50001];//f[i]��ʾi�ĸ��׽��,d[i]��ʾi�����ڵ��·�����ȶ�3������ 
int M,N,K;
/*���ϵ����ã���������������Ԫ�صĹ�ϵ�Կ���ȷ��
����d a b����a b����ͬһ�����Ͼ���˵��ϵ����ȷ�������ֹ�ϵ�����״γ���������ģ��Ϳ��Ժϲ����������� 
*/
 
int root(int x)
{
	if(x!=f[x])
	{
		int temp=f[x];
		f[x]=root(f[x]);//ѹ��·�� 
		d[x]=(d[x]+d[temp])%M;//x����ǰ�������=x�������temp����+����㵽��ǰ�������  
	}
	return f[x];
}

int main() 
{
	int i,D,A,B,count=0;
	scanf("%d%d%d",&M,&N,&K);
	//scanf("%d%d",&N,&K);M=3;
	
	for(i=1; i<=N; i++)
	{
		f[i]=i;
		d[i]=0;
    }//��ʼ�� 
	for(i=1; i<=K; i++)
	{
		scanf("%d%d%d",&D,&A,&B);	
		if( D>=M || A>N || B>N || (A==B&&D!=0))
		{
			count++;
			continue;
		} 
		
		if(root(A)==root(B))//A B ��һ�������У������ж�x y��ϵ 
		{
			if( d[A]!=(d[B]+D)%M ) count++;
		}
		else//A B ����һ��������,����˵ǰ��û�г����������������ģ��ϲ����� 
		{
			d[f[A]]=(d[B]-d[A]+D+M)%M; //����B���ڼ���ԭ������Ϊ�ϲ��󼯺����죬A��ԭ������뵱ǰ�������= 
			f[f[A]]=f[B]; 				
		}
	}
	cout<<count<<endl;
	return 0; 
}
/*
3 100 7
0 101 1
1 1 2
1 2 3
1 3 3
0 1 3
1 3 1
0 5 5
*/

