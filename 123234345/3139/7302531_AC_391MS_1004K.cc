#include<stdio.h>
struct Node
{
       int d;
       Node *next;
}node[1000000],*num[10241];
int cnt[1<<16],nn;
int d[17];
int cntbit(int x)
{
    int res=0;
    while(x>0)
       res++,x/=2;
    return res;
}
int main()
{
    int T=0;
    while(scanf("%d",&d[0]),d[0])
    {
         for(int i=1;i<=15;i++) scanf("%d",&d[i]);
         for(int i=0;i<10241;i++) num[i]=NULL;
         for(int i=0;i<(1<<16);i++) cnt[i]=0;
         nn=0;
         for(int i1=0;i1<16;i1++)
            for(int i2=0;i2<16;i2++) if(i2!=i1)
                for(int i3=0;i3<16;i3++) if(i3 != i2 && i3 != i1)
                   for(int i4=0;i4<16;i4++) if(i4 !=i3 && i4 != i2 && i4 != i1)
                   {
                          int u=4*d[i1]+3*d[i2]+2*d[i3]+1*d[i4];
                          int idx=(1<<i1)|(1<<i2)|(1<<i3)|(1<<i4);
                          Node *p=&node[nn++];
                          p->d = idx;
                          p->next = num[u];
                          num[u] = p;
                   }
        for(int u=0;u<=10240;u++)
             for(Node *p=num[u];p&&p->next;p=p->next)
                  for(Node *p2=p->next;p2;p2=p2->next)
                  {
                       if((p->d) & (p2->d)) continue;
                       cnt[(p->d) | (p2->d)] +=2;
                  }
         __int64 ans=0;       
         for(int i=0;i<(1<<16);i++)
               if(cnt[i])
               {
                    ans+=(cnt[i]*cnt[0xffff&(~i)]);
               }
         printf("Case %d: %I64d\n",++T,ans/8);
    }
}
