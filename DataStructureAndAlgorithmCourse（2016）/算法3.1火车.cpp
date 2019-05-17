#include<iostream>
#include<cstring>
using namespace std;
int main( )
{     int  book[25],n,p=-1,k=0,j=0;
      char inorder[11],outorder[11];
      cin>>n>>inorder>>outorder;
      for(int i=0;i<n;i++)   
      {       book[++p]=1; //用book数组记录进站出站，1是进站、0是出站。
               if(inorder[i]==outorder[j])
               {      book[++p]=inorder[i]=0; //inorder归0用于标记该位置火车出站了
                       k=i-1;j++;
                       while(!inorder[k])  k--;
               }
              while(k>=0&&inorder[k]==outorder[j]) 
              {      book[++p]=inorder[k]=0;
                      j++;
                      while(!inorder[k])  k--;
               }
       }
      if(p<2*n-1)   {cout<<"No"<<endl;return 0;}
      cout<<"Yes"<<endl;
      for(int z=0;z<=p;z++)
      {      if(book[z])     cout<<"in"<<endl;
             else   cout<<"out"<<endl;
      }
      return 0;
}

/*
5
12345
24315
*/