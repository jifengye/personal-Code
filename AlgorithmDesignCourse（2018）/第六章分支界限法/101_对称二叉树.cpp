/* ��Ŀ��101. �Գƶ�����
 * Ҫ�󣺸���һ����������������Ƿ��Ǿ���ԳƵġ�
		 ���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
 * ��Դ��https://leetcode-cn.com/problems/symmetric-tree/description/
 * ʱ�䣺2018-11-7
 */

/**
 * �� root ���µ�������������
 * 		������������� 
 *		�������������
 *		һ����������ͬ���򲻶Գƣ������㷨
 * 
 * ��ϵ�������� 
 *   	return isTreesSymmetric(root1->left, root2->right) && isTreesSymmetric(root1->right, root2->left);
 *		����õĺ�Ϊ���� 
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
 * ����ʹ��ջ������
 * ����ݹ���ʱ���Ϻͻ��Ѳ��
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
//	cin >> a;   //�޴�������������Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
//	if(a == 0) return NULL;
//
//	struct TreeNode *newnode;
//    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
//    newnode->val = a;
//    newnode->left  = CreatBinaryTree();  //�ݹ鴴��������
//    newnode->right = CreatBinaryTree();  //�ݹ鴴��������
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
