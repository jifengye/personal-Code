#include<iostream>
#include<cmath>
using namespace std;
int s[100003],N;

void quicksort(int left,int right)
{  int i,j,t,temp;
   if(left>right) return;//�ݹ������־ 
   
   temp=s[left];//temp���׼��
    
   i=left;//������׼�� 
   j=right;
   while(i!=j)
   {   while(s[j]>=temp && i<j)  j--;
       while(s[i]<=temp && i<j)  i++; 
	   if(i<j)
	   {   t=s[j];
	       s[j]=s[i];
	       s[i]=t;
		}
	}
	
	s[left]=s[i];//��׼����λ 
	s[i]=temp;
   
   quicksort(left,i-1);
   quicksort(i+1,right);
    
}


int main()
{    cin>>N;
     s[0] = 0;
     int temp,i,min;
     for(i=1;i<=N;i++)
     {    cin>>temp;
          s[i]=s[i-1]+temp;
     }
     /*ǰ׺�����ʣ�s[j]-s[i]��ʾi~j�ĺ�*/
     
     quicksort(0,N);
     
     for(i=1,min=abs(s[1]-s[0]);i<=N;++i )
     {    temp=abs(s[i]-s[i-1]);
          if(temp<min)  min=temp;
     }
     cout<<min<<endl;
     return 0;
}
