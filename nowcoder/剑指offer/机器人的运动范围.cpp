/*
�����˵��˶���Χ

������һ��m�к�n�еķ���
һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19��
���ʸû������ܹ��ﵽ���ٸ����ӣ�
*/

/*
û��˵���ܻ���
���ܹ��鲼�ķ�Χ
ʹ����ȵݹ���� 
*/
#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
	int bitSum(int t){ //����λ�� 
        int count = 0;
        while (t != 0){
            count += t%10;
            t /= 10;
        }
        return  count;
    }

	int vis[100][100];
	int dir_x[4] = {1,0,-1,0};
	int dir_y[4] = {0,1,0,-1};
	int movingCount(int threshold, int rows, int cols, int x, int y) {
       	int ans=1;
		for(int r=0; r<4; ++r){
			int nx = x+dir_x[r];
			int ny = y+dir_y[r];
			if(0<=nx && nx<rows && 0<=ny && ny<cols && bitSum(nx)+bitSum(ny)<=threshold && vis[nx][ny]==0){
				vis[nx][ny]=1; 
				ans += movingCount(threshold, rows, cols, nx, ny);
			}
		}
		return ans;
    }
	
    int movingCount(int threshold, int rows, int cols) {
    	if(threshold<0) return 0;
		memset(vis,0,sizeof(vis));
		vis[0][0]=1;
		return movingCount(threshold, rows, cols, 0, 0);
    }
};

int main(){
	class Solution solu;
	cout<<solu.movingCount(-10, 10, 10);
	return 0;
}
