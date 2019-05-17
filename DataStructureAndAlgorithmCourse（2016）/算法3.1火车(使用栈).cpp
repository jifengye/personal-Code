#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 105;
int main()
{
    int N;
    cin>>N;
    bool flag = true;
    stack<int>stk;
    int i,inout[maxn] = {0},in[maxn],out[maxn];
    
    char strin[maxn],strout[maxn];
    cin>>strin>>strout;
    for (i = 0; i < N; i++)	in[i] = strin[i] - '0';
    for (i = 0; i < N; i++)	out[i] = strout[i] - '0';
    
    int j = 0,p = 0;
    i = 0;
    for (i = 0; i < N; i++)
    {   if (in[i] != out[j])
        {   inout[p++] = 0;//0表火车进站
            stk.push(in[i]); //使用栈，记下进站火车的编号
        }
        else if (in[i] == out[j])
        {  inout[p++] = 0;
            j++;//出一辆火车则j+1，用于out[j]
            inout[p++] = 1;//1表火车出站
            while (!stk.empty() && stk.top() == out[j])//栈不空&&栈顶等于该次出站火车号
            {   j++;//j+1后，out[j]是下次出站火车号
                inout[p++] = 1;
                stk.pop();//删除栈顶元素
            }
        }
    }
    while (!stk.empty())
    {   if (stk.top() != out[j])
        {    cout<<"No"<<endl;
             return 0;           
        }
        else
        {   j++;
            stk.pop();
            inout[p++] = 1;
        }
    }
    cout<<"Yes"<<endl;
    for (i = 0; i < p; i++)	      
          inout[i]?printf("out\n"):printf("in\n");
    return 0;
}

/*
5
12342 24321
*/