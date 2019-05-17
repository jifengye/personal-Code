#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<queue>  
using namespace std;  
const int maxn = 10005;  
  
struct Node
{  
    int p,d,oldp; //oldp是上一个位置 
    friend bool operator <(const Node &a,const Node &b)
    {  
        if(a.p==b.p)  return a.oldp>b.oldp;  
        return a.p>b.p;  
    }  
};  
  
int main()  
{  
    //freopen("input.txt","r",stdin);  
    int N,i;  
    priority_queue<Node>pq;  
    Node temp;  
    scanf("%d",&N);  
    for (i=0;i<N;i++)  
    {  
        scanf("%d%d",&temp.p,&temp.d);  
        temp.oldp=temp.p;  
        pq.push(temp);  
    }  
    bool flag=0;  
    while(!pq.empty())  
    {  
        temp=pq.top();  
        pq.pop();  
        if(flag)  
        {  
            temp.p+=temp.d;  
            pq.push(temp);  
        }  
        flag=!flag;  
    }   
    printf("%d\n",temp.p);  
    return 0;  
}
