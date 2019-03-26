/* ��Ŀ��473. ���ƴ������
 * Ҫ������ÿ����񳤶ȡ��ж��Ƿ��������еĻ��ƴ��������
 * ��Դ��https://leetcode-cn.com/problems/matchsticks-to-square/description/
 * ʱ�䣺2018-11-16
 */

/**
	�����ⷨ
		ÿ�����ֱ���䵽�����ߣ����������ϣ�ֱ���гɹ��ķ�������
		
	�Ľ��� 
		ͨ�����л�񳤶ȺͿ�����������α߳���
		�õ���֦������һ�����ȳ����߳����÷�������������֦
		���жϳɹ�������ֻҪ����ϳ������ߣ�������һ���ܳɹ� 
		����ﵽ��֦��������񰴳��ȴӴ�С���� 
*/	 
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
	int circumfer; //�������ܳ� 
	int sideLength; //�����α߳� 
	vector<int> sides = {0,0,0,0}; //������
	
	bool dfs(const vector<int>& nums, int id) {
		if(id == nums.size()) 
			return sides[0]==sideLength && sides[1]==sideLength && sides[2]==sideLength;
			
		for (int i=0;i<4;i++) {
			if (sides[i]+nums[id] > sideLength) continue; //��֦ 
			
			sides[i] += nums[id];
			if(dfs(nums,id+1)) return true; //��֦���гɹ��ķ������㷨ֹͣ 
			sides[i] -= nums[id];
		}
		return 0;
	}
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) return false;
		
		circumfer = accumulate(nums.begin(),nums.end(),0); //���л�񳤶Ⱥ� 
		if (circumfer%4 != 0) return false; 
		
		sort(nums.begin(),nums.end(),greater<int>()); //���� 
		sideLength = circumfer/4;
		if (nums[0] > sideLength) return false; 
		
		return dfs(nums,0);
	}
};

int main() {
	Solution solu;	
	vector<int> nums({1,1,2,2,2});	
	cout << solu.makesquare(nums);
	return 0;
}
