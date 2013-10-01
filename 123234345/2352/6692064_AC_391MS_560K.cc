#include<stdio.h>
const int N=15000,M=32002;
int star[M],lev[N];
int lowbit(int n)
{
    return n & (-n);
}
int sum(int n)
{
    int r=0;
    while(n)
    {
        r += star[n];
        n-=lowbit(n);
    }
    return r;
}
void update(int n)
{
     while(n < M)
     {
           star[n]++;
           n += lowbit(n);
     }
}
int main()
{
    int n,x,y,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         scanf("%d%d",&x,&y);
         lev[sum(x+1)]++;
         update(x+1);
    }
    for(i=0;i<n;i++)
        printf("%d\n",lev[i]);
}
