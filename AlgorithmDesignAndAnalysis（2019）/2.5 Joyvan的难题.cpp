/*
�㷨�������� 2.5 Joyvan������
����Ŀ����
Joyvan���������һ������,����һ������
N������������a1,a2,����,aN�����壺f(i,j)=(j-i)2+(j��k=i+1 ak)2
����Joyvan��Ҫ�������������
f(i,j)(1<=i<j<=N)����Сֵ��

�������ʽ
����ĵ�һ��Ϊ����N����ʾ�������еĳ��ȡ�
�ڶ��а���N����������ʾ�����е�����a1,a2,����,aN��


�������ʽ
���һ��������������f(i,j)(1<=i<j<=N)����Сֵ��

����������
4
1 0 0 -1
���������
1
*/
/*
�Թ�ʽ���б���
���� xi=i��yi= i��k=1 ak
��ô f(i,j)=(xj-xi)2+(yj-yi)2
��ôҲ�����൱���ʾ������������

���ڵ�����������ʹ�ö��ַ��ҵ��������������

���԰ٶȡ�ƽ�������ԡ��������ҵ�ģ���� 

�����һά��һ����������������ҵ�����С���������أ�
	����һ�Ǳ�������Ҫ�Ƚϣ�n-1����������ȡ 
	�������ǰ�����ֵ��С����󣬱Ƚϣ�n-1���Σ���Ҫlogn��
		���Ƕ�ά�������ζ�����������벻��������������ò���
	���������Ƿ�����
		���Ƚ���ͼ����X���򡢷ֳ��������룬��ʱ���������������������������� 
			�������㶼������
			�������㶼���Ұ��
			��������һ������һ������
		����㷨����
			��֪ PL��PR �������ϵ������Ծ��� dl, dr���� P �������ԡ�
			������һ������������ 
			�������������� PL��PR �������ϵ���������֪���� lim = min(dl, dr)��
			PL��PR ֮���������ֻ���������ֱ�� l Ϊ���ģ���� 2lim �Ĵ�ֱ���������С�


ע��һ���ӣ�ҪС�����ݵķ�Χ��Ҫʹ��long�� 
�� Dist �������ƽ�������У�Ҫ��int��ǿ��ת��Ϊlong�� 
 */
 
#include<bits/stdc++.h>
#define sq(x) ((x)*(x))
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int n;
struct Point{
	int x, y;
	bool operator < (const Point &b) const {return y<b.y;}
}P[100005], tmp[100005]; 

long Dist(struct Point a, struct Point b){
	return sq(a.x-b.x) + sq(a.y-b.y);
}

int cmpy(struct Point a, struct Point b){
	return a.y<b.y;
}

long long  df(int L, int R){
	if(L>=R) return 0x3fffffff;
	if(L+1==R) return sq(P[L].x-P[R].x) + sq(P[L].y-P[R].y);
	
	int mid = (L+R)>>1;
	long lim = min(df(L, mid-1), df(mid+1, R));
	
//	int m=0;
//	for(int i=L; i<=R; ++i) if(sqr(i-mid)<=lim) tmp[m++]=P[i];
//	
//	sort(tmp, tmp+m);
	
	for(int i=0; i<m; ++i) 
		for(int j=i+1; j<m; ++j){
			long y_dist = sq(tmp[j].y-tmp[i].y)
			if(y_dist>lim) break;
			lim = min(lim, y_dist);
	}
	return lim;
}

int main(){
	int a, ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",&a);
		P[i].x = i;
		// P[i].y = P[i-1].y+a;
		ans += a;
		P[i].y = ans;
	}

	printf("%ld\n", df(1, n));
	return 0;
} 
/*
4
1 0 0 -1

2
1 2

2
1 3

3
0 3 -2
*/
