/* ��Ŀ����������
 * Ҫ�󣺸���һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
 * ���룺-2 1 -3 4 -1 2 1 -5 4
 * �����6 
 * ��Դ��https://leetcode-cn.com/problems/maximum-subarray/description/
 * ʱ�䣺2018/9/16
 */

/* ����һ��̰���㷨
 * ʱ�临�Ӷȣ� O(n) 
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//using namespace std;
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = INT_MIN, tmp = 0;
//		for (auto e : nums) {
//			ans = max(ans, tmp += e);
//			tmp = max(tmp, 0);
//		}
//        return ans;
//    }
//};
//
//int main(){
//	Solution solu;
//	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
//	int n = sizeof(a)/sizeof(a[0]);
//	vector<int> nums(a, a+n);
//	
//    cout<<solu.maxSubArray(nums);
//    return 0;
//}





/* �������������㷨 
 * ʱ�临�Ӷȣ� O(NlogN)
 * ����ʱ���̰���㷨����
����ֳ����������֣��������������
��������ȫ������ߡ�
........��ȫ�����ұߡ�
........�������ߡ�
ǰ���ߵݹ�����
������Ϊ��ߵ�һ����׺���� + �ұߵ�һ��ǰ׺���顣
��������ת��Ϊ����������ǰ׺/��׺���顣 
 */
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> 
using namespace std;

class Solution {
private:
	int maxPreArray(vector<int> nums) { //���ǰ׺ 
		int ans = -INT_MAX, tmp = 0;
		for(int i = 0; i < nums.size(); i++){
			tmp += nums[i];
			ans = max(ans, tmp);
		}
		return ans;
	}
	int maxSufArray(vector<int> nums) { //����׺ 
		reverse(nums.begin(), nums.end());
		return maxPreArray(nums);
	}
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return -INT_MAX;
		if (nums.size() == 1) return nums[0];//�������ǵݹ����
		
		int mid = nums.size() >> 1;
		vector<int> nums_left(nums.begin(), nums.begin() + mid);//��nums�԰�ֳ�����
		vector<int> nums_right(nums.begin() + mid, nums.end());
		
		//������������������������ֵ 
		//Ҫ�Ƚ� a,b,c ������С�������� max( max(a,b), c ) 
		return max( max(maxSubArray(nums_left), maxSubArray(nums_right)), maxSufArray(nums_left) + maxPreArray(nums_right) );
	}
};

int main(){
    Solution solu;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<solu.maxSubArray(nums);
    return 0;
}
