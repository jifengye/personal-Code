#include<iostream>
using namespace std;
int f[101];  //朋友关系friend, a的朋友是f[a];  
int e[101][101];  //敌人关系enemy, e[a][b]=e[b][a]=1; 

int findroot(int a)  //找朋友圈的首领root 
{
	int i=a,root,temp;
	while(f[i]!=i) i=f[i];  
	root=i; 
	
	i=a;
	while(i!=root)
	{
		temp=f[i];
		f[i]=root;  
		i=temp;
	} //路径压缩 
	
	return root; 
}

int main() 
{   
    int i,n, m, k, x, y, opt;
    cin>>n>>m>>k;

    for(i=1; i<=n; i++) f[i]=i;
    for(i=1; i<=m; i++) 
	{
        cin>>x>>y>>opt;
        if(opt==1)
            f[findroot(y)]=findroot(x);
        else
            e[x][y]=e[y][x]=1;
    }
    
    for(i=1; i<=k; i++) 
	{
        cin>>x>>y;
        if(findroot(x)==findroot(y) && e[x][y]==0)       cout<<"Good job"<<endl;
        else if(findroot(x)!=findroot(y) && e[x][y]==0)  cout<<"No problem"<<endl;
        else if(findroot(x)==findroot(y) && e[x][y]==1)  cout<<"OK but..."<<endl;
        else if(findroot(x)!=findroot(y) && e[x][y]==1)  cout<<"No way"<<endl;
    }
    return 0;
}
/*
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
*/ 
