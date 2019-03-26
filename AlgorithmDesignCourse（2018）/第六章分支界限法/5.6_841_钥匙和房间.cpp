/* 题目：841. 钥匙和房间
 * 要求：有 N 个房间，每个房间 i 都放着一堆钥匙列表 rooms[i]，对于每个钥匙由 [0,1，...，N-1] 中的一个整数表示
		rooms[i][j] 表示在 i 房间里有打开房间j的钥匙 
		最初，除 0 号房间外的其余所有房间都被锁住。
		请判断你能否进入每个房间，如果能返回 true，否则返回 false。
 * 来源：https://leetcode-cn.com/problems/keys-and-rooms/description/
 * 时间：2018-11-10
 */

/**
 * 思路
 *		使用 set 容器
 *		用  set 存储未被打开的房间
 *		打开了房间就从 set 中删去
 *		一旦 set 为空，说明能进入所有房间
 */
#include <set> 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	set<int> lockrooms;
	void openrooms(vector<vector<int> >& rooms,int i){ //打开房间i 		
		for(auto e : rooms[i]){
			if(lockrooms.count(e)==0) continue; //房间e已打开，这个钥匙e没用 

			lockrooms.erase(e); //删除，即打开 
			openrooms(rooms,e); //开房 
		}
	}
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        for(int i=1; i<rooms.size(); i++) lockrooms.insert(i); //0号开着，取余锁着的房间放入set容器 
		openrooms(rooms,0);
		return lockrooms.empty(); 
    }
};

int main() {
	Solution solu;
	vector<vector<int> > rooms = {{1},{2},{3},{}}; 
	cout << boolalpha << solu.canVisitAllRooms(rooms);
	return 0;
} 
