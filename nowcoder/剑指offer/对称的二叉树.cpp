/*
对称的二叉树

请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//使用递归的方法创建二叉树 
struct TreeNode *CreatBinaryTree(){
	int a;
	cin >> a; //有多少叶子就需要输入2倍个 0 才能结束创建进程 
	if(a == 0) return NULL;

	struct TreeNode *newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = a;
    newnode->left  = CreatBinaryTree();  //递归创建左子树
    newnode->right = CreatBinaryTree();  //递归创建右子树
    return newnode;
}




/*
一个左递归
一个右递归
两者同步值一样 
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

