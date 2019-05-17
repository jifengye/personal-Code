#include<iostream>
#include<string>
using namespace std;
int main()
{   int n,m,life[505],i,j,k;
    string opt;
    cin>>n>>m;
     for(i=0;i<n;i++)  cin>>life[i];
     while(m--)
     {    cin>>opt>>k;
          if(opt=="add")
                life[n++]=k;
          else if(opt=="del")
                {--n;for(j=k;j<n;j++)  life[j]=life[j+1];}
          else if(opt=="cge")
                cin>>life[k];
          else
                cout<<life[k]<<endl;
     }
     return 0;
}

/*
看清楚塔的编号是a0,a1,a2........an-1,注意取位置k取值
*/