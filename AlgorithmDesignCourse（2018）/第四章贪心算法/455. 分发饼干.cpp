/*
455. �ַ�����
ÿ���������ֻ�ܸ�һ����ɡ�
��ÿ������ i ������һ��θ��ֵ gi ���������ú���������θ�ڵı��ɵ���С�ߴ磻
ÿ����� j ������һ���ߴ� sj ��
��� sj >= gi �����ǿ��Խ�������� j ��������� i ��������ӻ�õ����㡣
�������Խ�������ĺ�����������ֵ��
*/

/*
θ�ڵı������������� 
����С���ɷ��𣬷ָ�θ����С������
�Դ˵ݽ�
�ֲ���ȥ�ı������� 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); //�������� 
		sort(s.begin(), s.end());
		
		int count = 0;
		for(int i=0,j=0; i<s.size() && j<g.size(); ) {
			if(s[i]>=g[j]){ //��ǰ���������㵱ǰ���� 
				i++;
				j++;
				count++;
			}
			else //��ǰ���ɲ������㵱ǰ���� ������һ�� 
				i++;
		}
		return count;
	}
};

int main() {
	Solution solu;
	vector<int> g = {1,2};
	vector<int> s = {1,2,3};
	cout<<solu.findContentChildren(g, s);
	return 0;
} 
