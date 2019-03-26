/* 题目：874. 模拟行走机器人
 * 要求：机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
			-2：向左转 90 度
			-1：向右转 90 度
			1 <= x <= 9：向前移动 x 个单位长度
		在网格上有一些格子被视为障碍物。第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
		如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
		返回从原点到机器人的最大欧式距离的平方。
 * 来源：https://leetcode-cn.com/problems/walking-robot-simulation/description/
 * 时间：2018-11-02
 */
 
 
/* 本题就像下棋，没有什么快捷方法，顶多在转向和查找上做改进 
	一、首要解决的是机器人转向，用0~3标记东南西北。向右就+1，向左就-1(因为对4取余故+3就是-1)。这个算是本题难点，方法很巧妙，要学习。 
	二、其次是判断障碍物，使用set类型，方便查找。每走一步在前进过程中都要判断
	三、最后走到最后不一定就是最远的，有可能往回走，所以没走一步都要计算距离 
*/
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int x = 0, y = 0; //机器人位置 
		int dir = 0; //机器人朝向，0朝北，1朝东，2朝南，3朝西 
		int result = 0; //机器人与原点最大欧式平方 
		int g[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //四个方向位置计算方式 
		
		set<pair<int, int> > obstacles_set;//vector转set，方便查找 
		for(auto e : obstacles){
			obstacles_set.insert({e[0], e[1]});
		}
		
		for(auto c : commands){
			switch(c){
				case -2: //向左转 
						dir = (dir + 3) % 4;
					break;
					
				case -1: //向右转 
						dir = (dir + 1) % 4;
					break;
					
				default: //前进 c 步 
						while(c--){
							int nx = x + g[dir][0];
							int ny = y + g[dir][1];
							if (obstacles_set.find({nx, ny}) != obstacles_set.end()) break;
							x = nx;
							y = ny;
						}
			}
			result = max(result, x * x + y * y);
		}
		return result;
	}
};

int main(){
	Solution solu;
	vector<int> commands = {4,-1,3};
	vector<vector<int>> obstacles = {};
	cout<<solu.robotSim( commands, obstacles );
	return 0;
} 
