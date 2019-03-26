/***
	将算式转化为后缀表达式： 
		1、从左向右读取输入的运算符 
		2、若为数字将数字写入字符串A中 
		3、若为运算符，与栈顶的运算符比较优先级 
			3-1、若栈为空或为‘（’则直接压入栈中 
			3-2、若优先级高于栈顶的直接压入到栈中 
			3-3、若优先级低或相等则将栈顶的元素弹出并放入到A中，再与新的栈顶元素比较 
		4、若为括号 
			4-1、若为（则将其直接压入到栈中 
			4-2、若为）则从栈顶开始弹出元素依次放入到A中直到遇到（并删除这对括号 
		5、重复上述步骤直到算式读完
		
		1+2*3  转为后缀表达式为  123*+ 
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
class Expression{
private:
	stack<int> numStack; //数字栈
	stack<char> operatorStack; //操作符栈

	int cal(int left, int right, char oper){
		switch (oper){
		case '+':
			return left + right;
			break;
		case '-':
			return left - right;
			break;
		case '*':
			return left * right;
			break;
		case '/':
			return left / right;
			break;
		}
	}
	int getPriority(char c){
		switch (c){
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
		default:
			return -1;
			break;
		}
	}
	
public:
	int expCal(string exp){
		stack<int> numStack; //数字栈
		stack<char> operatorStack; //操作符栈
		for (int i=0; i<exp.length(); i++){
			//数字直接入栈
			if (exp[i]>='0' && exp[i]<='9'){
				int tmp = exp[i] - '0';
				while (i+1<exp.length() && exp[i+1]>='0' && exp[i+1]<='9'){ //判断是否为多位数
					tmp = tmp*10 + (exp[++i]-'0');
				}
				numStack.push(tmp);
			}
			else if (operatorStack.empty() || exp[i]=='(') //栈为空或者遇到左括号直接入栈
				operatorStack.push(exp[i]);
			else if (exp[i] == ')'){//遇到右括号，进行出栈操作，直到遇到左括号
				while (operatorStack.top() != '(') {
					int rNum = numStack.top(); numStack.pop();
					int lNum = numStack.top(); numStack.pop();
					char oper = operatorStack.top(); operatorStack.pop();
					numStack.push( cal(lNum, rNum, oper) );
				}
				operatorStack.pop();
			}
			else if (getPriority(operatorStack.top()) >= getPriority(exp[i])){//栈顶操作符优先级 >= 当前操作符,计算表达式值
				int rNum = numStack.top(); numStack.pop();
				int lNum = numStack.top(); numStack.pop();
				char oper = operatorStack.top(); operatorStack.pop();
				numStack.push( cal(lNum, rNum, oper) );
				i--; //exp[i]还没处理 
			}
			else //栈顶操作符优先级 < 当前操作符,直接入栈
				operatorStack.push(exp[i]);
		}
 
		//字符串遍历完毕，求栈中最终表达式的值
		while (!operatorStack.empty()){
			int rNum = numStack.top(); numStack.pop();
			int lNum = numStack.top(); numStack.pop();
			char oper = operatorStack.top(); operatorStack.pop();
			numStack.push( cal(lNum, rNum, oper) );
		}
		return numStack.top();//若最终元素个数不是1，表示表达式非法
	}
};

int main()
{
	Expression exp;
	//string str = "1+2*(30+4)*(5/2)";
	string str = "1+2*(30+4)*(5/2)";
	cout << exp.expCal(str) << endl;;
	system("pause");
	return 0;
}

