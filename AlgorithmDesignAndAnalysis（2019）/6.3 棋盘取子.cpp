/*
算法设计与分析 棋盘取子
★题目描述
有一个N行M列的棋盘，上面摆放有K个棋子，现在想要尽可能的从棋盘上取下这些棋子
但是棋盘的每行每列至多允许取一个棋子，请问最多能取多少棋子？

★输入格式
输入的第一行三个数字N,M,K(1<=N,M<=100,1<=K<=M*M)$，表示棋盘与棋子数。
接下来K行每行两个数字a,b(1<=a<=N,1<=b<=M)代表一个位于a行b列的棋子。

★输出格式
输出一个整数表示最多能取的棋子数目。

★样例输入
2 2 4
1 1
1 2
2 1
2 2
★样例输出
2
*/

/*
题目等价于：
	取出一颗棋子，与这颗棋子同行、同列的会被消掉
	那么如何尽可能多的拿出棋子 


【方案一】使用回溯法
每行的每个棋子都尝试过 

改进一：
	使用邻接表的思想存储，不用遍历整张表
	
改进二：
	从棋子最少的列开始取，有效降低复杂度 
	

【结果】失败	
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//int n,m,k;
//int Map[101][101];
//int vis[101]; //标志该列取过了，不能再取了 
//int res=0; 
//
//void dfs(int step, int cnt){
//	if(res==n) return; //这已经是能找到的最大值了，可以结束了 
//	
//	if(step>n){
//		res = max(cnt, res);
//		return;
//	}
//	
//	int j=0;
//	for(int j=0; Map[step][j]!=0; ){
//		j=Map[step][j];
//		if(vis[j]==0){
//			vis[j]=1;
//			dfs(step+1, cnt+1);
//			vis[j]=0;
//		}
//	} 
//	dfs(step+1, cnt);
//}
//
//
//void fun(int i, int j, int nj){
//	while(Map[i][j]!=0) j=Map[i][j];
//	Map[i][j]=nj;
//}
//
//int main(){
//	cin>>n>>m>>k;
//	int a,b;
//	memset(Map, 0, sizeof(Map));
//	memset(vis, 0, sizeof(vis));
//	while(k--){
//		cin>>a>>b;
//		fun(a, Map[a][0], b);
//	}
//	
//	dfs(0,0);
//	
//	printf("%d\n",res);
//	return 0;
//}
/*
2 2 4
1 1
1 2
2 1
2 2



3 3 3
1 3
2 3
3 3


3 3 3
1 3
2 2
3 3

5 1 3
1 1
2 1
3 1


1 5 3
1 2
1 3
1 5


5 6 8
1 1
2 2
1 5
4 3
2 5
3 3
1 6
4 6


*/


/*
【思路二】这题其实是二分图
先看下最大独立集的定义：
在Ｎ个点的图G中选出m个点，使这m个点两两之间没有边(没有某种关系)．求m最大值．
如果图Ｇ满足二分图条件，则可以用二分图匹配来做．最大独立集点数 = N - 最大匹配数。

“没有某种关系”在这题中就是指没用共同的行和列 

先解决最大匹配数的问题：https://www.acwing.com/problem/content/863/ 
*/ 

#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int H[501]; //记录节点连接的边的编号 
struct Edge{
	int end,nxt; 
}E[100001]; //按照编号记录边 

int Match[501];
int Visit[501];

int idx=0;
void AddEdge(int u, int v){ //用邻接表方式记录存稀疏图 
    idx++;
    E[idx].end = v;
    E[idx].nxt = H[u];
    H[u] = idx;
}


int find(int x) {
    for(int i=H[x]; i!=0; i=E[i].nxt) { //遍历与x相连的边 
        int e = E[i].end;
        if(!Visit[e]){ //如果在这一轮模拟匹配中,这个女孩尚未被预定
            Visit[e] = 1; //那x就预定这个女孩了
            if(Match[e]==0 || find(Match[e])) { //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
                Match[e] = x;
                return 1;
            }
        }
    }
    return 0;//自己中意的全部都被预定了。配对失败。
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	
	int u,v;
	memset(H, 0, sizeof(H));
	while(k--){
		scanf("%d%d",&u,&v);
		AddEdge(u, v);
	}
	
	int res=0;
	memset(Match, 0, sizeof(Match));
	for(int i=1; i<=n; i++) {
        memset(Visit,0,sizeof(Visit));//因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        res += find(i);
    }
    
    printf("%d\n",res);
    return 0;
} 
