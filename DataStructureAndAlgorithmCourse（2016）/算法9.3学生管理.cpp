//9.3学生管理
//姓名不一定是a~z 
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=199999;
const int M=100002;
int h[N+5]={0};
int ant;
char name[M+5][6];
int p=0;

int main( )
{
	int n,i,j,k,opt;
	char c[6];
	cin>>n;
	strcpy(name[M],"&&&&&");//代替删除者
	while(n--)
	{
		cin>>opt>>c;
		ant=0;
	    for( i=0; i<strlen(c); i++) 
		    ant=(ant+c[i]*200+N)%N;
		switch(opt){
		case 1:
		    for(j=ant;h[j]!=0&&strcmp(name[h[j]],c)!=0;j=(j+1)%N);
		    if(h[j]==0)  {strcpy(name[++p],c);h[j]=p;}
		    break;
		case 2:
		    for(j=ant;h[j]!=0&&strcmp(name[h[j]],c)!=0;j=(j+1)%N);
		    if(h[j]!=0)  h[j]=M;
		    else  cout<<"The student does not exist!"<<endl;
		    break;
		case 3:
		    for(j=ant;h[j]!=0&&strcmp(name[h[j]],c)!=0;j=(j+1)%N);
		    if(h[j]==0) cout<<"No"<<endl;
		    else cout<<"Yes"<<endl;
		}
    }
    return 0;
}
/*
7
1 xx
1 xx
3 xx
2 aaa
2 xx
3 xx
2 xx

100
1 65
2 a
*/

/*
input
5
1 xx
3 xx
2 aaa
2 xx
3 xx

input

*/
