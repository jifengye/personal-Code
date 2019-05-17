// ‘Ã‚“ªifelse 
#include<iostream>
#include<stack>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	stack<string>s;
	string str;
	int n,max=0,ans=0;
	scanf("%d",&n);
	while(n--)
	{
		cin>>str;
		if(str=="if")
		   s.push(str);
		else
		{
			if(!s.empty())
			{
			    if(s.size()>1) ans++;
			    else
			    {
			    	max=max>ans?max:ans;
		            ans=0;
		        }
				s.pop();
			}
			else
			{
				printf("NO\n");return 0;
			}
		}
	}
	printf("%d",max);
	return 0;
}
/*
6
if
if
else
if
else
else

4
if
else
if
else

6
if
else
if
if
else
else
*/			
	
