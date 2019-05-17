//�㷨7.4����Ϸ������ (kruskal�㷨) 
#include<cstdio>
#include<algorithm>
using namespace std; 
const int MAX=500001;

struct Rode
{
    int a,b,d;
}R[MAX];
int f[MAX]; //���ڲ��鼯�����������·�����ӹ鲢��һ�������� 

int root(int x)
{
	if(x!=f[x])  f[x]=root(f[x]);//ѹ��·�� 
	return f[x];
}

int cmp(Rode x,Rode y)
{
    return x.d<y.d;
}

int main( )
{
	int n,m,i;
	scanf("%d%d",&n, &m);
	for(i=0; i<=n; i++) f[i]=i; //��ʼ����n����ֳ�n������ 
	for(i=0; i<m;  i++)
		scanf("%d%d%d",&R[i].a, &R[i].b, &R[i].d);
		
	sort(R, R+m, cmp); //�����룬��С�������� 
	
	int aroot,broot,sum=0,time=0; 
	for(i=0; i<m; i++)
    {
    	aroot=root(R[i].a); //��a�㼯�ϵ����� 
    	broot=root(R[i].b);

    	if(aroot==broot) continue; //a b��һ������˵���Ѿ������·�������������� 
		
		sum+=R[i].d; time++;  //a b����һ�����ϣ� 
		f[aroot]=broot;
    }
    printf("%d\n",sum);
    return 0;
}
/*
5 6
1 2 1
2 3 2 
1 3 3 
2 4 3
3 4 5
1 4 4
*/ 
