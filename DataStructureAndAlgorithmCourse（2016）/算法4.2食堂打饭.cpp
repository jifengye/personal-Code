#include<iostream>
#include<string>
#define MAX(a,b)  a>b?a:b
using namespace std;
int main( )
{     int  hunger[100005],p1=0,p2=0,temp=0;
      bool flag=true; //flag为真表示当前temp真的是最大值，flag为假表示最大值已OUT，要重新找
      string  opt;
      cin>>opt;
      while(opt!="END")
      {     if(opt=="IN")   
            {    cin>>hunger[p2];
                 if(flag)    temp=MAX(hunger[p2],temp);
                 p2++;
            }
            
            if(opt=="OUT")   
            {    if(p1<p2)
                 {   if( hunger[p1]==temp)  flag=false;
                     p1++;
                 }
            }
            
            if(opt=="QUERY")
            {    if(p1==p2)    cout<<"-1"<<endl;
                 else
                 {      if(!flag)
                        {   temp=0;
                            for(int i=p1;i<p2;i++)
                               temp=MAX(hunger[i],temp);
                             flag=true;
                        }
                        cout<<temp<<endl;
                  }
            }
            cin>>opt;
      }
      return 0;
} 

/*
输入
IN 100
IN 200
QUERY
OUT
QUERY
END

输出
200
200




输入
QUERY
IN 10001000
IN 10
OUT
QUERY
IN 20
QUERY
END

输出
-1
10
20



输入
QUERY
IN 25625
OUT
OUT
OUT
QUERY
IN 7338
OUT
OUT
IN 11509
OUT
IN 10156
IN 32359
OUT
QUERY
OUT
OUT
OUT
IN 21831
IN 17401
QUERY
END

输出
-1
-1
32359
21831
*/