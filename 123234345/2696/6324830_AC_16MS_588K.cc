#include<stdio.h>
int phi[1001],vst[1001],v;
int a,b,c,d,e,f,g,h,i;
int dp(int i)
{
    if(vst[i]==v) return phi[i];
    if(i&1) phi[i]=((d*dp(i-1)+e*dp(i-2)-f*dp(i-3))%g+g)%g;
    else phi[i]=((f*dp(i-1)-d*dp(i-2)+e*dp(i-3))%h+h)%h;
    vst[i]=v;
    return phi[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {         
         v++;
         scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
         phi[0]=a,phi[1]=b,phi[2]=c;
         vst[0]=vst[1]=vst[2]=v;
         printf("%d\n",dp(i));
    }
}
