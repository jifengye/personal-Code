/* ��Ŀ��169.������ 
 * Ҫ�󣺸�����СΪn�����飬�ҵ����е�����(�����������������г��ִ���n/2�ε�Ԫ��) 
 * ��Դ��https://leetcode-cn.com/problems/majority-element/description/ 
 * ���룺2 2 1 1 5 6 1 2 2 1 1
 * �����1 
 * ʱ�䣺2018/9/23
 */


/* ����һ������̨�� 
 * ������ ��������ͬ��ϵ������������++��������������--��̨��û�ˣ����Ϊ�µ�������
 * ʱ�临�Ӷȣ� O(n)
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int ans = nums[0];//����
		int cnt = 0;//����������
		for(int i=0; i<nums.size(); i++){
			// ���� 
			if(nums[i] == ans) cnt++; 
			else cnt--;
			
			// �ж���������˭ 
			if(cnt < 0) {
				ans = nums[i];
				cnt = 1;
			}
		}
		return ans;
	}
};

int main(){
	Solution solu;
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<solu.majorityElement(nums);
    return 0;
}

/* ����������������λ�� 
 * ʱ�临�Ӷȣ� ��Ϊʹ�ÿ��ţ�O(NlogN) 
 * ʹ���������㷨���ⷴ��������ʱ�� 
 */
//#include <iostream>
//#include <vector>
//#include <limits>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		return nums[nums.size() >> 1];
//	}
//};
//
//int main(){
//	Solution solu;
//    vector<int> nums={2,2,1,1,1,2,2};
//    cout<<solu.majorityElement(nums);
//    return 0;
//}
