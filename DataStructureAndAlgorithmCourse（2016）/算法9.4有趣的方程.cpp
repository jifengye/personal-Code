#include<cstdio>
#include<cstring>
using namespace std;
int hash[2000001];
 
int main(  )
{
    int n, a, b, c, d, i, j;
    scanf("%d",&n);
    while(n--)
    {
	    scanf("%d%d%d%d",&a,&b,&c,&d);
        if( a>0 && b>0 && c>0 && d>0 || a<0 && b<0 && c<0 && d<0 )
        {
            printf("0\n");
            continue;
        }
    
        memset(hash,0,2000001);
        for(i=1; i<=100; i++)
            for(j=1; j<=100; j++)
                hash[a*i*i+b*j*j+1000000]++;
        
        int count=0;
        for(i=1; i<=100; i++)
            for(j=1; j<=100; j++)
                count+=hash[1000000-c*i*i-d*j*j];
		printf("%d\n",count*16); 
    }
    return 0;
}
