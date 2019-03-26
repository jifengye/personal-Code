/* 题目：860. 柠檬水找零
 * 要求：每一杯柠檬水的售价为 5元。每位顾客只买一杯，然后向你付 5元、或10元、或 20元。
         你必须给每个顾客正确找零。注意，一开始你手头没有任何零钱。
        如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
 * 来源：https://leetcode-cn.com/problems/lemonade-change/description/
 * 时间：2018-9-30 
 */
 
/* 方法一：贪心算法 
 * 时间：O(N)
 * 思路：典型的贪心算法，先从大钱找起：先找10元，再找5元 
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int cnt10 = 0, cnt5 = 0; //记录5元、10元张数。支付最大20元，所以20不能用于找零 
		for(int i=0; i<bills.size(); i++) {
			if(bills[i] == 20){ //找零时从10元找起
				if(cnt10 && cnt5) {cnt10--;cnt5--;} //找一张10、一张5 
				else if(cnt5>=3)  cnt5-=3; //找3张5 
				else  return false;
			}
			else if(bills[i] == 10){
				cnt10 ++;
				if(cnt5) cnt5--;
				else return false;
			}
			else if(bills[i] == 5){
				cnt5 ++;
			} 
		}
		return true;
	}
};

int main(){
	Solution solu;
	vector<int> nums = {5,10,20};
	cout << boolalpha << solu.lemonadeChange(nums);
	return 0;
}

