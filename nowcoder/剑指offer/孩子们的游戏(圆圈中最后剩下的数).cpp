/*
�����ǵ���Ϸ(ԲȦ�����ʣ�µ���)
����,��С������Χ��һ����Ȧ��
Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ
,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ� 
������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
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
            for(int i=0;i<m-1;i++){//��m-1��
                ++current;
                if(current==numbers.end()) current=numbers.begin();
            }
             
            list<int>::iterator next=++current;
            if(next==numbers.end()) next=numbers.begin();
            --current;
            numbers.erase(current);
            current=next;
        }
        return *current;//�Ե�����ȡֵ���ȼ��ڶ�ָ��ȡֵ
    }
};



int main(){
	class Solution solu;
	printf("%d\n",solu.LastRemaining_Solution(3,1));
	return 0;
}

