#include<stdio.h>  
#include<string.h>  
#include<math.h>  
int main( )  
{     char  s[205];  
      int  i,n;  
      __int64 minsum=0,maxsum=1,temp;  
      gets(s);  
      n=strlen(s);  
      for(i=0,temp=0;i<n;i+=2)  
      {     if(i+1<n && s[i+1]=='+')      
            {       temp+=(s[i]-'0');  
                    continue;  
            }  
            if(temp>0)  
            {       maxsum*=(temp+(s[i]-'0'));  
                    temp=0;continue;  
            }  
            maxsum*=(s[i]-'0');  
            if(maxsum>=870764322)    
                   maxsum=maxsum%870764322;  
      }  
      for(i=0,temp=1;i<n;i+=2)  
      {     if(i+1<n && s[i+1]=='*')      
            {       temp*=(s[i]-'0');  
                    if(temp>=870764322)    
                            temp=temp%870764322;  
                    continue;  
            }  
            if(temp>1)  
            {       minsum+=(temp*(s[i]-'0'));  
                    if(minsum>=870764322)    
                         minsum=minsum%870764322;  
                    temp=1;continue;  
            }  
            minsum+=(s[i]-'0');  
            if(minsum>=870764322)    
                      minsum=minsum%870764322;  
      }  
      printf("%I64d\n%I64d\n",maxsum%870764322,minsum%870764322);  
      return 0;  
}  
//是大写的i不是l;