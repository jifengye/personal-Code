/* 题目：111. 二叉树的最小深度
 * 要求：给定一个二叉树，找出其最小深度。
		最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 来源：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 * 时间：2018-11-7
 */


/**
 * 方法: 和求最大深度相反
 * 		但不是拿那个代码简单改个大于小于号就行 
 *	 	使用递归求深度
 *		因为不是遍历到最深，所以需考虑节点是否为叶子 
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode *CreatBinaryTree(){
	int a;
	cin >> a;   //愚蠢的做法，多少叶子就需要输入2倍个 0 才能结束创建进程 
	if(a == 0) return NULL;

	struct TreeNode *newnode;
    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
    newnode->val = a;
    newnode->left  = CreatBinaryTree();  //递归创建左子树
    newnode->right = CreatBinaryTree();  //递归创建右子树
    return newnode;
}

class Solution {
public:
    int minDepth(TreeNode* root) {
		if(root == NULL) return 0;
		if(root->left  == NULL) return minDepth(root->right) + 1;
		if(root->right == NULL) return minDepth(root->left)  + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main(){
	Solution solu;
	struct TreeNode* root;
	root = CreatBinaryTree();
	
	cout << solu.minDepth(root);
	return 0;
} 

/*
输入例子 
3 9 0 0 20 15 0 0 7 0 0

1 0 2 0 0

1 2 0 0 0
*/
