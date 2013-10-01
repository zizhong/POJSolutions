#include<stdio.h>
int main()
{
    int t,x,m,d,s;
    while(scanf("%d%d%d",&t,&x,&m)==3)
    {
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
        if(tt==1||tt==0) {puts("0");continue;}
        ans=tt-1;
        ans+=(t-tt)/2+(t-tt)%2;
        printf("%d\n",ans*x);
    }
}
}
