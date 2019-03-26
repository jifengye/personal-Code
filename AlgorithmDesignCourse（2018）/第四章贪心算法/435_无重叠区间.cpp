/* 题目：435. 无重叠区间
 * 要求：给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
		注意:可以认为区间的终点总是大于它的起点。区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 * 来源：https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 * 时间：2018-11-03
 */



/* * 区间重叠（边界相互接触不视为重叠） 
 *	重叠的情况有4种：  两种相交，两种包含
 * 	不重叠的情况有2种：A在B前面，A在B后面
 *
 *	判断区间重叠的方法：
 *		1、正向判断，列出四种重叠的情况，  满足其一，则重叠；
 *		2、逆向判断，列出两种不重叠的情况，满足其一，则不重叠；
 *
 *	表面看1比较复杂，但可优化正向判断：
 * 		其实只要满足 max(A.start,B.start)<min(A.end,B,end)，即可判断A，B重叠。
 *  用2方法，逆向判断：
 *		只要满足其一 (A.end<=B.start || A.start>=B.end) ， 则A,B不重叠 
 */
 
 
 
/*
　　本题求的是除区间的数量，而不是求移除那个，数出需要移除的区间数量较难
　　我们反向思考。需移除区间的最小数量 = 区间总数 - 重叠于某一块按一块算的区间数
　　所以我们需计算 重叠按一块算的区间数 
    那么本题就和题目 452.用最少数量的箭引爆气球 很像了
	注：我们会把重叠于某一块的一些区间的看成一个大区间，下面所说的就是指这种大区间
	 例如 ______  _____   可看成   ______  _____ 
	          _______ 
	因为 大区间 最小为1，用变量end来记 和第一块大区间的右边结束点。
	然后我们开始遍历剩下的大区间:
		如果当前大区间的起始点<end，说明有重叠，end更新为两个大区间结束点之间较小的那个
		如果当前大区间的起始点>end，说明无重叠，那么result++，end更新为当前大区间的结束点了 

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
	
		// 先排序 
		vector<pair<int, int> > points;
		for(auto e : intervals) points.push_back({e.start, e.end});
		sort(points.begin(), points.end());
		
		int result = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if(points[i].first < end) //有重叠 
                end = min(end, points[i].second);
            else{ //没有重叠 
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
