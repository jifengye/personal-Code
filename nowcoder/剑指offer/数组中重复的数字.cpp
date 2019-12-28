/*
�������ظ�������

��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��

*/
#include<set>
#include<iostream>
using namespace std;

/*** ��ϣ���� ***/ 
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> s;
        for(int i=0; i<length; ++i){
        	if(s.find(numbers[i])==s.end()) s.insert(numbers[i]); //�Ҳ��� 
        	else{ //�ҵ��� 
        		*duplication = numbers[i];
        		return true;
        	}
        }
        return false;
    }
};

int main(){
	class Solution solu;
	int* d = new int(); 
	int numbers[] = {2,1,2,2,3,3};
	solu.duplicate(numbers, 6, d);
	printf("%d\n", *d);
	return 0;
}
