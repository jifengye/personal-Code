/* ��Ŀ��452.�����������ļ���������
 * Ҫ���ڶ�ά�ռ�����������ε����򡣶���ÿ�������ṩ��������ˮƽ�����ϣ�����ֱ���Ŀ�ʼ�ͽ������ꡣ
         һ֧������������x��Ӳ�ͬ����ȫ��ֱ�������
		 �ҵ�ʹ����������ȫ��������������Ĺ�������С������
 * ��Դ��https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 * ʱ�䣺2018-11-05
 */
 
/***************************
  ����˼·��
  ��Ϊ����������Ϊ0��������ôҲ������һ������Ȼ����һ���ܸ��ǵ���Զλ�þ��ǵ�һ������Ľ����㣬�ñ���end����ʾ��
  Ȼ�����ǿ�ʼ����ʣ�µ�����:
  	�����ǰ�������ʼ��<=end��˵�����غϣ�֮ǰ��һ���ɸ��ǵ���ǰ������end����Ϊ�������������֮���С���Ǹ�
    �����ǰ�������ʼ��>end��˵��ǰ��ļ��޷����ǵ���ǰ��������ô�͵�����һ��result++��end����Ϊ��ǰ����Ľ������� 
***************************/ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end()); //����һ�������������У������һ��������ͬ����ô���ڶ���������������
        
        int result = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if(points[i].first <= end)
                end = min(end, points[i].second);
            else{
                result++;
                end = points[i].second;
            }
        }
        return result;
    }
};

int main(){
	Solution Solu;
	vector<pair<int, int> > points =  { {10,16}, {2,8}, {1,6}, {7,12} };
	cout <<  Solu.findMinArrowShots(points);
	return 0;
}
