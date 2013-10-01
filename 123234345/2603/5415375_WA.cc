#include<stdio.h>
#include<string.h>
#include<cmath>
#include<iostream>
using namespace std;
bool flag[10000];
//int prime[1500];
void table()
{
     int i,j;
     memset(flag,true,sizeof(flag));
     for(i=2;i<100;i++)
        if(flag[i])
        for(j=i*i;j<10000;j+=i)
           flag[j]=false;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    table();
    int t=10,n,num=1,i;
    int f[10000]={0};
    while(t--)
    {
        cin>>n;
        for(i=2;i<=n;i++)
        {
            if(!flag[i]) continue;
            while(n%i==0)
            {
               n/=i;
               f[i]++;
            }
        }
    }
    for(i=2;i<10000;i++)
    {
        if(f[i]) num=num%10*(f[i]+1)%10;
    }
    printf("%d\n",num%10);
}
