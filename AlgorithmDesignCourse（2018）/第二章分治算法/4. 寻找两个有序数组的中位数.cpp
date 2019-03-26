/* 题目：4. 寻找两个有序数组的中位数
 * 要求：给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
 * 来源：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/ 
 * 时间：2018/9/26
 * nums1 = [1, 3]  nums2 = [2]
 * 中位数是 2.0  
 */
 
/*
模拟合并两个数组：每次选数组中较小的数，直选到中间元素(分数组长度奇偶情况)就是要找的中位数。算法复杂度为O(n1+n2)
解法中用到一个比较巧妙的方法：
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    通过在尾部追加最大值，有力的防止越界，让需复杂的情况判断简化了 
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
//	    nums1.push_back(INT_MAX);//防止越界，简化操作 
//	    nums2.push_back(INT_MAX);
//	    int mid = n1+n2+2>>1, i=0, j=0; 
//		vector<int> nums;
//	    while(mid--) { //合并操作只需进行到一半就行 
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
结论1：某个数组中有一半的元素不超过数组的中位数，有一半的元素不小于中位数。
结论2：如果我们去掉数组比中位数小的k个数，再去掉比中位数大的k个数，得到的子数组的中位数和原来的中位数相同。
折半查找的思想
假设两个数组的中位数分别是nums1[m1], nums2[m2]
如果nums1[m1] = nums2[m2] ，则vec1[m1]就是要找的中位数。
如果nums1[m1] < nums2[m2]，这个中位数只可能出现在nums1的后半段和nums2的前半段。因此在在两个数组其余部分中删除相同个数的元素，则中位数不变。
*/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //有一组为空，双数组变为单数组 
		if(nums1.empty()) return MedofArray(nums2);
        if(nums2.empty()) return MedofArray(nums1);
        //保证数组1一定最短
        if(nums1.size()<nums2.size())  swap(nums1,nums2);
        int n = nums1.size();
        int m = nums2.size();

    	int L1,L2,R1,R2,c1,c2,low = 0, top = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n+1长度
        while(low <= top) {  //对nums1二分查找 
        
            c1 = low+top>>1;  //c1是二分的结果
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
    double MedofArray(vector<int>& nums) { //割 
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

