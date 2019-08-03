/*
孩子们的游戏(圆圈中最后剩下的数)
首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始
,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版 
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/
#include<bits/stdc++.h>

// class Solution {
// public:
//     int LastRemaining_Solution(int n, int m){
//    	 if(m==0)
//             return -1;
//         if(n==0)
//             return 0;
//    	
//         int a[n];
//		 for(int i=0; i<n; ++i){
//			 a[i]=1;
//		 } 

//		 int k=0,out=0, i; 
//		 for(i=0;out<n-1;i++){   
//			 if(a[i]) k++;
//			 if(k==m){
//				 a[i]=0;
//				 k=0;
//				 out++;
//			 }
//			 if(i==n-1) i=0;
//		 }
//		 for(i=0;a[i]==0;i++) ;
//		 return i;
//     }
// };

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n<1 || m <1) return -1;
        
		list<int> numbers;
        for(int i=0;i<n;i++)
            numbers.push_back(i);
        
		list<int>::iterator current=numbers.begin();
        while(numbers.size()>1) {
            for(int i=0;i<m-1;i++){//走m-1步
                ++current;
                if(current==numbers.end()) current=numbers.begin();
            }
             
            list<int>::iterator next=++current;
            if(next==numbers.end()) next=numbers.begin();
            --current;
            numbers.erase(current);
            current=next;
        }
        return *current;//对迭代器取值，等价于对指针取值
    }
};



int main(){
	class Solution solu;
	printf("%d\n",solu.LastRemaining_Solution(3,1));
	return 0;
}

