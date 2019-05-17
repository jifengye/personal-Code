#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int barrel[12356631];

int main( )
{     char temp[6];
      int n,m,count=0,index,i;
      memset(barrel,0,12356631);
      cin>>n>>m;
      while(n--)
      {    cin>>temp;
            for(i=strlen(temp)-1,index=0;i>=0;i--)
                        index=index*26+(temp[i]%32);
            //cout<<"index"<<index<<endl;
            barrel[index]=1;
      }
      while(m--)
      {    cin>>temp;
            for(i=strlen(temp)-1,index=0;i>=0;i--)
                        index=index*26+(temp[i]%32);
            if(barrel[index])  count++;
      }
      cout<<count<<endl;
      return 0;
}
/*
input
3 2
Tom
Alice
Jack
Jack
Ted
output
1

input

*/