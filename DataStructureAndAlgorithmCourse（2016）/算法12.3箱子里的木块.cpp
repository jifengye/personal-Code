//算法12.3箱子里的木块 
#include<iostream>
using namespace std;
const int N=30001;
int f[N],d[N];

int findroot(int a)
{
	if(f[a]>0)
	{
		int temp=f[a];
		f[a]=findroot(f[a]);
		d[a]=d[a]+d[temp];
	}
	if(f[a]<0)  return a;
	return f[a];
}

int main()
{
	int n,T,i,a,b,alow,blow,atop,btop;
	char opt;
	cin>>n>>T;
	for(i=1; i<=n; i++)
	{
		f[i]=-i;
		d[i]=0;
	}
	
	while(T--)
	{
		cin>>opt;
		if(opt=='M')
		{
			cin>>a>>b;
			atop=findroot(a);
			btop=findroot(b);
			alow=-f[atop];
			blow=-f[btop];
			
			findroot(blow); //保证blow的d正确
			f[atop]=btop;
			d[atop]=d[blow]+1;
			f[btop]=-alow;
		}
		if(opt=='C')
		{
			cin>>a;
			findroot(a); //保证a的d值正确
			cout<<d[a]<<endl;
		}
	}
	return 0;
}
/*
input
6 6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
out
1
0
2

input
10 100
M 3 1
M 3 2
M 4 1
M 4 5
M 6 4
M 10 8
M 9 7
M 9 5
C 9
C 1
C 5
*/