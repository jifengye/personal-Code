/* 题目：452.用最少数量的箭引爆气球
 * 要求：在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
         一支弓箭可以沿着x轴从不同点完全垂直地射出。
		 找到使得所有气球全部被引爆，所需的弓箭的最小数量。
 * 来源：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 * 时间：2018-11-05
 */
 
/***************************
  讲下思路：
  因为气球数量不为0，所以怎么也得先来一发啊，然后这一箭能覆盖的最远位置就是第一个气球的结束点，用变量end来表示。
  然后我们开始遍历剩下的气球:
  	如果当前气球的起始点<=end，说明有重合，之前那一箭可覆盖到当前的气球，end更新为两个气球结束点之间较小的那个
    如果当前气球的起始点>end，说明前面的箭无法覆盖到当前的气球，那么就得再来一发result++，end更新为当前气球的结束点了 
***************************/ 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end()); //按第一个数字升序排列，如果第一个数字相同，那么按第二个数字升序排列
        
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
