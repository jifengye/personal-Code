#include<bits/stdc++.h>
using namespace std;

int N; 
int a[100];
 
int main(){
    cin>>N;
    
    printf("1 Ë³×ÖµäÐò=================\n");
    for(int i=1; i<=N; ++i) a[i]=i;
    do {
		for(int i=1; i<=N; ++i) cout<<a[i]<<" ";
		cout<<endl;
	} while(next_permutation(a+1,a+N+1));

	printf("2 Äæ×ÖµäÐò=================\n");
	reverse(a+1,a+N+1);
  	do{
		for(int i=1; i<=N; ++i) cout<<a[i]<<" ";
		cout<<endl;
    }while(prev_permutation(a+1,a+N+1));


    return 0;
}
