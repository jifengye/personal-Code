/* ��Ŀ��104. ��������������
 * Ҫ�󣺸���һ�����������ҳ��������ȡ�
         �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
 * ��Դ��https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 * ʱ�䣺2018-11-6
 */

/**
 * ����:
 *	 �ܼ򵥣�ֱ�ӵݹ������ 
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
	if(a == 0) return NULL;//�޴�������������Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ�����������

	struct TreeNode *newnode;
    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
    newnode->val = a;
    newnode->left  = CreatBinaryTree(nums);  //�ݹ鴴��������
    newnode->right = CreatBinaryTree(nums);  //�ݹ鴴��������
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
