/* 题目：134. 加油站
 * 要求：在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
         你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
         如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 * 来源：https://leetcode-cn.com/problems/gas-station/description/
 * 时间：2018-10-28
 */

/*
  方法一：
 */ 
//#include <vector>
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		vector<int> temp({0});
//      int sum = 0;
//		for(int i=0; i<gas.size(); i++) {
//			sum += gas[i]-cost[i];
//			temp.push_back(sum);
//		}
//		
//		if(sum<0) return -1;
//		
//		return distance( temp.begin(),min_element(temp.begin(),temp.end()) );
//    }
//};
//
//int main(){
//	Solution solu;
//	int a[] = {1,2,3,4,5};
//	int b[] = {3,4,5,1,2};
//	int n = sizeof(a)/sizeof(a[0]);
//	vector<int> gas(a, a+n);
//	vector<int> cost(b, b+n);
//
//	cout << solu.canCompleteCircuit(gas,cost);
//	return 0;
//}


/*
 方法一改进：
 	在for中找出油箱油量最小值
*/ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0; //记录汽车油量变化 
        int minqua = 0; //记录汽车油量最低值 
        int result = 0;
		for(int i=0; i<gas.size(); i++) {
			if( sum < minqua ){
				minqua = sum;
				result = i;
			}
			sum += gas[i]-cost[i];
		}
		
		return sum<0 ? -1:result;
    }
};

int main(){
	Solution solu;
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	cout << solu.canCompleteCircuit(gas,cost);
	return 0;
}



/*
 方法三：
 	寻找出发点的方法不一样
 */ 
//#include <vector>
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//
//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int sum = 0, tmp = 0, result = 0;
//		for(int i=0; i<gas.size(); i++) {
//			tmp += gas[i]-cost[i];
//			sum += gas[i]-cost[i];
//			if (tmp < 0) {
//				tmp = 0;
//				result = i + 1;
//				//cout << result <<endl;
//			}
//		}
//		return sum >= 0 ? result : -1;
//	}
//};
//
//int main(){
//	Solution solu;
//	int a[] = {1,2,3,4,5};
//	int b[] = {3,4,5,1,2};
//	int n = sizeof(a)/sizeof(a[0]);
//	vector<int> gas(a, a+n);
//	vector<int> cost(b, b+n);
//
//	cout << solu.canCompleteCircuit(gas,cost);
//	return 0;
//}
