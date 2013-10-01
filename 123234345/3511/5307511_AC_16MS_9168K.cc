#include<stdio.h>
#include<cmath>
#include<string.h>
const int MAX=1000000;
bool flag[MAX+1];
int prm[MAX+1];
int xprm[MAX+1];
void prime()
{
     int max=int(sqrt(MAX)),i,j;
     memset(flag,true,sizeof(flag));
     flag[0]=flag[1]=false;
     for(i=2;i<=max;i++)
         if(flag[i])
         {
            for(j=i*i;j<=MAX;j+=i)
                flag[j]=false;
         }
}
void maket()
{
     int i;
     for(i=1;i<=MAX;i++)
     {
         if(flag[i])
         {
            prm[i]=prm[i-1]+1;
            if((i-1)%4==0||i==2) xprm[i]=xprm[i-1]+1;
            else xprm[i]=xprm[i-1];
         }
         else xprm[i]=xprm[i-1],prm[i]=prm[i-1];
     }
}
int main()
{
    prime();
    maket();
    int l,u;
    while(scanf("%d%d",&l,&u)+1)
    {
        if(l==-1&&u==-1) break;
        int x=0,y=0;
        int i;
        if(l>=0)
        {
             x=prm[u]-prm[l-1];
             y=xprm[u]-xprm[l-1];
        }
        else if(u>0)
        {
             x=prm[u];
             y=xprm[u];
        }
        printf("%d %d %d %d\n",l,u,x,y);
    }
}