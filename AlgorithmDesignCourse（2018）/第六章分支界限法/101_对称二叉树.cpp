/* 题目：101. 对称二叉树
 * 要求：给定一个二叉树，检查它是否是镜像对称的。
		 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 来源：https://leetcode-cn.com/problems/symmetric-tree/description/
 * 时间：2018-11-7
 */

/**
 * 对 root 底下的左右子树进行
 * 		左子树先序遍历 
 *		右子树后序遍历
 *		一旦遇到数不同，则不对称，结束算法
 * 
 * 结合到这道题上 
 *   	return isTreesSymmetric(root1->left, root2->right) && isTreesSymmetric(root1->right, root2->left);
 *		这句用的很为巧妙 
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
private:
	bool isTreesSymmetric(TreeNode* root1, TreeNode* root2){
		if(root1==NULL && root2==NULL) return true;
		
		if(root1 && root2 && root1->val == root2->val){
			return isTreesSymmetric(root1->left, root2->right) && isTreesSymmetric(root1->right, root2->left);
		}
		return false;
	}
public:
    bool isSymmetric(TreeNode* root) {
    	if(root==NULL)  return true;
		return isTreesSymmetric(root->left, root->right);  
    }
};

int main(){
	Solution solu;
	struct TreeNode* root;
	root = CreatBinaryTree();
	
	cout << boolalpha << solu.isSymmetric(root);
	return 0;
}







/**
 * 这是使用栈的做法
 * 上面递归在时间上和花费差不多
 */
//#include <stack> 
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//struct TreeNode *CreatBinaryTree(){
//	int a;
//	cin >> a;   //愚蠢的做法，多少叶子就需要输入2倍个 0 才能结束创建进程 
//	if(a == 0) return NULL;
//
//	struct TreeNode *newnode;
//    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
//    newnode->val = a;
//    newnode->left  = CreatBinaryTree();  //递归创建左子树
//    newnode->right = CreatBinaryTree();  //递归创建右子树
//    return newnode;
//}
//
//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if(root==NULL)  return true;
//        
//        stack<TreeNode*> a, b;
//        if(root->left)  a.push(root->left);
//        if(root->right) b.push(root->right);
//        if(a.size() != b.size()) return false;
//            
//        while(!a.empty()){
//            TreeNode *l = a.top(), *r = b.top();
//            if(l->val != r->val)   return false;
//            a.pop(), b.pop();
//            
//            if(l->right && r->left){
//                a.push(l->right);
//                b.push(r->left);
//            }
//            else if(l->right || r->left) return false;
//            
//            if(l->left && r->right){
//                a.push(l->left);
//                b.push(r->right);
//            }
//            else if(l->left || r->right) return false;
//        }
//        return true;
//    }
//};
//
//int main(){
//	Solution solu;
//	struct TreeNode* root;
//	root = CreatBinaryTree();
//	
//	cout << boolalpha << solu.isSymmetric(root);
//	return 0;
//}
