/*
�ԳƵĶ�����

��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//ʹ�õݹ�ķ������������� 
struct TreeNode *CreatBinaryTree(){
	int a;
	cin >> a; //�ж���Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
	if(a == 0) return NULL;

	struct TreeNode *newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = a;
    newnode->left  = CreatBinaryTree();  //�ݹ鴴��������
    newnode->right = CreatBinaryTree();  //�ݹ鴴��������
    return newnode;
}




/*
һ����ݹ�
һ���ҵݹ�
����ͬ��ֵһ�� 
*/

class Solution {
public:
	bool dfs(TreeNode* lp, TreeNode* rp){
		if(lp==NULL && rp==NULL) return true;
		
		if(lp && rp && lp->val==rp->val) return dfs(lp->left, rp->right) && dfs(lp->right,rp->left);
		
		return false; 
	}
	
    bool isSymmetrical(TreeNode* pRoot) {
    	if(pRoot==NULL) return true;
    	
    	return dfs(pRoot->left, pRoot->right);
    }
};





int main(){
	TreeNode* head = CreatBinaryTree();
	Solution solu;
	cout<<solu.isSymmetrical(head);
	return 0;
} 

