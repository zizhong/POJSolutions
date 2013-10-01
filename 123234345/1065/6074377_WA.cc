#include<stdio.h>
#include<stdlib.h>
const int N=5000;
struct Wood
{
       int l,w;
}w[N+1];
int cmp(const void *a,const void *b)
{
    Wood * p1=(Wood *)a;
    Wood * p2=(Wood *)b;
    return p1->l - p2->l?p1->l - p2->l:p1->w - p2->w;
}
int main()
{
    int nt;
    scanf("%d",&nt);
    while(nt--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&w[i].l,&w[i].w);
        qsort(w,n,sizeof(w[0]),cmp);
        w[n].l=w[n].w=10001;
        int ans=1,rl=w[0].l,mw=w[0].w;
        for(int i=1;i<=n;i++)
        {
             while(w[i].l==rl&&i<=n) i++;
             rl=w[i].l;
             if(mw>w[i].w) mw=w[i].w,ans++;
        }
        printf("%d\n",ans);
    }
}
