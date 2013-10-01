#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=2001;
int father[N],mark[N],rank[N];
int find(int t)
{
    int tmp=t,flag=mark[t];
    while(father[tmp]!=tmp)
    {
        flag^=mark[father[tmp]];
        tmp=father[tmp];
    }
    father[t]=tmp;
    mark[t]=flag;
    return tmp;
}
int main()
{
    int i,T,cases=1;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        for(i=1;i<=N;i++)
        {
            father[i]=i;
            mark[i]=rank[i]=0;
        }
        int a,b,flag=0;
        while(M--)
        {
           scanf("%d%d",&a,&b);
           if(flag) continue;
           int x=find(a),y=find(b);
           if(x==y&&mark[a]==mark[b]) flag=1;
           else if(x!=y)
           {
                if(rank[x]<rank[y])
                {
                    father[x]=y;
                    mark[x]=!(mark[a]^mark[b]);
                }
                else
                {
                    father[y]=x;
                    mark[y]=!(mark[a]^mark[b]);
                    if(rank[x]==rank[y]) rank[x]++;
                }
           }
        }
        if(flag==1) 
            printf("Scenario #%d:\nSuspicious bugs found!\n\n",cases);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n",cases);
        cases++;
    }
}