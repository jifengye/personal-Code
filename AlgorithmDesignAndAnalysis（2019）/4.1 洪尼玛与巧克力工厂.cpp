/*
�㷨�������� 4.1 ���������ɿ�������
����Ŀ����
��������ɿ�������׼������n�����������i������1���ɿ����Ļ���ΪciԪ����i����Ҫ�������ͻ�ai���ɿ�����

��������һ��������Դ�����޶���ɿ�������֤�ɿ������ỵ���������Ǵ��ÿ���ɿ���ÿ��Ļ���ΪsԪ��

��������֪�������n�����ж�������С�����Ƕ��٣�


�������ʽ
��һ��Ϊ����������n��s����ʾ�������ʹ洢ÿ���ɿ���ÿ��Ļ��ѣ�

������n�У�ÿ������������ci��ai����ʾ��i������1���ɿ����Ļ��Ѻ���Ҫ�������ͻ����ɿ���������

����60%�����ݣ�1<=n<=103��

����100%�����ݣ�1<=n<=106��1<=s<=102��1<=ci��ai<=103��


�������ʽ
���һ������������ʾ��С���ѡ�


����������
3 1
1 1
3 2
2 3
���������
11
*/

/*
���赱ǰʱ�� cnt �� 
��i������1�����軨�� p = ci + (cnt-i)*s  
*/

#include<bits/stdc++.h>
using namespace std;

int n,s;
int c_min=0X3FFFFF;
long ans=0;

int main(){
	scanf("%d%d",&n,&s);
	
	int c, a;
	for(int i=0; i<n; i++){
		scanf("%d%d",&c,&a);
		c_min = min(c_min+s, c);
		ans += a*c_min;
	} 
	
	printf("%ld\n",ans);
	return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAX = 1000000 + 5;
//int a,c;
//
//int main(){
//  int c1, n, s, temp;
//  long long sum = 0;
//  scanf("%d%d",&n,&s);
//  scanf("%d %d", &c, &a);
//  sum = c * a;
//  temp = c;
//  for(int i = 1;i < n; i++){
//    scanf("%d %d", &c, &a);
//    temp = min(c, temp+s);
//    sum += temp * a;
//  }
// 
//  printf("%lld\n",sum);
//
//  return 0;
//}

