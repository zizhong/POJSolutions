#include<stdio.h>
const int N=101;
int d[N];
int main()
{
    int n,fac,max;
    scanf("%d%d",&n,&fac);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        if(i==1) max=d[i];
        else if(max<d[i]) max=d[i];
    }
    int ans=0;
    if(max<=0&&(fac&1))
    {
       ans=1;
       for(int i=0;i<fac;i++)
           ans*=max;
    }
    else
    {
              for(int i=1;i<=n;i++)
              {
                  int t;
                  if(fac==1) t=d[i];
                  else if(fac==2) t=d[i]*d[i];
                  else if(fac==3) t=d[i]*d[i]*d[i];
                  if(t>0) ans+=t; 
              }
    }
    printf("%d\n",ans);
    //scanf("%'d");
}
