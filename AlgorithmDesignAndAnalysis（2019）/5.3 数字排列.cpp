/*
�㷨�������� 5.3 ��������
����Ŀ����
������������A��B������ͨ����������A���С�ڻ����B����������Ƕ���(����ǰ��0)��

�������ʽ
����ĵ�һ����������A��B����֤������������int��Χ�ڡ�

�������ʽ
���A�������к�С�ڻ����B���������(����ǰ��0)�������������-1��

����������
1234 3456

���������
3421
*/ 

/*
ȫ������ prev_permutation ����ʵ�� 
*/
#include<bits/stdc++.h>
using namespace std;

string A, B;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>A>>B;
	
	sort(A.begin(), A.end(), greater<char>());
	
	string res = "";
	int lenA = A.length(), lenB = B.length();
	if(lenA<lenB){ //��������ͳͳС��B��ֻȡ�ֵ����������м��� 
		res = A;
	}
	else if(lenA==lenB){ //��Aȫ���� 
		do{
			if(A.front()=='0') break; //����ǰ��0
			if(A<=B) res=max(res, A);
		}while(prev_permutation(A.begin(), A.end()));	
	}
	
	res=="" ? cout<<"-1"<<endl : cout<<res<<endl;
	return 0;
} 
