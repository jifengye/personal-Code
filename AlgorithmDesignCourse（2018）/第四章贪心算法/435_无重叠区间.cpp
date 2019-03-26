/* ��Ŀ��435. ���ص�����
 * Ҫ�󣺸���һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
		ע��:������Ϊ������յ����Ǵ���������㡣���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
 * ��Դ��https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 * ʱ�䣺2018-11-03
 */



/* * �����ص����߽��໥�Ӵ�����Ϊ�ص��� 
 *	�ص��������4�֣�  �����ཻ�����ְ���
 * 	���ص��������2�֣�A��Bǰ�棬A��B����
 *
 *	�ж������ص��ķ�����
 *		1�������жϣ��г������ص��������  ������һ�����ص���
 *		2�������жϣ��г����ֲ��ص��������������һ�����ص���
 *
 *	���濴1�Ƚϸ��ӣ������Ż������жϣ�
 * 		��ʵֻҪ���� max(A.start,B.start)<min(A.end,B,end)�������ж�A��B�ص���
 *  ��2�����������жϣ�
 *		ֻҪ������һ (A.end<=B.start || A.start>=B.end) �� ��A,B���ص� 
 */
 
 
 
/*
������������ǳ���������������������Ƴ��Ǹ���������Ҫ�Ƴ���������������
�������Ƿ���˼�������Ƴ��������С���� = �������� - �ص���ĳһ�鰴һ�����������
����������������� �ص���һ����������� 
    ��ô����ͺ���Ŀ 452.�����������ļ��������� ������
	ע�����ǻ���ص���ĳһ���һЩ����Ŀ���һ�������䣬������˵�ľ���ָ���ִ�����
	 ���� ______  _____   �ɿ���   ______  _____ 
	          _______ 
	��Ϊ ������ ��СΪ1���ñ���end���� �͵�һ���������ұ߽����㡣
	Ȼ�����ǿ�ʼ����ʣ�µĴ�����:
		�����ǰ���������ʼ��<end��˵�����ص���end����Ϊ���������������֮���С���Ǹ�
		�����ǰ���������ʼ��>end��˵�����ص�����ôresult++��end����Ϊ��ǰ������Ľ������� 

 */
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
	
		// ������ 
		vector<pair<int, int> > points;
		for(auto e : intervals) points.push_back({e.start, e.end});
		sort(points.begin(), points.end());
		
		int result = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if(points[i].first < end) //���ص� 
                end = min(end, points[i].second);
            else{ //û���ص� 
                result++;
                end = points[i].second;
            }
        }
		return intervals.size() - result;
    }
};

int main(){
	Solution Solu;
	vector<Interval> intervals =  { {1,4}, {2,3}, {3,5} };
	cout <<  Solu.eraseOverlapIntervals(intervals);
	return 0;
}
