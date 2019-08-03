/*
不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215


这道题肯定使用二进制的运算来解决 
位运算
	与运算：& 
	或运算：| 
	非运算：~ 
	异或运算:^
	
位移操作符 
	按位右移: a>>1，二进制整体右移1位，左侧补1个零，数值变小为a/2 
	按位左移: a<<1，二进制整体左移1位，右侧补1个零，数值变大为a*2 
	
	
那么两位二进制数的加法换成位符运算就是不断的 异或（值等于不算进位） + 与且左移运算（值等于进位值）

例如：2+3 = 5

2的二进制：10           3的二进制：11            
	   
     	         求和

10和11异或：001      10和11与且右移一位：010

     	         求和
     
001和010异或：011    10和11与且右移一位：000

     	         求和
     
	             011
*/
#include<bits/stdc++.h> 

class Solution {
public:
    int Add(int num1, int num2) {
		while (num2!=0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;   }
};

int main(){
	class Solution solu;
	printf("%d\n", solu.Add(1,1));
	return 0; 
}
