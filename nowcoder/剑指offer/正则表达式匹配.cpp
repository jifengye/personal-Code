/*
������ʽƥ��

��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
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


/* ֻ����ȷ��66% */
//class Solution {
//public:
//    bool match(char* str, char* pattern) {
//    	char *next_p=pattern;
//    	for(char *s=str; *s!='\0'; s++ ){
//			if(*next_p=='\0') return false;
//			
//			char *cur_p = next_p++;
//			if(*cur_p=='.' && *next_p=='*'){
//				//����ƥ�䣬��ǰ��
//				--next_p;
//			}			
//			else if(*cur_p=='.') {
//				//ƥ��Ϊ.��ǰ��һλ 
//			}
//			else if(*cur_p==*s && (*next_p=='\0'||*next_p!='*')) {
//				//ƥ�䱾���ַ���ǰ��һλ 
//			}
//			else if(*cur_p==*s && *next_p=='*') {
//				//ƥ�䱾���������ַ�����ǰ�� 
//				--next_p; 
//			}
//			else if(*cur_p!=*s && *next_p=='*'){
//				//��ƥ�䣬ǰ����λ 
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

/* ������ʹ�õݹ�˼�� 
	ƥ��ķ������ܻ��ж���� ����ȷ��������һ�֣����磺aaa �� aaa*a
	������Ҫ�ڵ�ǰ�����ϳ������п��ܵķ��� 
*/
class Solution {
public:
    bool match(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0') return true; //str��β��pattern��β��ƥ��ɹ�
		if(*str != '\0' && *pattern == '\0') return false; //pattern�ȵ�β��ƥ��ʧ��
 
		
        if(*(pattern+1) != '*') { //û���Ǻţ����߶�Ҫǰ��һλ 
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        else{ //���Ǻţ�ƥ���ˣ�strǰ��һλpatternǰ����λ �� strǰ��һλpattern��ǰ������ƥ�䣺str��ǰ��patternǰ����λ 
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
