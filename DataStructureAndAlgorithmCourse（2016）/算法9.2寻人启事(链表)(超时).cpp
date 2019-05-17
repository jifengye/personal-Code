#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Name
{    int elem;
     Name *next;
     Name( ){elem=0;next=NULL;}
}name[18280];

void create(Name *par, int x)
{    if(par->elem==0) par->elem=x;
      else
      {   while(par->next!=NULL) par=par->next;   
           Name *newp=new Name;
           newp->elem=x;
           par->next=newp;
      }
}

int quert(Name *par,int x)
{   while(par!=NULL)
    {    if(par->elem==x) return 1;
          par=par->next;
    }
    return 0;
}

int main( )
{     char temp[6];
      int n,m,count=0,x,y,i;
   //   memset(name,0,sizeof(Name)*18280);
      cin>>n>>m;
      while(n--)
      {    cin>>temp;
            for(i=strlen(temp)-1,x=y=0;i>=2;i--)
                        y+=(temp[i]%32)*pow(26,i-2);
            if(i==1)  x=(temp[1]%32)*26;
            x+=temp[0]%32;
            //cout<<y<<' '<<x<<endl;
            create(&name[y],x);
      }
      while(m--)
      {    cin>>temp;
            for(i=strlen(temp)-1,x=y=0;i>=2;i--)
                        y+=(temp[i]%32)*pow(26,i-2);
            if(i==1)   x=(temp[1]%32)*26;
            x+=temp[0]%32;
           // cout<<y<<' '<<x<<endl;
            if(quert(&name[y],x))  count++;
      }
      cout<<count<<endl;
      return 0;
}
/*
input
3 2
Tom
Alice
Jack
Jack
Ted
output
1

input
14 10
t
tt
tttt
attt
gets
void
long
zero
lette
qry
pba
book
zai
job
ttttt
OUT
zero
pqa
CV
max
zai
int
while
long
output
3

input
6 4
q
Zoret
doret
goret
Toret
Group
Q
ziret
Grou
tret
output
1

input
5 2
zzgki
zzgkb
zzgkm
zzgik
z
zzgk
zzgki
*/