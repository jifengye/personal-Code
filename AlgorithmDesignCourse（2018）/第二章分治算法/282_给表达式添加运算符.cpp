/* ��Ŀ��282. �����ʽ��������
 * Ҫ�� ����һ������������ 0-9 ���ַ�����һ��Ŀ��ֵ��������֮����Ӷ�Ԫ�����������һԪ��+��- �� * �����������ܹ��õ�Ŀ��ֵ�ı��ʽ��
 * ��Դ��https://leetcode-cn.com/problems/expression-add-operators/description/ 
 * ʱ�䣺2018-11-17
 */
 
/*
	�����ַ��������ַ�֮������������� +��-��*������������
	������Щ�������ȼ���һ����ʹ������ӣ� ���������� > * > +/- 
	
	������ 
		ʹ��dfs˼�룬���������б��ʽ
		������ʽֵ����������Ŀ��ֵ�ı��ʽ 
		
		������һ�����ӳ������ݷ�Χ ��int�͸�Ϊlong�ͻ��ǲ��� 
*/
//#include <stack>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//private:
//	int targetval;
//	vector<string> expr;
//	
//	int cal(int left, int right, char oper){
//		switch (oper){
//		case '+':
//			return left + right;
//			break;
//		case '-':
//			return left - right;
//			break;
//		case '*':
//			return left * right;
//			break;
//		}
//	}
//	int getPriority(char c){
//		switch (c){
//		case '+':
//		case '-':
//			return 1;
//			break;
//		case '*':
//			return 2;
//			break;
//		default:
//			return -1;
//			break;
//		}
//	}
//	
//	void dfs(string &num, string tmp, int id) {
//		if( id==num.length() ) {
//			expr.push_back(tmp);
//			return;
//		}
//		
//		if(id==0)
//			dfs(num, tmp+num[id], id+1);
//		else {
//			dfs(num, tmp+"+"+num[id], id+1);
//			dfs(num, tmp+"-"+num[id], id+1);
//			dfs(num, tmp+"*"+num[id], id+1);
//			if(tmp[tmp.length()-1]=='0'&&(tmp.length()==1||tmp[tmp.length()-2]=='+'||tmp[tmp.length()-2]=='-'||tmp[tmp.length()-2]=='*')) return; //���ܳ���00*0��1*05����� 
//			dfs(num, tmp+num[id], id+1);
//		}
//	}
//	
//	int calculate(string &exp) {
//		stack<int> numStack; //����ջ
//		stack<char> operatorStack; //������ջ
//		for (int i=0; i<exp.length(); i++){
//			//����ֱ����ջ
//			if (exp[i]>='0' && exp[i]<='9'){
//				int tmp = exp[i] - '0';
//				while (i+1<exp.length() && exp[i+1]>='0' && exp[i+1]<='9'){ //�ж��Ƿ�Ϊ��λ��
//					tmp = tmp*10 + (exp[++i]-'0');
//				}
//				numStack.push(tmp);
//			}
//			else if (operatorStack.empty()) //ջΪ��ֱ����ջ
//				operatorStack.push(exp[i]);
//			else if (getPriority(operatorStack.top()) >= getPriority(exp[i])){//ջ�����������ȼ� >= ��ǰ������,������ʽֵ
//				int rNum = numStack.top(); numStack.pop();
//				int lNum = numStack.top(); numStack.pop();
//				char oper = operatorStack.top(); operatorStack.pop();
//				numStack.push( cal(lNum, rNum, oper) );
//				i--; //exp[i]��û����
//			}
//			else //ջ�����������ȼ� < ��ǰ������,ֱ����ջ
//				operatorStack.push(exp[i]);
//		}
// 
//		//�ַ���������ϣ���ջ�����ձ��ʽ��ֵ
//		while (!operatorStack.empty()){
//			int rNum = numStack.top(); numStack.pop();
//			int lNum = numStack.top(); numStack.pop();
//			char oper = operatorStack.top(); operatorStack.pop();
//			numStack.push( cal(lNum, rNum, oper) );
//		}
//		return numStack.top();//������Ԫ�ظ�������1����ʾ���ʽ�Ƿ�
//	}
//
//public:
//    vector<string> addOperators(string num, int target) {
//    	if(num.length()==0) return {};
//    	
//        dfs(num, "", 0);
//        
//        vector<string> result; 
//        for (auto e:expr) {
//        	if(calculate(e)==target)
//        		result.push_back(e);
//		}        
//        return result;
//    }
//};
//
//void output(vector<string> str){
//	for(auto e:str)
//		cout << e << endl;
//}
//
//int main() {
//    Solution solu;
//    string nums = "000";
//    int target = 0;
//    output(solu.addOperators(nums, target));
//    return 0;
//} 









/**
	�����㷨�����������⻮��Ϊ���������
		���磺0000		0+��		0+0+�� 
									0+0-��
									0+0*��		  
						0-��		0-0+��
									0-0-��
									0-0*��
						0*�� 		....
*/
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    void dfs(string& num, int& target, int pos, string& exp, int len, long prev, long curr, vector<string> &result) {    
        if (pos == num.length() && curr == target) {      
            result.push_back(exp.substr(0, len));
            return;
        }

        long tmp = 0;
        int s = pos;
        int l = len;
        if (s != 0) ++len;    
        while (pos < num.size()) {      
            tmp = tmp*10 + (num[pos]-'0');
            if (num[s]=='0' && pos!=s) break; //���ܳ���00*0��1*05����� 
            if (tmp>INT_MAX) break; //nֵ̫�� 
            exp[len++] = num[pos++];
            if (s == 0) {
                  dfs(num, target, pos, exp, len, tmp, tmp, result);
                  continue;
            }
            exp[l] = '+'; 
			dfs(num, target, pos, exp, len, tmp, curr+tmp, result);
            exp[l] = '-'; 
			dfs(num, target, pos, exp, len, -tmp, curr-tmp, result);
            exp[l] = '*'; 
			dfs(num, target, pos, exp, len, prev*tmp, curr-prev+prev*tmp, result);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string exp(num.length() * 2, '\0');    
        dfs(num, target, 0, exp, 0, 0, 0, result);
        return result;
    }
};

void output(vector<string> str){
	for(auto e:str)
		cout << e << endl;
}

int main() {
    Solution solu;
    string nums = "000";
    int target = 0;
    output(solu.addOperators(nums, target));
    return 0;
} 
