/*
����������һ�����


����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

���ǲ���Ҫ�������������ýڵ����һ���ڵ������������ 
	1.�ýڵ�գ��򷵻ؿգ� 
	2.��������ӽڵ㣬��ô�Ӵ����ӽڵ����һֱ�����һ�������ӽڵ�����������һ���ڵ� 
	3.���û�����ӽڵ㣬��ô�����󣬵���ǰ�ڵ��Ǹ��׽ڵ�����ӽڵ㣬��ô���׽ڵ�������� 
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

//ʹ�õݹ�ķ������������� 
struct TreeLinkNode *Creat(struct TreeLinkNode* fNode){
	int a;
	cin >> a; //�ж���Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
	if(a == 0) return NULL;

	struct TreeLinkNode *newnode = (struct TreeLinkNode*)malloc( sizeof(struct TreeLinkNode) );
    newnode->val = a;
    newnode->next = fNode;
    newnode->left  = Creat(newnode);  //�ݹ鴴��������
    newnode->right = Creat(newnode);  //�ݹ鴴��������
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
