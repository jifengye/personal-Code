/* 题目：282. 给表达式添加运算符
 * 要求： 给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
 * 来源：https://leetcode-cn.com/problems/expression-add-operators/description/ 
 * 时间：2018-11-17
 */
 
/*
	数字字符与数字字符之间有四种情况： +、-、*、相连不运算
	但是这些运算优先级不一样，使情况复杂： 相连不运算 > * > +/- 
	
	暴力： 
		使用dfs思想，构建出所有表达式
		计算表达式值，挑出符合目标值的表达式 
		
		但是有一个例子超出数据范围 ，int型改为long型还是不行 
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
//			if(tmp[tmp.length()-1]=='0'&&(tmp.length()==1||tmp[tmp.length()-2]=='+'||tmp[tmp.length()-2]=='-'||tmp[tmp.length()-2]=='*')) return; //不能出现00*0、1*05的情况 
//			dfs(num, tmp+num[id], id+1);
//		}
//	}
//	
//	int calculate(string &exp) {
//		stack<int> numStack; //数字栈
//		stack<char> operatorStack; //操作符栈
//		for (int i=0; i<exp.length(); i++){
//			//数字直接入栈
//			if (exp[i]>='0' && exp[i]<='9'){
//				int tmp = exp[i] - '0';
//				while (i+1<exp.length() && exp[i+1]>='0' && exp[i+1]<='9'){ //判断是否为多位数
//					tmp = tmp*10 + (exp[++i]-'0');
//				}
//				numStack.push(tmp);
//			}
//			else if (operatorStack.empty()) //栈为空直接入栈
//				operatorStack.push(exp[i]);
//			else if (getPriority(operatorStack.top()) >= getPriority(exp[i])){//栈顶操作符优先级 >= 当前操作符,计算表达式值
//				int rNum = numStack.top(); numStack.pop();
//				int lNum = numStack.top(); numStack.pop();
//				char oper = operatorStack.top(); operatorStack.pop();
//				numStack.push( cal(lNum, rNum, oper) );
//				i--; //exp[i]还没处理
//			}
//			else //栈顶操作符优先级 < 当前操作符,直接入栈
//				operatorStack.push(exp[i]);
//		}
// 
//		//字符串遍历完毕，求栈中最终表达式的值
//		while (!operatorStack.empty()){
//			int rNum = numStack.top(); numStack.pop();
//			int lNum = numStack.top(); numStack.pop();
//			char oper = operatorStack.top(); operatorStack.pop();
//			numStack.push( cal(lNum, rNum, oper) );
//		}
//		return numStack.top();//若最终元素个数不是1，表示表达式非法
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
	分治算法，把整体问题划分为多个子问题
		例如：0000		0+子		0+0+子 
									0+0-子
									0+0*子		  
						0-子		0-0+子
									0-0-子
									0-0*子
						0*子 		....
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
            if (num[s]=='0' && pos!=s) break; //不能出现00*0、1*05的情况 
            if (tmp>INT_MAX) break; //n值太大 
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
