/* ��Ŀ��111. ����������С���
 * Ҫ�󣺸���һ�����������ҳ�����С��ȡ�
		��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
 * ��Դ��https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 * ʱ�䣺2018-11-7
 */


/**
 * ����: �����������෴
 * 		���������Ǹ�����򵥸ĸ�����С�ںž��� 
 *	 	ʹ�õݹ������
 *		��Ϊ���Ǳ�������������迼�ǽڵ��Ƿ�ΪҶ�� 
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
	cin >> a;   //�޴�������������Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
	if(a == 0) return NULL;

	struct TreeNode *newnode;
    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
    newnode->val = a;
    newnode->left  = CreatBinaryTree();  //�ݹ鴴��������
    newnode->right = CreatBinaryTree();  //�ݹ鴴��������
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
�������� 
3 9 0 0 20 15 0 0 7 0 0

1 0 2 0 0

1 2 0 0 0
*/
