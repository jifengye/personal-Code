/* ��Ŀ��113. ·���ܺ� II
 * Ҫ�󣺸���һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
 * ��Դ��https://leetcode-cn.com/problems/path-sum-ii/description/
 * ʱ�䣺2018-11-11
 */
 
/**
 * 	˼·��
		�ֱ��ģ������м�֦
		��������и��ڵ㵽�ӽڵ�ĺͣ���������·��
		Ȼ��forѭ������������Ŀ����ȵ�·��������
	
	˵����
		����������ҪĿ�������ɶ���������·����·����
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
    newnode->left  = CreatBinaryTree(nums);  //�ݹ鴴��������
    newnode->right = CreatBinaryTree(nums);  //�ݹ鴴��������
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
	    
		//�������ӽڵ� 
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
 * 	������ 
 *	�����֦
 *		���Ƕ�sumֵ�жϣ����sumֵ����Ŀ��ֵ�ˣ�����·���ͼ�ȥ
 * 	��������֦�����в�ͨ����Ϊ����������valֵ�и���	
 *
 *	ֻ����Ҫ��·�����Ͳ������forѭ������
 *		�����ж��ӽڵ㴦sum����Ŀ��ֵʱ���ŰѸ�·�����룻 
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
//	//cin >> a;   //�޴�������������Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
//	a = qs.front(); qs.pop();
//	if(a == 0) return NULL;
//
//	struct TreeNode *newnode;
//    newnode = (struct TreeNode*)malloc( sizeof(struct TreeNode) );
//    newnode->val = a;
//    newnode->left  = CreatBinaryTree(qs);  //�ݹ鴴��������
//    newnode->right = CreatBinaryTree(qs);  //�ݹ鴴��������
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
//		//�������ӽڵ� 
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
 *	������ ���Žⷨ 
 *	����ÿ�εݹ飬sum��path���Ǵ���
 *	����ǵ�ռ�úܴ�ռ�
 *	�ο���̤���̣�ֵ�Ļ��� 
 *	�ڵݹ������л��ˣ���ôsum��pathֻ��һ������
 *  ���һ����ô�ͷ�ڵ㵽Ҷ�ӽڵ����¿�ʼ�������	 
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
//    newnode->left  = CreatBinaryTree(nums);  //�ݹ鴴��������
//    newnode->right = CreatBinaryTree(nums);  //�ݹ鴴��������
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
//		//�������ӽڵ� 
//		if(root->left==NULL && root->right==NULL && cursum==target) result.push_back( path );	
//	    
//		dfs(root->left);
//	    dfs(root->right);
//	    
//	    path.pop_back(); //������ǻ��� 
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

