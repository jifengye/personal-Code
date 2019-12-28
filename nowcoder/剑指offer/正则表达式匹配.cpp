/*
正则表达式匹配

请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/*
str = "aaaaas"
pattern = "a*s*"

str="aaa";
pattern=".*"

str = "aaa"
pattern = "a*a"

str = "aaaa"
pattern = "a*aaaa"
*/
#include<stdio.h>


/* 只有正确了66% */
//class Solution {
//public:
//    bool match(char* str, char* pattern) {
//    	char *next_p=pattern;
//    	for(char *s=str; *s!='\0'; s++ ){
//			if(*next_p=='\0') return false;
//			
//			char *cur_p = next_p++;
//			if(*cur_p=='.' && *next_p=='*'){
//				//任意匹配，不前进
//				--next_p;
//			}			
//			else if(*cur_p=='.') {
//				//匹配为.，前进一位 
//			}
//			else if(*cur_p==*s && (*next_p=='\0'||*next_p!='*')) {
//				//匹配本身字符，前进一位 
//			}
//			else if(*cur_p==*s && *next_p=='*') {
//				//匹配本身无数次字符，不前进 
//				--next_p; 
//			}
//			else if(*cur_p!=*s && *next_p=='*'){
//				//不匹配，前进两位 
//				++next_p;
//			}
//			else{
//				return false;	
//			}
//		}
//		if(*next_p=='\0') return true;
//		if(*next_p=='*') ++next_p;
//		while(*next_p!='\0'){
//			char *cur_p = next_p++;
//			if(*next_p!='*') return false;
//			else ++next_p;	
//		}
//		return true;
//    }
//};

/* 正解是使用递归思想 
	匹配的方案可能会有多个， 而正确的是其中一种，例如：aaa 和 aaa*a
	所以需要在当前基础上尝试所有可能的方案 
*/
class Solution {
public:
    bool match(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0') return true; //str到尾，pattern到尾，匹配成功
		if(*str != '\0' && *pattern == '\0') return false; //pattern先到尾，匹配失败
 
		
        if(*(pattern+1) != '*') { //没有星号，两者都要前进一位 
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        else{ //有星号，匹配了：str前进一位pattern前进两位 或 str前进一位pattern不前进。不匹配：str不前进pattern前进两位 
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern+2) || match(str+1, pattern);
            else
                return match(str, pattern+2);
        }
    }
}; 




int main(){
	class Solution solu;
	char str[] = "aaa";
	char pattern[] = "a*a";
	printf("%d",solu.match(str, pattern));
	return 0;
} 
