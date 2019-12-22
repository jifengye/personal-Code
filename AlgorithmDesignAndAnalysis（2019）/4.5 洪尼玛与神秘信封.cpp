/*
算法设计与分析 4.5 洪尼玛与神秘信封

该“ * ”替换成“ o ”需要a的代价、替换成“ x ”需要b的代价。
一个字符串合法需要满足以下两个条件：
1.字符串所有前缀的“ o ”的个数必须不小于“ x ”的个数；
2.字符串的“ o ”的个数必须等于“ x ”的个数；
洪尼玛想知道将所有的“ * ”替换成“ o ”或“ x ”使得该字符串合法的最小代价是多少？如果无解输出-1。

★输入格式
第一行为一个字符串S，表示字符串；
接下来m行，每行两个正整数ai、bi，表示替换成“ o ”、“ x ”所需的代价；
对于60%的数据，字符串长度不大于1000；
对于100%的数据，字符串长度不大于100000，0<=ai、bi<=108。

★输出格式
若有解，输出一个正整数，表示最小代价；若无解，输出-1。

★样例输入
o**x
1 2
3 5
★样例输出
5
*/
/*
scanf() 会读取字符数据，但是换行符留在缓冲区。scanf碰到缓冲区里面的空字符(空格，tab，回车，换行就会截断并添加\0) 
gets() 会读取换行符，但是不会留在变量中。gets是要等回车才截断字符串并添加\0的 

暴力思想，直接深度递归，枚举所有方案 
*/
//#include<bits/stdc++.h>
//using namespace std;
//char S[100005];
//int A[100005]={0};
//int B[100005]={0};
//long long res=0x3f3f3f3f;
//int n=0; 
//
////暴力 
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
////		dfs(step+1, ans+1, cost+A[step]);//该*补o
////		if(ans>0) dfs(step+1, ans-1, cost+B[step]);//该*补x
////	}
////}
//
////加入剪枝
////剪枝1：当cost大于res时候，这个方案可以放弃了
////剪枝2：当剩余字符数量小于ans时候，即使将所有剩余字符（*或o）都换成x，也无法做到o和x数量相同，这个方案可以放弃了 
//void dfs(int step, int ans, long long cost){
//	if(ans<0 || cost>=res || ans>n-step) return; //剪枝
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
//		dfs(step+1, ans+1, cost+A[step]);//该*补o
//		if(ans>0) dfs(step+1, ans-1, cost+B[step]);//该*补x
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

优先队列优化的贪心问题。

qwb 大佬短短几句话就完美诠释了这道题~~~%%%%%%%%%%%%
刚开始把 ? 全部用 ) 替换。然后记录一下 sum 和 cnt。
如果遇到某个时候 cnt<0，那么就把之前的 ? 里面里从 ) 变成 ( 需要的费用最少的改成 (，并 cnt+=2。
这一步可以用优先队列来维护。
*/ 
#include<bits/stdc++.h>
using namespace std;
int n;
char S[100005];
int A[100005]={0};
int B[100005]={0};
long long sum = 0; //记录代价 
int cnt = 0; //记录o和x的个数差 
priority_queue<int> pqi;


long long fun(){
    for(int i=0; i<n; ++i){
        if(S[i] == 'o') ++cnt;
        else if(S[i]=='x' || S[i]=='*') --cnt;

        if(S[i]=='*') pqi.push(B[i]-A[i]);    //替换时，a[i] - b[i]，考虑优先出来大的，故取反

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
