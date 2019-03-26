/* ��Ŀ��690. Ա������Ҫ��
 * Ҫ�󣺸���һ������Ա����Ϣ�����ݽṹ����������Ա��Ψһ��id����Ҫ�� �� ֱϵ������id��
		��������һ����˾������Ա����Ϣ���Լ�����Ա��id���������Ա������������������Ҫ��֮�͡�
 * ��Դ��https://leetcode-cn.com/problems/employee-importance/description/
 * ʱ�䣺2018-11-9
 */

/**
 * 	˼·�� 
 *		ֱ�ӵݹ鼴�� 
 *	�ѵ���
 *		��Ĺ����ָ���ʹ�� 
 * 		vector<Employee*> �����ڷŵ��������ĵ�ַ����&�������õ�ַ 
 *	������
 *		��������������id���ǰ������±���� 
 */
//#include <vector> 
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//class Employee {
//public:
//    int id;
//    int importance;
//    vector<int> subordinates;
//
//	Employee() { };
//	
//	void set(int a, int b, vector<int> c) {
//		id = a;
//		importance = b;
//		subordinates = c;
//	}
//};
//
//class Solution {
//public:
//    int getImportance(vector<Employee*> employees, int id) {
//		Employee* rt;
//		for (auto i:employees){
//			if (i->id==id){
//				rt=i; 
//				break;
//			}
//		}
//		int sum = rt->importance;
//		for (auto i:rt->subordinates) 
//			sum += getImportance(employees,i);
//		return sum;
//	}
//};
//
//int main() {
//	Solution solu;
//	vector<Employee*> ve;
//	
//	vector<int> c1,c2;
//	c1.push_back(2);
//	c1.push_back(3);
//	Employee empl[3];
//	empl[0].set(1,5,c1);
//	empl[1].set(2,3,c2);
//	empl[2].set(3,3,c2);
//	ve.push_back(&empl[0]);
//	ve.push_back(&empl[1]);
//	ve.push_back(&empl[2]);
//
//	cout << solu.getImportance(ve,3);
//	return 0;
//}


/**
 * 	��������ʹ��һ��for����id
 *	�����ݺܴ�ʱ�Ứ�Ѻܶ�ʱ��
 *	ʹ��map����¼id�����ܺܿ��ҵ���
 */
#include <vector> 
#include <iostream>
#include <unordered_map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;

	Employee() { };
	
	void set(int a, int b, vector<int> c) {
		id = a;
		importance = b;
		subordinates = c;
	}
};

class Solution {
public:
	unordered_map<int,Employee*> mm; //��������
	 
    int dp(int id){
        int sum = mm[id]->importance; //������Ҫ�� 
        for(auto c:mm[id]->subordinates)  sum += dp(c); //������Ҫ�� 
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto* p:employees) mm[p->id]=p; //vector ���� map������������� 
        return dp(id);
    }
};

int main() {
	Solution solu;
	vector<Employee*> ve;
	
	vector<int> c1,c2;
	c1.push_back(2);
	c1.push_back(3);
	Employee empl[3];
	empl[0].set(1,5,c1);
	empl[1].set(2,3,c2);
	empl[2].set(3,3,c2);
	ve.push_back(&empl[0]);
	ve.push_back(&empl[1]);
	ve.push_back(&empl[2]);

	cout << solu.getImportance(ve,3);
	return 0;
}
