/* 题目：690. 员工的重要性
 * 要求：给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。
		现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
 * 来源：https://leetcode-cn.com/problems/employee-importance/description/
 * 时间：2018-11-9
 */

/**
 * 	思路简单 
 *		直接递归即可 
 *	难点是
 *		类的构造和指针的使用 
 * 		vector<Employee*> 容器内放的是这个类的地址，用&符号引用地址 
 *	更正：
 *		测试用例中下属id不是按数组下标的来 
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
 * 	上面用例使用一个for来找id
 *	当数据很大时会花费很多时间
 *	使用map来记录id，就能很快找到了
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
	unordered_map<int,Employee*> mm; //无序容器
	 
    int dp(int id){
        int sum = mm[id]->importance; //自身重要度 
        for(auto c:mm[id]->subordinates)  sum += dp(c); //下属重要度 
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto* p:employees) mm[p->id]=p; //vector 改用 map容器，方便查找 
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
