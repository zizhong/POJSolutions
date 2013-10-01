#include<stdio.h>
int main()
{
    int t,x,m,d,s;
    scanf("%d%d%d",&t,&x,&m);
    int tt=t*10;
    while(m--)
    {
         scanf("%d%d",&d,&s);
         int tmp=d/s-(d%s==0);
         if(tmp<tt) tt=tmp;
    }
    int ans=0;
    if(t<=tt) printf("%d\n",t*x);
    else
    {
        ans=tt-1;
        ans+=(t-tt)/2+(t-tt)%2;
        printf("%d\n",ans*x);
    }
}
