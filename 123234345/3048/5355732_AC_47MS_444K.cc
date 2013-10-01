#include<stdio.h>
#include<string.h>
#include<cmath>
bool flag[20001];
void prime()
{
     int max=int(sqrt(20001));
     memset(flag,true,sizeof(flag));     
     int i,j;
     for(i = 2;i<=max;i++)
        if(flag[i])
        {
           for(j=i*i;j<=20000;j+=i)
              flag[j]=false;
        }
}
int main()
{
    prime();
    int i,j,n,max=0,maxcow;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int cow;
        scanf("%d",&cow);
        for(j=cow;j>=1;j--)
          if(j<max||(flag[j]&&(cow%j==0))) break;
        if(j>max){max=j;maxcow=cow;}
    }
    printf("%d\n",maxcow);}
