#include<stdio.h>
const int N=100000;
int v[N],pl[N],plen;
void table()
{
     for(int i=2;i<N;i++)
        if(!v[i])
        {
             pl[plen++]=i;
             for(int j=i+i;j<N;j+=i)
                 v[j]=1;
        }
}
int main()
{
    table();
    int m,a,b;
    while(scanf("%d%d%d",&m,&a,&b),m)
    {
         int ans=0,mi=0,mj=0;
         for(int i=0;i<plen;i++)
         {
             if(pl[i]*2>m) break;
             for(int j=0;j<=i;j++)
             {
                 if(pl[i]*pl[j]>m) break;
                 if(pl[j]*b>=pl[i]*a)
                 {
                    if(pl[i]*pl[j]>ans) ans=pl[i]*pl[j],mi=i,mj=j;
                 }
             }
         }
         printf("%d %d\n",pl[mj],pl[mi]);
    }
}
