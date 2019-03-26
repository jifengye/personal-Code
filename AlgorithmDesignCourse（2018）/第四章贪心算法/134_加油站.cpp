/* ��Ŀ��134. ����վ
 * Ҫ����һ����·���� N ������վ�����е� i ������վ������ gas[i] ����
         ����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�
         ���������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1��
 * ��Դ��https://leetcode-cn.com/problems/gas-station/description/
 * ʱ�䣺2018-10-28
 */

/*
  ����һ��
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
 ����һ�Ľ���
 	��for���ҳ�����������Сֵ
*/ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0; //��¼���������仯 
        int minqua = 0; //��¼�����������ֵ 
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
 ��������
 	Ѱ�ҳ�����ķ�����һ��
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
