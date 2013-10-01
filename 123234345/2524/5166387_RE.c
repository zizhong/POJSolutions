#include<stdio.h>
int pre[50001];
int findset(int x)
{
    int i=x;
    while(pre[x]>0)
        x=pre[x];
    while(i!=x)
    {
        int j=pre[i];
        pre[i]=x;
        i=j;
    }
    return i;
}
void unionset(int a,int b)
{
     int roota=findset(a),rootb=findset(b);
     int sum=pre[roota]+pre[rootb];
     if(pre[roota]<pre[rootb])
     {
         pre[rootb]=roota;
         pre[roota]=sum;
     }
     else
     {
         pre[roota]=rootb;
         pre[rootb]=sum;
     }
     
}
int main()
{
    int t=0,n;
    while(scanf("%d",&n)&&n)
    {
        int num=0,m,a,b,i;
        memset(pre,-1,sizeof(pre));
        scanf("%d",&m);
        while(m--)
        {
           scanf("%d%d",&a,&b);
           unionset(a,b);
        }
        for(i=1;i<=n;i++)
           if(pre[i]<0) num++;
        t++;
        printf("Case %d: %d\n",t,num);
    }
}
