/* 题目：455. 分发饼干
 * 要求：每块饼干 j ，都有一个尺寸 Sj 。
         每个孩子 i ，都有一个胃口 Gi ，这是能让孩子们满足胃口的饼干的最小尺寸。每个孩子最多只能给一块饼干。
 		 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 * 来源：https://leetcode-cn.com/problems/assign-cookies/description/
 * 时间：2018-9-30 
 */
 
/* 方法一：贪心算法 
 * 时间：O(NlogN)
 * 思路：先排序，从最小的饼干分起。排序后： 
        把第i块饼干分给将将能满足的第j个孩子，可知第i+1块饼干肯定能满足[0,j-1]中任何一个孩子 
 */ /*
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); //升序排序 
		sort(s.begin(), s.end());
		
		int wait = 0; 
		int result = 0;
		int j=0;
		for(int i=0; i<s.size(); i++) {
			for(; j<g.size() && g[j]<=s[i]; j++) wait++;
			if (wait) {
				wait--;
				result++;
			}
		}
		return result;
	}
};


int main(){
	Solution solu;
	// 孩子胃口 
	int a[] = {1,2};
	int an = sizeof(a)/sizeof(a[0]);
	vector<int> nums1(a, a+an);
	
	// 饼干尺寸 
	int b[] = {1,2,3};
	int bn = sizeof(b)/sizeof(b[0]);
	vector<int> nums2(b, b+bn);

	cout << solu.findContentChildren(nums1,nums2);
	return 0;
}

*/

/* 方法一：贪心算法 
 * 时间：O(NlogN)
 * 思路：先排序。饼干i和孩子j都从小往大比。若饼干能满足当前的孩子，就分给他，不需要将将好 
 		相当于装袋问题，把袋子和物品从小到大排好，拿最小的袋子和最小的物品比起，...... 
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); //升序排序 
		sort(s.begin(), s.end());
		
		int count = 0;
		for(int i=0,j=0; i<s.size() && j<g.size(); ) {
			if(s[i]>=g[j]){ //当前饼干能满足当前孩子 
				i++;
				j++;
				count++;
			}
			else //当前饼干不能满足当前孩子 ，拿下一块 
				i++;
		}
		return count;
	}
};


int main(){
	Solution solu;
	// 孩子胃口 
	int a[] = {1,2};
	int an = sizeof(a)/sizeof(a[0]);
	vector<int> nums1(a, a+an);
	
	// 饼干尺寸 
	int b[] = {1,2,3};
	int bn = sizeof(b)/sizeof(b[0]);
	vector<int> nums2(b, b+bn);

	cout << solu.findContentChildren(nums1,nums2);
	return 0;
}
