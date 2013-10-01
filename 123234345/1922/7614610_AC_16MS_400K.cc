#include<stdio.h>
#include<math.h>
const int N=10001,inf=0xfffffff;
int main()
{
    int n;
    double tt[41];
    for(int i=1;i<=40;i++)
          tt[i]=4500*3.6/i;
    while(scanf("%d",&n),n)
    {
         int st[41]={0};
         for(int i=1;i<41;i++) st[i]=inf;
         for(int i=0;i<n;i++)
         {
             int t,v;
             scanf("%d%d",&v,&t);
             if(t>=0&&st[v]>t) st[v]=t;
         }
         int min=inf;
         for(int i=1;i<=40;i++)
         {
              int cur=(int)ceil(st[i]+tt[i]);
              if(cur<min) min=cur;
         }
         printf("%d\n",min);
    }
}
