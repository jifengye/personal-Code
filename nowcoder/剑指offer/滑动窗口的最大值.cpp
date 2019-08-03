/*
滑动窗口的最大值
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
*/

#include<cstdio>
#include<vector>
#include<deque>
#include<climits> 
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i=0;i<num.size();++i){
            while(s.size() && num[s.back()]<=num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
                s.pop_back();
            while(s.size() && i-s.front()+1>size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
                s.pop_front();
            s.push_back(i);//把每次滑动的num下标加入队列
            if(size&&i+1>=size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back(num[s.front()]);
        }
        return res;
    }
};

int main(){
	class Solution solu;
	vector<int> num = {1,2,3,4,5,6,7};
	int size = 7;
	vector<int> result = solu.maxInWindows(num, size);
	for(auto e:result){
		printf("%d ",e);
	}
	return 0;
} 
