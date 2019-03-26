/* ��Ŀ��312. ������
 * Ҫ��ÿ�������һ������ i ʱ������Ի�� nums[left] * nums[i] * nums[right] ��Ӳ�ҡ� 
 		����� left �� right ����� i ���ڵ������������š�ע�⵱����������� i ������ left ������ right �ͱ�������ڵ�����
		�����ܻ��Ӳ�ҵ����������
 * ��Դ��https://leetcode-cn.com/problems/burst-balloons/description/
 * ʱ�䣺2018-11-19
 */
 
/*
	̰���㷨 
	ѡ���������ԭ�� 
		�������������ʱ�����ƴ� (1,size()-2)����С������
		�����򲻶�������ʱ��������С������
		���Ƿ��������У����� 1,8,2 
	
	
	�����㷨��
		��ʵ�������ѡ����������˳��
		ͨ������������˳��õ����ֵ 
	
	
	�����㷨
		Ϊ�����������������ͬ�������⣬��������˼��
		�Ӵ������һ��������ǰ������������λ�ÿ��԰�������������ֳ������֡�
		��Ҫע����Ǳ�����ַ����ں����� 
		
		XXXXlOOOOiOOOrXXXXXXX   //����i������OOOOiOOO���������� 
		 	 OOOOiOOO
	   XXXXl OOOOiOOO rXXXXXXX	//��ô����iʱӦ�������㣺l*i*r 
	         OOOO OOO			//��ô�������ٷָ�����󣬾�����...... 
	         
		dp[i][j]��ʾ�ѵ� i ������͵� j ������֮������ܵõ��ķ�ֵ 
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
		nums.push_back(1); 
		int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0)); 
		for (int length=3; length<=n; length++) { //��3��һ�飬��4��4��һ��......�����n��һ�飬���ϸ���dp���� 
			for (int i=0; i+length<=n; i++) {
				int j = i+length-1;
				dp[i][j] = -INT_MAX;
				for (int k=i+1; k<j; k++) {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
				}
			}
		}

        return  dp[0][n-1];
    }
};



int main() {
	Solution solu;
	vector<int> nums = {3,1,5,8};       
	cout<<solu.maxCoins(nums);
	return 0;
} 
