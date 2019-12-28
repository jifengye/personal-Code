/*
二叉树的下一个结点


给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

我们不需要遍历整棵数，该节点的下一个节点有如下情况： 
	1.该节点空，则返回空； 
	2.如果有右子节点，那么从此右子节点出发一直求到最后一个的左子节点就是所求的下一个节点 
	3.如果没有右子节点，那么向上求，当当前节点是父亲节点的左子节点，那么父亲节点就是所求 
*/

#include<cstdio>
#include<iostream>
using namespace std;
 
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

//使用递归的方法创建二叉树 
struct TreeLinkNode *Creat(struct TreeLinkNode* fNode){
	int a;
	cin >> a; //有多少叶子就需要输入2倍个 0 才能结束创建进程 
	if(a == 0) return NULL;

	struct TreeLinkNode *newnode = (struct TreeLinkNode*)malloc( sizeof(struct TreeLinkNode) );
    newnode->val = a;
    newnode->next = fNode;
    newnode->left  = Creat(newnode);  //递归创建左子树
    newnode->right = Creat(newnode);  //递归创建右子树
    return newnode;
}


 
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode==NULL) return NULL;
		
		if(pNode->right){
			pNode = pNode->right;
			while(pNode->left) pNode = pNode->left;
			return pNode; 
		}
		
		while(pNode->next){
			if(pNode == pNode->next->left) return pNode->next;
			pNode = pNode->next; 
		}
		return NULL;
    }
};

int main(){
	class Solution solu;
	struct TreeLinkNode* head = Creat(NULL);
	
}
