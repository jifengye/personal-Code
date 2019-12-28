/*
�ַ����е�һ�����ظ����ַ�

��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/
 
/*
ʹ�ù�ϣ
���е�char�ַ�����ASCII������ܹ�128���������ֵתΪʮ���ƾ���0~127 
����������ַ������ղ����˳�򣬿ɷ���ĵõ���һ������hash���и���Ϊ1����������򷵻�#
*/
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    string str;
    char hash[128] = {0};
    void Insert(char ch) {
        str += ch;
        hash[ch]++;
    }
    
    
    char FirstAppearingOnce() {
        for(char ch : str)
            if(hash[ch] == 1) return ch;
        return '#';
    }
};

int main(){
	class Solution solu;
	string str="898";
	for(int i=0; i<str.length(); ++i){
		solu.Insert(str[i]);
	} 
	printf("%c\n",solu.FirstAppearingOnce());
	return 0;
}

