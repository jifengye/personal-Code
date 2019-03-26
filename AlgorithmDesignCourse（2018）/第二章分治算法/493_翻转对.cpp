/* ��Ŀ��493. ��ת�� 
 * Ҫ�󣺸���һ������ nums ����� i < j �� nums[i] > 2*nums[j] ���Ǿͽ� (i, j) ����һ����Ҫ��ת�ԡ�����Ҫ���ظ��������е���Ҫ��ת�Ե������� 
 * ��Դ��https://leetcode-cn.com/problems/reverse-pairs/description/
 * ����: 1 3 2 3 1
 * ���: 2
 * ʱ�䣺2018/9/25 
 */
 
/* ����һ������
 * ʱ�䣺O(n^2)
 * ֻͨ����33��ʵ�� 
 */
//#include <iostream>
//#include <vector>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//	int reversePairs(vector<int>& nums) {
//		int count=0; //��ת��
//		for(int i=0; i<nums.size(); i++)
//			for(int j=i+1; j<nums.size(); j++)
//				if(nums[i]/2.0>nums[j]) count++;
//		return count;
//	}
//};
//
//int main(){
//    Solution solu;
//    vector<int> nums;
//    int a;
//	cout<<"���������ʱ����ctrl+d����enter��"<<endl;
//    while(cin>>a){
//        nums.push_back(a);
//    } 
//    cout<<solu.reversePairs(nums);
//    return 0;
//} 


/* ������������
 * ʱ�䣺O(NlogN)
 * ʵ���ǹ鲢�����㷨�����м������ 
 */
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
private:
	vector<int> merge(vector<int> left, vector<int> right) { //�鲢���򷽷� 
		vector<int> ans;
		int i=0;
		int j=0;
		while(i<left.size() && j<right.size()) {
			if(left[i]<right[j])  ans.push_back(left[i++]);
			else  ans.push_back(right[j++]);
		}
		while(i<left.size()) ans.push_back(left[i++]); 
		while(j<right.size()) ans.push_back(right[j++]);
		
		return ans;
	}
public:
	int reversePairs(vector<int>& nums) {
		if (nums.size() < 2) return 0; //�ݹ����
		 
		int mid = nums.size() >> 1; //�԰�ֳ��������� 
		vector<int> left(nums.begin(), nums.begin() + mid);
		vector<int> right(nums.begin() + mid, nums.end());
		
		int ans = reversePairs(left) + reversePairs(right); //�ݹ� 
		
		int j=0;
		for(int i=0; i<left.size(); i++) {
			for(; j<right.size() && left[i]/2.0-right[j]>0; j++);
			ans += j;
		}
		nums = merge(left, right);//����͹鲢
		return ans;
	}
};

int main(){
    Solution solu;
    vector<int> nums = {1,3,2,3,1};
    cout<<solu.reversePairs(nums);
    return 0;
} 
