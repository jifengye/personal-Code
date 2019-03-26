/* 22. ��������
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 * ���� n �����������ŵĶ������������п��ܵĲ�����Ч��������ϡ�
 * ����:3
 * ���:["((()))","(()())","(())()","()(())","()()()"]
 * 2018/10/12
 */
 
 
/* ����
	for (auto e1 : p1) {
		for (auto e2 : p2) {
			result.push_back("(" + e1 + ")" + e2);
		}
 * n=1ʱ���ŵ��� (0,0) ,��˼��p1Ϊn=0��������ϣ�p2Ϊn=0���������
 * n=2ʱ���ŵ��� (0,1) + (1,0) ,��˼��p1Ϊn=0��������ϣ�p2Ϊn=1��������� + p1Ϊn=1��������ϣ�p2Ϊn=0���������
 * n=3ʱ���ŵ��� (0,2) + (1,1) + (2,0)
 * n=4ʱ���ŵ��� (0,3) + (1,2) + (2,1) + (3,0)
 */ 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0) {
			result.push_back("");
			return result;
		}
		for (int right = 1; right < 2 * n; right += 2) {
			//����right���ֳ����������֣��ֱ𷵻������� 
			auto p1 = generateParenthesis(right - 1 >> 1);
			auto p2 = generateParenthesis(2 * n - right - 1 >> 1);
			//���� 
			for (auto e1 : p1) for (auto e2 : p2)
					result.push_back("(" + e1 + ")" + e2);
		}
		return result;
	}
};

void output(vector<string> str){
	for(auto elem : str) cout << elem << endl;
}

int main(){
	Solution solu;
	output(solu.generateParenthesis(3));
	return 0;
}





//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        int l = 0, i = 0;
//        vector<string> ans;
//        string temp(2*n, ' ');
//        while (i>=0) {
//            if (i==2*n) {
//                ans.push_back(temp);
//                i--;
//            }
//            switch (temp[i]) {
//                case ' ':
//                    temp[i] = '(';
//                    if (l<n) {
//                        i++;
//                    }
//                    l++;   
//                    break;
//                case '(':
//                    temp[i] = ')';
//                    l--;
//                    if (i<2*l) {
//                        i++;
//                    }
//                    break;
//                case ')':
//                    temp[i] = ' ';
//                    i--;
//                    break;
//            }
//        }
//        return ans;
//    }
//};
//
//void output(vector<string> str){
//	for(auto elem : str) cout << elem << endl;
//}
//
//int main(){
//	Solution solu;
//	output(solu.generateParenthesis(3));
//	return 0;
//}
