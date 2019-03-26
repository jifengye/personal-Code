/* ��Ŀ��4. Ѱ�����������������λ��
 * Ҫ�󣺸���������СΪ m �� n ���������� nums1 �� nums2 �����ҳ������������������λ����Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log (m+n)) ��
 * ��Դ��https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/ 
 * ʱ�䣺2018/9/26
 * nums1 = [1, 3]  nums2 = [2]
 * ��λ���� 2.0  
 */
 
/*
ģ��ϲ��������飺ÿ��ѡ�����н�С������ֱѡ���м�Ԫ��(�����鳤����ż���)����Ҫ�ҵ���λ�����㷨���Ӷ�ΪO(n1+n2)
�ⷨ���õ�һ���Ƚ�����ķ�����
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    ͨ����β��׷�����ֵ�������ķ�ֹԽ�磬���踴�ӵ�����жϼ��� 
*/
//#include<iostream>
//#include<vector>
//#include<limits>
//using namespace std;
//
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	    int n1 = nums1.size(), n2 = nums2.size();
//	    nums1.push_back(INT_MAX);//��ֹԽ�磬�򻯲��� 
//	    nums2.push_back(INT_MAX);
//	    int mid = n1+n2+2>>1, i=0, j=0; 
//		vector<int> nums;
//	    while(mid--) { //�ϲ�����ֻ����е�һ����� 
//			nums1[i]<nums2[j] ? nums.push_back(nums1[i++]):nums.push_back(nums2[j++]);
//	    }
//		return (nums[n1+n2-1>>1]+nums[n1+n2>>1])/2.0;
//	}
//};
// 
//int main(){
//    Solution solu;
//    vector<int> nums1 = {1,2};
//	vector<int> nums2 = {3,4};
//	cout<<solu.findMedianSortedArrays(nums1,nums2);
//    return 0;
//} 
 


/*
https://hk029.gitbooks.io/leetbook/%E5%88%86%E6%B2%BB/004.%20Median%20of%20Two%20Sorted%20Arrays[H]/004.%20Median%20of%20Two%20Sorted%20Arrays[H].html
����1��ĳ����������һ���Ԫ�ز������������λ������һ���Ԫ�ز�С����λ����
����2���������ȥ���������λ��С��k��������ȥ������λ�����k�������õ������������λ����ԭ������λ����ͬ��
�۰���ҵ�˼��
���������������λ���ֱ���nums1[m1], nums2[m2]
���nums1[m1] = nums2[m2] ����vec1[m1]����Ҫ�ҵ���λ����
���nums1[m1] < nums2[m2]�������λ��ֻ���ܳ�����nums1�ĺ��κ�nums2��ǰ��Ρ�������������������ಿ����ɾ����ͬ������Ԫ�أ�����λ�����䡣
*/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //��һ��Ϊ�գ�˫�����Ϊ������ 
		if(nums1.empty()) return MedofArray(nums2);
        if(nums2.empty()) return MedofArray(nums1);
        //��֤����1һ�����
        if(nums1.size()<nums2.size())  swap(nums1,nums2);
        int n = nums1.size();
        int m = nums2.size();

    	int L1,L2,R1,R2,c1,c2,low = 0, top = 2*n;  //����Ŀǰ���������'#'��������1��2*n+1����
        while(low <= top) {  //��nums1���ֲ��� 
        
            c1 = low+top>>1;  //c1�Ƕ��ֵĽ��
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
            
            c2 = m+n-c1;
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)
                top = c1-1;
            else if(L2 > R1)
                low = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
    double MedofArray(vector<int>& nums) { //�� 
        if(nums.size() == 0)    return -1;
        return (nums[nums.size()>>1]+nums[nums.size()-1>>1])/2.0;
    }
};

int main(){
    Solution solu;
    vector<int> nums1 = {1,2,3};
	vector<int> nums2 = {3,4};
	cout<<fixed<<setprecision(2)<<solu.findMedianSortedArrays(nums1,nums2);
    return 0;
} 

