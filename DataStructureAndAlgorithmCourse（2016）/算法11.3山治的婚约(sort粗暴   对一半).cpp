#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10001;
const int MAX=99999999;
struct Monkey
{
	int point;
	int dis;
	int init;
}m[N];

bool cmp(const struct Monkey &a,const struct Monkey &b)
{
	if(a.point==b.point)  return a.init<b.init;
	return a.point<b.point;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
	    scanf("%d%d",&m[i].point, &m[i].dis);
	    m[i].init=m[i].point;
	}
	sort(m,m+n,cmp);
	for(i=0;m[1].point!=MAX;i++)
	{
		m[0].point=MAX;
		m[1].point+=m[1].dis;
		sort(m,m+n-i,cmp);
	}
	cout<<m[0].point<<endl;
	return 0;
}
/*
6
1 6
2 3
4 5
3 2
5 4
14 5
output 19

8
1 1
2 2
6 6
3 3
5 5
4 4
7 7
8 8
output 24
*/
