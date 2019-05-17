//9.3学生管理(数组实现邻接表)
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100001
using namespace std;
int head[N],Next[N],p=0;
char name[N][6];

int main( )
{	
     memset(head,-1,sizeof(head));	
     memset(Next,0,sizeof(Next));	
     int n,opt,ans,i,t;	
     char s[6];	
     cin>>n;	
     while(n--)
     {		
           cin>>opt>>s;
           ans=0;
           for(i=0;i<strlen(s);i++)
               ans=(ans+s[i]*128)%N;
           switch(opt){
           case 1:
               for(i=head[ans];i!=-1&&strcmp(s,name[i])!=0;i=Next[i]) ;
               if(i==-1)
               {
               	  strcpy(name[p],s);
               	  Next[p]=head[ans];
               	  head[ans]=p++;
               }
               break;
           case 2:
           for(i=head[ans];i!=-1&&strcmp(s,name[i])!=0;i=Next[i]) t=i;
               if(i==-1)  cout <<"The student does not exist!"<< endl;			
               else 
               {    
                     if(i==head[ans])   head[ans]=Next[i];
               	  else   Next[t]=Next[i];
               }
               break;
           case 3:
               for(i=head[ans];i!=-1&&strcmp(s,name[i])!=0;i=Next[i]) ;
               if(i==-1)   cout<< "No" << endl;
               else  cout<< "Yes" << endl;
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