#include<stdio.h>
#include<string.h>
const int MAXN=101;
int vst[MAXN];
struct Node
{
       int l,t,ed;
       Node *next;
}sp[MAXN*MAXN];
Node g[MAXN];
int rt,k,n,r;
int cnt=0;
void dfs(int st,int m,int len)
{
     for(Node *p=g[st].next;p;p=p->next)
     {
          if(!vst[p->ed]&&m+p->t<=k&&(len+p->l<rt||rt==-1))
          {
               if(p->ed==n)
               {
                   rt=(len+p->l);
                   continue;
               }
               vst[p->ed]=1;
               dfs(p->ed,m+p->t,len+p->l);
               vst[p->ed]=0;
          }
     }
}
int main()
{
    scanf("%d%d%d",&k,&n,&r);
    for(int i=0;i<r;i++)
    {
        int s;
        scanf("%d",&s);
        scanf("%d%d%d",&sp[cnt].ed,&sp[cnt].l,&sp[cnt].t);
        sp[cnt].next=g[s].next;
        g[s].next=&sp[cnt];
        cnt++; 
    }
    rt=-1;
    memset(vst,0,sizeof(vst));
    dfs(1,0,0);
    printf("%d\n",rt);
   // scanf("%d",&k);
    return 0;
}
