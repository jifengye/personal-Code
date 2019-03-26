/* 题目：113. 路径总和 II
 * 要求：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 来源：https://leetcode-cn.com/problems/path-sum-ii/description/
 * 时间：2018-11-11
 */
 
/**
 * 	思路：
		粗暴的，不进行剪枝
		先求出所有根节点到子节点的和，并且生成路径
		然后for循环，挑出和与目标相等的路径，返回
	
	说明：
		本例代码主要目的是生成二叉树所有路径与路径和
 */ 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode *CreatBinaryTree(vector<int> &nums){
	int a = nums.front(); nums.erase(nums.begin());
	if(a == 0) return NULL;

	struct TreeNode *newnode;
    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
    newnode->val = a;
    newnode->left  = CreatBinaryTree(nums);  //递归创建左子树
    newnode->right = CreatBinaryTree(nums);  //递归创建右子树
    return newnode;
}

void output_2V(vector<vector<int> > matrix){
	for(auto nums:matrix){
		for(auto e:nums) cout<<e;
		cout<<endl;
	}
	cout<<endl;
}

class Solution {
public:
	vector< pair<int,vector<int> > > treAllPaths;
	void dfs(TreeNode* node, int sum,vector<int> path){
	    path.push_back(node->val);
	    sum += node->val;
	    
		//遍历到子节点 
		if(node->left==NULL && node->right==NULL) treAllPaths.push_back( make_pair(sum, path) );	
	    
		if(node->left!=NULL)  dfs(node->left, sum,path);
	    if(node->right!=NULL) dfs(node->right,sum,path);
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
			
		if(root!=NULL){
			vector<int> path;
			dfs(root,0,path);
			for(auto e:treAllPaths){
				if(e.first == sum) result.push_back(e.second);
			}
		}
		return result;
    }
};

int main(){
	Solution solu;
	vector<int> nums = {5,4,11,7,0,0,2,0,0,0,8,13,0,0,4,5,0,0,1,0,0};
	struct TreeNode* root;
	root = CreatBinaryTree(nums);
	output_2V(solu.pathSum(root,22));
	return 0;
}













/**
 * 	（二） 
 *	加入剪枝
 *		就是对sum值判断，如果sum值大于目标值了，这条路径就剪去
 * 	更正：剪枝方法行不通，因为测试用例中val值有负数	
 *
 *	只存需要的路径，就不用最后for循环查找
 *		就是判断子节点处sum等于目标值时，才把该路径存入； 
 */ 
//#include <queue>
//#include <vector> 
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
//struct TreeNode *CreatBinaryTree(queue<int> &qs){
//	int a;
//	//cin >> a;   //愚蠢的做法，多少叶子就需要输入2倍个 0 才能结束创建进程 
//	a = qs.front(); qs.pop();
//	if(a == 0) return NULL;
//
//	struct TreeNode *newnode;
//    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
//    newnode->val = a;
//    newnode->left  = CreatBinaryTree(qs);  //递归创建左子树
//    newnode->right = CreatBinaryTree(qs);  //递归创建右子树
//    return newnode;
//}
//
//void output_2V(vector<vector<int> > matrix){
//	for(auto nums:matrix){
//		for(auto e:nums) cout<<e;
//		cout<<endl;
//	}
//	cout<<endl;
//}
//
//class Solution {
//private:
//	vector<vector<int> > result;
//	int target;
//	
//	void dfs(TreeNode* root, int sum,vector<int> path){
//		if(root==NULL) return;
//		
//	    path.push_back(root->val);
//	    sum += root->val;
//		 
//		//遍历到子节点 
//		if(root->left==NULL && root->right==NULL && sum==target) result.push_back( path );	
//	    
//		dfs(root->left, sum,path);
//	    dfs(root->right,sum,path);
//	}
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//		vector<int> path;
//		target = sum;
//		dfs(root,0,path);
//		return result;
//    }
//};
//
//
//
//
//
//int main(){
//	Solution solu;
//	
//	queue<int> qs;
//	int a[] = {5,4,11,7,0,0,2,0,0,0,8,13,0,0,4,5,0,0,1,0,0};
//	for(auto e:a) qs.push(e);
//	
//	struct TreeNode* root;
//	root = CreatBinaryTree(qs);
//	
//	int target = 22;
//	
//	output_2V(solu.pathSum(root,target));
//	return 0;
//}














/**
 *	（三） 最优解法 
 *	发现每次递归，sum和path都是传参
 *	这会是的占用很大空间
 *	参考马踏棋盘，值的回退 
 *	在递归最后进行回退，那么sum和path只需一个即可
 *  而且还不用从头节点到叶子节点重新开始计算求和	 
 */
//#include <vector> 
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
//struct TreeNode *CreatBinaryTree(vector<int> &nums){
//	int a = nums.front(); nums.erase(nums.begin());
//	if(a == 0) return NULL;
//
//	struct TreeNode *newnode;
//    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
//    newnode->val = a;
//    newnode->left  = CreatBinaryTree(nums);  //递归创建左子树
//    newnode->right = CreatBinaryTree(nums);  //递归创建右子树
//    return newnode;
//}
//
//void output_2V(vector<vector<int> > matrix){
//	for(auto nums:matrix){
//		for(auto e:nums) cout<<e;
//		cout<<endl;
//	}
//}
//
//class Solution {
//public:
//	vector<vector<int>> result;
//	vector<int> path;
//	int target;
//	int cursum;
//	
//	void dfs(TreeNode* root){
//		if(root==NULL) return;
//		
//	    path.push_back(root->val);
//	    cursum += root->val;
//		 
//		//遍历到子节点 
//		if(root->left==NULL && root->right==NULL && cursum==target) result.push_back( path );	
//	    
//		dfs(root->left);
//	    dfs(root->right);
//	    
//	    path.pop_back(); //这个就是回退 
//	    cursum -= root->val;
//	}
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//		target = sum;
//		cursum = 0;
//		dfs(root);
//		return result;
//    }
//};
//
//int main(){
//	Solution solu;
//	vector<int> nums = {5,4,11,7,0,0,2,0,0,0,8,13,0,0,4,5,0,0,1,0,0};
//	struct TreeNode* root;
//	root = CreatBinaryTree(nums);
//	output_2V(solu.pathSum(root,22));
//	return 0;
//}

