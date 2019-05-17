#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main( )
{     int n,i,j,firm=-1,k=-1;
      string str[10005],temp;
       cin>>n;
       while(n--)
       {      cin>>temp;
              if(temp=="input")   
                    {cin>>str[++k];firm=k;}
             if(temp=="ctrl+z")  
                    if(k>=0)   --k;
             if(temp=="ctrl+y")
                    if(k<firm)   ++k;
       }
       if(k==-1)   cout<<"No output"<<endl;
       else 
       {      for(i=0;i<k;i++)  cout<<str[i]<<' ';
              cout<<str[i]<<endl;
       }
       return 0;
}   