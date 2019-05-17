//算法10.4魔法少女之相亲大会（仿AVL下标替代指针）
//旋转判断依据随机数就不用时刻维护平衡
//由位置找人时无需中序遍历一次，节约时间 
//使用引用传递，具有隐式的连接节点作用 
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
using namespace std;
const int N=100001;
  
struct Node  
{  
    int data; //值 
	int lson; //左子 
	int rson; //右子 
	int num; //自己和子孙总个数 
	int rnd;  //存储随机数 (随机的左转右转) 
	int frg;  //频率 
}node[N];
int size=0,root; 

//更新结点信息  
void update(int k)
{  
    node[k].num=node[node[k].lson].num+node[node[k].rson].num+node[k].frg;  
} 
 
void rturn(int &k2)  //左左 
{  
    int k1=node[k2].lson;  
    node[k2].lson=node[k1].rson;  
    node[k1].rson=k2;  
    node[k1].num=node[k2].num;  
    update(k2);  
    k2=k1; //因为是引用这一步不能少 
}  

void lturn(int &k2) //右右 
{  
    int k1=node[k2].rson;  
    node[k2].rson=node[k1].lson;  
    node[k1].lson=k2;  
    node[k1].num=node[k2].num;  
    update(k2);  
    k2=k1;  
}  

void insert(int &k,int x)  
{  
    if(k==0)  
    {  
        k=++size;  
        node[k].num=node[k].frg=1;  
        node[k].data=x;  
        node[k].rnd=rand();
        return;  
    }  
    node[k].num++;  
    if(node[k].data==x)node[k].frg++;//每个结点顺便记录下与该节点相同值的数的个数  
    else if(x>node[k].data)  
    {  
        insert(node[k].rson,x);  
        if(node[node[k].rson].rnd<node[k].rnd)lturn(k);//维护堆性质  
    }  
    else  
    {  
        insert(node[k].lson,x);  
        if(node[node[k].lson].rnd<node[k].rnd)rturn(k);  
    }  
}

void del(int &k,int x)  
{  
    if(k==0)return;
    if(node[k].data==x)  
    {  
        if(node[k].frg>1)  
        {  
            node[k].frg--;  
            node[k].num--;  
            return;//若不止相同值的个数有多个，删去一个  
        }  
        if(node[k].lson*node[k].rson==0)k=node[k].lson+node[k].rson;//有一个儿子为空  
        else if(node[node[k].lson].rnd<node[node[k].rson].rnd)  
            rturn(k),del(k,x);  
        else lturn(k),del(k,x);  
    }  
    else if(x>node[k].data)   node[k].num--,del(node[k].rson,x);  
    else                 node[k].num--,del(node[k].lson,x);  
} 

//查询x值的位置
int query_rank(int k,int x)  
{  
    if(k==0) return 0;
	 
    if(x<node[k].data)  
	    return query_rank(node[k].lson,x);
    else if(x>node[k].data)  
        return node[node[k].lson].num+node[k].frg+query_rank(node[k].rson,x);  
    else   
	    return node[node[k].lson].num+1;
}  

//查询x位置的值
int query_num(int k,int x)  
{  
    if(k==0) return 0;
    
    if(x<=node[node[k].lson].num)  
        return query_num(node[k].lson,x);  
    else if(x>node[node[k].lson].num+node[k].frg)  
        return query_num( node[k].rson, x-node[node[k].lson].num-node[k].frg);  
    else 
	    return node[k].data;  
}  

int main()  
{  

    char opt[4];  
    int n,x;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%s",opt);  
        if(opt[0] == 'J')//in  
        {  
            scanf("%d",&x);  
            insert(root,x);  
        }  
        else if(opt[0] == 'X')//out  
        {  
            scanf("%d",&x);  
            del(root,x);  
        }  
        else if(opt[0] == 'W')//output position  
        {             
            scanf("%d",&x);  
            printf("%d\n",query_num(root,x));  
        }  
        else printf("Single dog!\n");  
    }  
    return 0;  
}
/*
10
JX 11
JX 111
JX 1111
WT 1
XQ 11
WT 1
XQ 111
WT 1
WT 1111
YOU
*/
