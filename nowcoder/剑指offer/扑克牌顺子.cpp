/*
题意：给予5个数字，数字0可以代表任何数字

能否组成一个顺子（5个数字连续）
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

 
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
		if(numbers.empty()) return false;
		
		sort(numbers.begin(), numbers.end());
		
		int life = 0;
		int start = 0;
		for(auto e:numbers ){
			if(e==0) life++;
			else{
				if(start==0){
					start=e;
				}
				else{
					start++;
					while(start!=e){
						start++;
						life--;
						if(life<0) return false;
					}
				}
			}
		}
		return true;
    }
};



int main(){
	class Solution s;
	vector<int> numbers = {1,1,5,0,0};
	printf("%d\n", s.IsContinuous(numbers));
	return 0;
}
