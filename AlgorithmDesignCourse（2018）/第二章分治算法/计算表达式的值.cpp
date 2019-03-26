/***
	����ʽת��Ϊ��׺���ʽ�� 
		1���������Ҷ�ȡ���������� 
		2����Ϊ���ֽ�����д���ַ���A�� 
		3����Ϊ���������ջ����������Ƚ����ȼ� 
			3-1����ջΪ�ջ�Ϊ��������ֱ��ѹ��ջ�� 
			3-2�������ȼ�����ջ����ֱ��ѹ�뵽ջ�� 
			3-3�������ȼ��ͻ������ջ����Ԫ�ص��������뵽A�У������µ�ջ��Ԫ�رȽ� 
		4����Ϊ���� 
			4-1����Ϊ������ֱ��ѹ�뵽ջ�� 
			4-2����Ϊ�����ջ����ʼ����Ԫ�����η��뵽A��ֱ����������ɾ��������� 
		5���ظ���������ֱ����ʽ����
		
		1+2*3  תΪ��׺���ʽΪ  123*+ 
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
class Expression{
private:
	stack<int> numStack; //����ջ
	stack<char> operatorStack; //������ջ

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
		stack<int> numStack; //����ջ
		stack<char> operatorStack; //������ջ
		for (int i=0; i<exp.length(); i++){
			//����ֱ����ջ
			if (exp[i]>='0' && exp[i]<='9'){
				int tmp = exp[i] - '0';
				while (i+1<exp.length() && exp[i+1]>='0' && exp[i+1]<='9'){ //�ж��Ƿ�Ϊ��λ��
					tmp = tmp*10 + (exp[++i]-'0');
				}
				numStack.push(tmp);
			}
			else if (operatorStack.empty() || exp[i]=='(') //ջΪ�ջ�������������ֱ����ջ
				operatorStack.push(exp[i]);
			else if (exp[i] == ')'){//���������ţ����г�ջ������ֱ������������
				while (operatorStack.top() != '(') {
					int rNum = numStack.top(); numStack.pop();
					int lNum = numStack.top(); numStack.pop();
					char oper = operatorStack.top(); operatorStack.pop();
					numStack.push( cal(lNum, rNum, oper) );
				}
				operatorStack.pop();
			}
			else if (getPriority(operatorStack.top()) >= getPriority(exp[i])){//ջ�����������ȼ� >= ��ǰ������,������ʽֵ
				int rNum = numStack.top(); numStack.pop();
				int lNum = numStack.top(); numStack.pop();
				char oper = operatorStack.top(); operatorStack.pop();
				numStack.push( cal(lNum, rNum, oper) );
				i--; //exp[i]��û���� 
			}
			else //ջ�����������ȼ� < ��ǰ������,ֱ����ջ
				operatorStack.push(exp[i]);
		}
 
		//�ַ���������ϣ���ջ�����ձ��ʽ��ֵ
		while (!operatorStack.empty()){
			int rNum = numStack.top(); numStack.pop();
			int lNum = numStack.top(); numStack.pop();
			char oper = operatorStack.top(); operatorStack.pop();
			numStack.push( cal(lNum, rNum, oper) );
		}
		return numStack.top();//������Ԫ�ظ�������1����ʾ���ʽ�Ƿ�
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

