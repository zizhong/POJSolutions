#include<stdio.h>
int pre[10001];
int main()
{
    int m,n,i,j,k,max,st=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&pre[i],&m);
        max=0;
        for(j=1;j<=m;j++)
        {
           scanf("%d",&k);
           max=max<pre[k]?pre[k]:max;
        }
        pre[i]+=max;
        st=st<pre[i]?pre[i]:st;
    }
    printf("%d\n",st);
    //getchar();getchar();
}
