#include<iostream>
#include<cstdio>
using namespace std;
int f[50001],d[50001];//f[i]表示i的父亲结点,d[i]表示i到根节点的路径长度对3的余数 
int M,N,K;
/*集合的作用：集合中任意两个元素的关系皆可以确定
出现d a b，若a b不在同一个集合就是说关系不能确定，这种关系就是首次出现他是真的，就可以合并两个集合了 
*/
 
int root(int x)
{
	if(x!=f[x])
	{
		int temp=f[x];
		f[x]=root(f[x]);//压缩路径 
		d[x]=(d[x]+d[temp])%M;//x到当前首领距离=x到父结点temp距离+父结点到当前首领距离  
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
    }//初始化 
	for(i=1; i<=K; i++)
	{
		scanf("%d%d%d",&D,&A,&B);	
		if( D>=M || A>N || B>N || (A==B&&D!=0))
		{
			count++;
			continue;
		} 
		
		if(root(A)==root(B))//A B 在一个集合中，可以判断x y关系 
		{
			if( d[A]!=(d[B]+D)%M ) count++;
		}
		else//A B 不在一个集合中,就是说前面没有出现这种情况他是真的，合并集合 
		{
			d[f[A]]=(d[B]-d[A]+D+M)%M; //将以B所在集合原首领作为合并后集合首领，A的原首领距离当前首领距离= 
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

