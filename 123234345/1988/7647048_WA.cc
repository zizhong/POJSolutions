#include<stdio.h>
const int N=30001;
int pre[N],at[N],h[N];
int find(int x)
{
    int t=pre[x];
    if(pre[x]==x) return x;
    pre[x]=find(pre[x]);
    h[x]+=h[t];
    return pre[x];
}
int main()
{
    for(int i=1;i<N;i++)
        pre[i]=i,at[i]=h[i]=0;
    int p;
    scanf("%d",&p);
    while(p--)
    {
        char s[2];
        int x,y;
        scanf("%s",s);
        if(s[0]=='M')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x=find(x),y=find(y);
            if(x==y) continue;
            pre[x]=y;
            h[x]=at[y]+1;
            at[y]=at[y]+at[x]+1;
        }
        else
        {
            scanf("%d",&x);
            /*int r=find(x);
            printf("%d %d %d %d\n",r,at[r],h[r],h[x]);*/
            printf("%d\n",h[x]);
        }
    }
}
