/* ��Ŀ��455. �ַ�����
 * Ҫ��ÿ����� j ������һ���ߴ� Sj ��
         ÿ������ i ������һ��θ�� Gi ���������ú���������θ�ڵı��ɵ���С�ߴ硣ÿ���������ֻ�ܸ�һ����ɡ�
 		 ���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
 * ��Դ��https://leetcode-cn.com/problems/assign-cookies/description/
 * ʱ�䣺2018-9-30 
 */
 
/* ����һ��̰���㷨 
 * ʱ�䣺O(NlogN)
 * ˼·�������򣬴���С�ı��ɷ�������� 
        �ѵ�i����ɷָ�����������ĵ�j�����ӣ���֪��i+1����ɿ϶�������[0,j-1]���κ�һ������ 
 */ /*
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); //�������� 
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
	// ����θ�� 
	int a[] = {1,2};
	int an = sizeof(a)/sizeof(a[0]);
	vector<int> nums1(a, a+an);
	
	// ���ɳߴ� 
	int b[] = {1,2,3};
	int bn = sizeof(b)/sizeof(b[0]);
	vector<int> nums2(b, b+bn);

	cout << solu.findContentChildren(nums1,nums2);
	return 0;
}

*/

/* ����һ��̰���㷨 
 * ʱ�䣺O(NlogN)
 * ˼·�������򡣱���i�ͺ���j����С����ȡ������������㵱ǰ�ĺ��ӣ��ͷָ���������Ҫ������ 
 		�൱��װ�����⣬�Ѵ��Ӻ���Ʒ��С�����źã�����С�Ĵ��Ӻ���С����Ʒ����...... 
 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end()); //�������� 
		sort(s.begin(), s.end());
		
		int count = 0;
		for(int i=0,j=0; i<s.size() && j<g.size(); ) {
			if(s[i]>=g[j]){ //��ǰ���������㵱ǰ���� 
				i++;
				j++;
				count++;
			}
			else //��ǰ���ɲ������㵱ǰ���� ������һ�� 
				i++;
		}
		return count;
	}
};


int main(){
	Solution solu;
	// ����θ�� 
	int a[] = {1,2};
	int an = sizeof(a)/sizeof(a[0]);
	vector<int> nums1(a, a+an);
	
	// ���ɳߴ� 
	int b[] = {1,2,3};
	int bn = sizeof(b)/sizeof(b[0]);
	vector<int> nums2(b, b+bn);

	cout << solu.findContentChildren(nums1,nums2);
	return 0;
}
