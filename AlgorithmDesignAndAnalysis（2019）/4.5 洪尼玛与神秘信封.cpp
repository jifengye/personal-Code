/*
�㷨�������� 4.5 �������������ŷ�

�á� * ���滻�ɡ� o ����Ҫa�Ĵ��ۡ��滻�ɡ� x ����Ҫb�Ĵ��ۡ�
һ���ַ����Ϸ���Ҫ������������������
1.�ַ�������ǰ׺�ġ� o ���ĸ������벻С�ڡ� x ���ĸ�����
2.�ַ����ġ� o ���ĸ���������ڡ� x ���ĸ�����
��������֪�������еġ� * ���滻�ɡ� o ���� x ��ʹ�ø��ַ����Ϸ�����С�����Ƕ��٣�����޽����-1��

�������ʽ
��һ��Ϊһ���ַ���S����ʾ�ַ�����
������m�У�ÿ������������ai��bi����ʾ�滻�ɡ� o ������ x ������Ĵ��ۣ�
����60%�����ݣ��ַ������Ȳ�����1000��
����100%�����ݣ��ַ������Ȳ�����100000��0<=ai��bi<=108��

�������ʽ
���н⣬���һ������������ʾ��С���ۣ����޽⣬���-1��

����������
o**x
1 2
3 5
���������
5
*/
/*
scanf() ���ȡ�ַ����ݣ����ǻ��з����ڻ�������scanf��������������Ŀ��ַ�(�ո�tab���س������оͻ�ضϲ����\0) 
gets() ���ȡ���з������ǲ������ڱ����С�gets��Ҫ�Ȼس��Žض��ַ��������\0�� 

����˼�룬ֱ����ȵݹ飬ö�����з��� 
*/
//#include<bits/stdc++.h>
//using namespace std;
//char S[100005];
//int A[100005]={0};
//int B[100005]={0};
//long long res=0x3f3f3f3f;
//int n=0; 
//
////���� 
////void dfs(int step, int ans, int cost){
////	if(step==n){
////		if(ans==0) res=min(res, cost);
////		return;
////	} 
////	else if(S[step]=='o'){
////		dfs(step+1, ans+1, cost);
////	}
////	else if(S[step]=='x'){
////		dfs(step+1, ans-1, cost);
////	}
////	else if(S[step]=='*'){
////		dfs(step+1, ans+1, cost+A[step]);//��*��o
////		if(ans>0) dfs(step+1, ans-1, cost+B[step]);//��*��x
////	}
////}
//
////�����֦
////��֦1����cost����resʱ������������Է�����
////��֦2����ʣ���ַ�����С��ansʱ�򣬼�ʹ������ʣ���ַ���*��o��������x��Ҳ�޷�����o��x������ͬ������������Է����� 
//void dfs(int step, int ans, long long cost){
//	if(ans<0 || cost>=res || ans>n-step) return; //��֦
//	if(step==n){
//		if(ans==0) res=min(res, cost);
//		return;
//	} 
//	else if(S[step]=='o'){
//		dfs(step+1, ans+1, cost);
//	}
//	else if(S[step]=='x'){
//		dfs(step+1, ans-1, cost);
//	}
//	else if(S[step]=='*'){
//		dfs(step+1, ans+1, cost+A[step]);//��*��o
//		if(ans>0) dfs(step+1, ans-1, cost+B[step]);//��*��x
//	}
//}
//
//int main(){
//	gets(S);
//
//	for(int i=0; S[i]!='\0'; ++i){
//		++n;
//		if(S[i]=='*'){
//			scanf("%d%d",&A[i],&B[i]);
//						
//		}
//	}
//	
//	dfs(0, 0, 0);
//	
//	printf("%d\n",res==0x3f3f3f3f?-1:res);
//	return 0;
//}



/*
https://blog.csdn.net/f_zyj/article/details/74158391

���ȶ����Ż���̰�����⡣

qwb ���ж̶̼��仰������ڹ���������~~~%%%%%%%%%%%%
�տ�ʼ�� ? ȫ���� ) �滻��Ȼ���¼һ�� sum �� cnt��
�������ĳ��ʱ�� cnt<0����ô�Ͱ�֮ǰ�� ? ������� ) ��� ( ��Ҫ�ķ������ٵĸĳ� (���� cnt+=2��
��һ�����������ȶ�����ά����
*/ 
#include<bits/stdc++.h>
using namespace std;
int n;
char S[100005];
int A[100005]={0};
int B[100005]={0};
long long sum = 0; //��¼���� 
int cnt = 0; //��¼o��x�ĸ����� 
priority_queue<int> pqi;


long long fun(){
    for(int i=0; i<n; ++i){
        if(S[i] == 'o') ++cnt;
        else if(S[i]=='x' || S[i]=='*') --cnt;

        if(S[i]=='*') pqi.push(B[i]-A[i]);    //�滻ʱ��a[i] - b[i]���������ȳ�����ģ���ȡ��

        if(cnt < 0) {
            if(pqi.empty()) return -1;
            sum -= pqi.top();
            pqi.pop();
            cnt += 2;
        }
    }
    if (cnt != 0) return -1;
	return sum; 
}


int main(){
    scanf("%s", S);
    n = (int)strlen(S);

    for(int i=0; i<n; ++i){
        if(S[i]=='*'){
            scanf("%d%d",&A[i],&B[i]);
            sum += B[i];
        }
    }

    printf("%lld\n", fun());

    return 0;
}
/*
ooo**x
1 2
3 5

*oo**x
1 2
3 5
4 4

xoo**x
1 2
3 5
4 4
*/
