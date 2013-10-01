#include<stdio.h>
#include<stdlib.h>
const int N=5000;
struct Wood
{
       int l,w;
}w[N+1];
int used[N];
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
            scanf("%d%d",&w[i].l,&w[i].w),used[i]=0;
        qsort(w,n,sizeof(w[0]),cmp);
        int ans=0,mi=0;
        for(int i=0;i<n;i++)
        {
              if(!used[i])
              {
                    used[i]=1;
                    ans++;
                    mi=i;
                    for(int j=i+1;j<n;j++)
                    {
                         if(!used[j]&&w[mi].w<=w[j].w)
                         {
                               used[j]=1;
                               mi=j;
                         }
                    }
              }
        }
        printf("%d\n",ans);
    }
}
