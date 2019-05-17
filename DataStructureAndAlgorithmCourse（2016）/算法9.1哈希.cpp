#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char s[1000005];
int book[56000];

int main( )
{   int index=0,lindex=0;
     int n,m,k,i,count=0;
     cin>>n>>m>>k>>s;
     for(i=0;i<k;i++)   lindex+=pow(6,i);
     //cout<<"lindex"<<lindex<<endl;
     int kpow6=pow(6,k);
     //cout<<"hindex"<<lindex+kpow6<<endl;
     memset(book,0,lindex+kpow6);

     for(i=0;i<n;i++)
     {  index=index*6+s[i]%32;
        if(index>=lindex+kpow6)
              index-=(s[i-k]%32)*kpow6;
         if(index>=lindex&&book[index]==0)
         {     book[index]=1;
                count++;
                //cout<<index<<endl;
          }
      }
     cout<<count<<endl;
     return 0;
}
/*
input
8 2 3
ababaaab
output
5

input
8 2 3
aabbaabb
output
4

input
10 2 3
aaaaabaaabaa
output
4

input
10 6 2
abcdefabcd
output
6

input
15 6 4
efafeeffffafefe
output
11

input
28 6 6
eefffeefffaafefffffeeeaeefee
output
23
*/