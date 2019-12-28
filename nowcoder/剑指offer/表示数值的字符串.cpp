/*
��ʾ��ֵ���ַ���

��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��      
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/

#include<cstdio>
#include<string>
using namespace std;

/* 
������ֿ����ж��������
	1.����  
	2.�����ŵ�����
	3.С��
	4.�����ŵ�С��
	5.��ѧ��ʾ��
	6.�����ŵĿ�ѧ��ʾ��
	7.�����ź�С���Ŀ�ѧ��ʾ�� 

���Խ�һ������Ϊ��
	1.�����ţ�����
	2.�����ţ����� . ���� 
	3. �����ţ����� . 
	4. . ����
	5.�����ţ����� E|e �����ţ����� 
 	6. �����ţ����� . ����  E|e �����ţ����� 
 	
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
        if(point_index!=-1){ //��С���� 
         	return isInteger(s.substr(0,point_index),1) && isInteger(s.substr(point_index+1),0);
		}
		if(E_index!=-1){ //����Ȼ����
			if(E_index==0 || E_index+1==s.length()) return false;
		 	return isInteger(s.substr(0,E_index),1) && isInteger(s.substr(E_index+1),1);
		} 
        return isInteger(s,1);
    }
    
    bool isInteger(string str, int canSign){
    	int i=0;
		if(str[0]=='-'||str[0]=='+'){ //�ַ����з��� 
    		if(canSign==0) return false;
    		i=1; //��ȥ����λ 
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
