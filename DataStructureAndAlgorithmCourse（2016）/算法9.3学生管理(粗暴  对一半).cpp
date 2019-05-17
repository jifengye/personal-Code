#include<iostream>
#include<string>
using namespace std;
string name[100001];
int main( )
{
	int n,i,opt,m=0;
	string c;
	cin>>n;
	while(n--)
	{
		cin>>opt>>c;
		switch(opt){
		case 1:
		     for(i=1;i<=m&&name[i]!=c;i++);
		     if(i==m+1)   {name[i]=c; m++;}
		     break;
		 case 2:
		     for(i=1;i<=m&&name[i]!=c;i++);
		     if(i<=m)  name[i]="&&&&&";
		     else cout<<"The student does not exist!"<<endl;
		     break;
		  case 3:
		     for(i=1;i<=m&&name[i]!=c;i++);
		     if(i>m)  cout<<"No"<<endl;
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