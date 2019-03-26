/* ��Ŀ��874. ģ�����߻�����
 * Ҫ�󣺻�������һ�����޴�С�����������ߣ��ӵ� (0, 0) ����ʼ���������򱱷����û����˿��Խ��������������͵����
			-2������ת 90 ��
			-1������ת 90 ��
			1 <= x <= 9����ǰ�ƶ� x ����λ����
		����������һЩ���ӱ���Ϊ�ϰ���� i ���ϰ���λ�������  (obstacles[i][0], obstacles[i][1])
		�����������ͼ�ߵ��ϰ����Ϸ�����ô����ͣ�����ϰ����ǰһ�����񷽿��ϣ�����Ȼ���Լ�����·�ߵ����ಿ�֡�
		���ش�ԭ�㵽�����˵����ŷʽ�����ƽ����
 * ��Դ��https://leetcode-cn.com/problems/walking-robot-simulation/description/
 * ʱ�䣺2018-11-02
 */
 
 
/* ����������壬û��ʲô��ݷ�����������ת��Ͳ��������Ľ� 
	һ����Ҫ������ǻ�����ת����0~3��Ƕ������������Ҿ�+1�������-1(��Ϊ��4ȡ���+3����-1)��������Ǳ����ѵ㣬���������Ҫѧϰ�� 
	����������ж��ϰ��ʹ��set���ͣ�������ҡ�ÿ��һ����ǰ�������ж�Ҫ�ж�
	��������ߵ����һ��������Զ�ģ��п��������ߣ�����û��һ����Ҫ������� 
*/
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int x = 0, y = 0; //������λ�� 
		int dir = 0; //�����˳���0������1������2���ϣ�3���� 
		int result = 0; //��������ԭ�����ŷʽƽ�� 
		int g[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //�ĸ�����λ�ü��㷽ʽ 
		
		set<pair<int, int> > obstacles_set;//vectorתset��������� 
		for(auto e : obstacles){
			obstacles_set.insert({e[0], e[1]});
		}
		
		for(auto c : commands){
			switch(c){
				case -2: //����ת 
						dir = (dir + 3) % 4;
					break;
					
				case -1: //����ת 
						dir = (dir + 1) % 4;
					break;
					
				default: //ǰ�� c �� 
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
