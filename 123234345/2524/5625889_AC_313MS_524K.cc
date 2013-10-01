#include<stdio.h>
int pre[50002];
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
    int t=0,n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        int num=0,a,b,i;
        for(i=0;i<=n;i++) pre[i]=-1;
        while(m--)
        {
           scanf("%d%d",&a,&b);
           if(findset(a)!=findset(b))
              unionset(a,b);        
        }
       for(i=1;i<=n;i++)
           if(pre[i]<0) num++;
        t++;
        printf("Case %d: %d\n",t,num);
    }
}

