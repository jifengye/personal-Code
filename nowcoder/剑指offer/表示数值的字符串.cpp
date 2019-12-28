/*
表示数值的字符串

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。      
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

#include<cstdio>
#include<string>
using namespace std;

/* 
这个数字可能有多种情况：
	1.整数  
	2.带符号的整数
	3.小数
	4.带符号的小数
	5.科学表示法
	6.带符号的科学表示法
	7.带符号和小数的科学表示法 

可以进一步归纳为：
	1.（符号）整数
	2.（符号）整数 . 整数 
	3. （符号）整数 . 
	4. . 整数
	5.（符号）整数 E|e （符号）整数 
 	6. （符号）整数 . 整数  E|e （符号）整数 
 	
*/
class Solution {
public:
    bool isNumeric(char* str) {
    	string s = str;
        int point_index = s.find('.');
        int E_index = s.find('e')!=-1 ? s.find('e') : s.find('E');
        
        if(point_index!=-1 && E_index!=-1 && point_index<E_index){
        	if(E_index+1==s.length()) return false;
        	return isInteger(s.substr(0,point_index),1) && isInteger(s.substr(point_index+1, E_index-point_index-1),0) && isInteger(s.substr(E_index+1),1);
		}
        if(point_index!=-1){ //有小数点 
         	return isInteger(s.substr(0,point_index),1) && isInteger(s.substr(point_index+1),0);
		}
		if(E_index!=-1){ //有自然常数
			if(E_index==0 || E_index+1==s.length()) return false;
		 	return isInteger(s.substr(0,E_index),1) && isInteger(s.substr(E_index+1),1);
		} 
        return isInteger(s,1);
    }
    
    bool isInteger(string str, int canSign){
    	int i=0;
		if(str[0]=='-'||str[0]=='+'){ //字符串有符号 
    		if(canSign==0) return false;
    		i=1; //擦去符号位 
		} 
		for(; i<str.length(); ++i){
			if(str[i]<'0'||str[i]>'9') return false;
		} 
		return true;    	
	} 
};

int main(){
	class Solution solu;
	char s[]="1e";
	printf("%d\n",solu.isNumeric(s)); 
}
