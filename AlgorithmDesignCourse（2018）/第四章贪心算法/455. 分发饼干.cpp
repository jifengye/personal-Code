/*
455. 分发饼干
每个孩子最多只能给一块饼干。
对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；
每块饼干 j ，都有一个尺寸 sj 。
如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
输出满足越多数量的孩子这个最大数值。
*/

/*
胃口的饼干先升序排序 
从最小饼干分起，分给胃口最小的朋友
以此递进
分不出去的饼干舍弃 
*/
#include<iostream>
#include<vector>
#include<algorithm>
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

int main() {
	Solution solu;
	vector<int> g = {1,2};
	vector<int> s = {1,2,3};
	cout<<solu.findContentChildren(g, s);
	return 0;
} 
