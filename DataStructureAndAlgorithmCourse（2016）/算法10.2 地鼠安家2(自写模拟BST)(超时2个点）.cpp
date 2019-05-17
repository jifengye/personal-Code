//算法10.2地鼠安家(自写模拟BST) 
#include<stdio.h>
struct Node
{
	int l;
	int r;
	int h;
}home[10001];
int head;

void creat(int pp,int a)
{
	if(a<pp)
	{
		if(home[pp].l==0)
		{
			home[pp].l=a;
			home[a].l=home[a].r=0;
			home[a].h=home[pp].h+1;
		}
		else
            creat(home[pp].l,a);
		
	}
	else
	{
		if(home[pp].r==0)
		{
			home[pp].r=a;
			home[a].l=home[a].r=0;
			home[a].h=home[pp].h+1;
		}
		else
		    creat(home[pp].r,a);
	}
}

int main()
{
	int n,i,x;
	scanf("%d%d",&n,&head);
	home[head].l=home[head].r=0;
	home[head].h=1;
	
	for(i=1; i<=n-1; i++)
	{
		scanf("%d",&x);
		creat(head,x);
	}
	
	for(i=1; i<n; i++)
	    printf("%d ",home[i].h);
	printf("%d\n",home[i].h);
	return 0;
}
/*
input
5
4 2 1 3 5
output
3 2 3 1 2

input
3
1 3 2
output
1 3 2
*/
