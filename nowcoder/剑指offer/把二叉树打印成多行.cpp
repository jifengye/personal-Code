/*
�Ѷ�������ӡ�ɶ���

���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
*/
#include<vector>
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//ʹ�õݹ�ķ������������� 
struct TreeNode *CreatBinaryTree(){
	int a;
	cin >> a; //�ж���Ҷ�Ӿ���Ҫ����2���� 0 ���ܽ����������� 
	if(a == 0) return NULL;

	struct TreeNode *newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = a;
    newnode->left  = CreatBinaryTree();  //�ݹ鴴��������
    newnode->right = CreatBinaryTree();  //�ݹ鴴��������
    return newnode;
}



/*
//��α�����ʹ�ö��У����ղ㼶�ֱ𱣴�
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      	vector<vector<int>> result;
	    LevelOrderTraverse(pRoot, 0, result);
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
