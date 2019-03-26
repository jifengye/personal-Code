/* 题目：104. 二叉树的最大深度
 * 要求：给定一个二叉树，找出其最大深度。
         二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 来源：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 * 时间：2018-11-6
 */

/**
 * 方法:
 *	 很简单，直接递归求深度 
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

struct TreeNode *CreatBinaryTree(vector<int>& nums){
	int a = nums.front(); nums.erase(nums.begin());
	if(a == 0) return NULL;//愚蠢的做法，多少叶子就需要输入2倍个 0 才能结束创建进程

	struct TreeNode *newnode;
    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
    newnode->val = a;
    newnode->left  = CreatBinaryTree(nums);  //递归创建左子树
    newnode->right = CreatBinaryTree(nums);  //递归创建右子树
    return newnode;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
		if(root == NULL) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(){
	Solution solu;
	struct TreeNode* root;
	vector<int> nums = {3,9,0,0,20,15,0,0,7,0,0} ;
	root = CreatBinaryTree(nums);
	cout << solu.maxDepth(root);
	return 0;
}
