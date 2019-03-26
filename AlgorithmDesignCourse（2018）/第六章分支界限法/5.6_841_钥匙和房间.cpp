/* ��Ŀ��841. Կ�׺ͷ���
 * Ҫ���� N �����䣬ÿ������ i ������һ��Կ���б� rooms[i]������ÿ��Կ���� [0,1��...��N-1] �е�һ��������ʾ
		rooms[i][j] ��ʾ�� i �������д򿪷���j��Կ�� 
		������� 0 �ŷ�������������з��䶼����ס��
		���ж����ܷ����ÿ�����䣬����ܷ��� true�����򷵻� false��
 * ��Դ��https://leetcode-cn.com/problems/keys-and-rooms/description/
 * ʱ�䣺2018-11-10
 */

/**
 * ˼·
 *		ʹ�� set ����
 *		��  set �洢δ���򿪵ķ���
 *		���˷���ʹ� set ��ɾȥ
 *		һ�� set Ϊ�գ�˵���ܽ������з���
 */
#include <set> 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	set<int> lockrooms;
	void openrooms(vector<vector<int> >& rooms,int i){ //�򿪷���i 		
		for(auto e : rooms[i]){
			if(lockrooms.count(e)==0) continue; //����e�Ѵ򿪣����Կ��eû�� 

			lockrooms.erase(e); //ɾ�������� 
			openrooms(rooms,e); //���� 
		}
	}
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        for(int i=1; i<rooms.size(); i++) lockrooms.insert(i); //0�ſ��ţ�ȡ�����ŵķ������set���� 
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
