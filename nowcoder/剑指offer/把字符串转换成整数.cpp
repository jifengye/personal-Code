/*
���ַ���ת��������

��һ���ַ���ת����һ������
Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str=="") return 0;
        
        int sign=0;
        if(str[0]=='+') {str[0]='0'; sign=0;}
        if(str[0]=='-') {str[0]='0'; sign=1;}
        
        long long value=0;
        for(char c:str){
        	if(c<'0'||c>'9') return 0;
        	value = value*10 + (c-'0');	
        }
        return sign ? -value : value;
    }
};

int main(){
	class Solution solu;
	printf("%d\n",solu.StrToInt("123"));
	printf("%d\n",solu.StrToInt("-123"));
	printf("%d\n",solu.StrToInt("+2147483647"));
	printf("%d\n",solu.StrToInt("1a33123"));
	printf("%d\n",solu.StrToInt("12 3"));
	printf("%d\n",solu.StrToInt("1-23"));
	printf("%d\n",solu.StrToInt("1203"));
	return 0; 
} 
