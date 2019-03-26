/* ��Ŀ��860. ����ˮ����
 * Ҫ��ÿһ������ˮ���ۼ�Ϊ 5Ԫ��ÿλ�˿�ֻ��һ����Ȼ�����㸶 5Ԫ����10Ԫ���� 20Ԫ��
         ������ÿ���˿���ȷ���㡣ע�⣬һ��ʼ����ͷû���κ���Ǯ��
        ������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��
 * ��Դ��https://leetcode-cn.com/problems/lemonade-change/description/
 * ʱ�䣺2018-9-30 
 */
 
/* ����һ��̰���㷨 
 * ʱ�䣺O(N)
 * ˼·�����͵�̰���㷨���ȴӴ�Ǯ��������10Ԫ������5Ԫ 
 */ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int cnt10 = 0, cnt5 = 0; //��¼5Ԫ��10Ԫ������֧�����20Ԫ������20������������ 
		for(int i=0; i<bills.size(); i++) {
			if(bills[i] == 20){ //����ʱ��10Ԫ����
				if(cnt10 && cnt5) {cnt10--;cnt5--;} //��һ��10��һ��5 
				else if(cnt5>=3)  cnt5-=3; //��3��5 
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

