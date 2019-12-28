/*
按之字形顺序打印二叉树

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/
#include<vector>
#include<iostream>
#include<algorithm>
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
//层次遍历，使用队列，按照层级分别保存
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      	vector<vector<int>> result;
	    LevelOrderTraverse(pRoot, 0, result);
	    for(int i=1; i<result.size(); i+=2){
	    	reverse(result[i].begin(), result[i].end());
		}
	    return result;
    }
  	void LevelOrderTraverse(TreeNode* root, int depth, vector<vector<int>> &result) {
	    if(root==NULL) return;
	    if(depth >= result.size()) result.push_back(vector<int>{});
	    result[depth].push_back(root->val);
	    LevelOrderTraverse(root->left,  depth + 1, result);
	    LevelOrderTraverse(root->right, depth + 1, result);
	}
}; 



int main(){
	TreeNode* head = CreatBinaryTree();
	Solution solu;
	vector<vector<int> > result = solu.Print(head);
    for(auto line:result){
    	for(auto e:line) cout<<e<<' ';
    	cout<<endl;
	}
	return 0;
} 
