#include<stdio.h>
#include<stdlib.h>
struct Node
{
     int x,y,v;
}pea[51*51];
int nn;
int cmp(const void *a,const void *b)
{
    return ((Node *)b)->v - ((Node *)a)->v;
}
int abs(int x){return x>0?x:-x;}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,nt;
        nn=0;
        scanf("%d%d%d",&n,&m,&nt);
        for(int i=1;i<=n;i++)
           for(int j=1;j<=m;j++)
           {
                scanf("%d",&pea[nn].v);
                if(pea[nn].v)
                {
                    pea[nn].x=i;
                    pea[nn].y=j;
                    nn++;
                }
           }
        qsort(pea,nn,sizeof(pea[0]),cmp);
        if(pea[0].x*2+1>nt)
        {
              puts("0");
              continue;
        }
        int ans=pea[0].v;
        nt-=pea[0].x+1;
        for(int i=1;i<nn;i++)
        {
             if(abs(pea[i-1].x-pea[i].x)+abs(pea[i-1].y-pea[i].y)+1+pea[i].x>nt) break;
             nt-=abs(pea[i-1].x-pea[i].x)+abs(pea[i-1].y-pea[i].y)+1;
             ans+=pea[i].v;
        }
        printf("%d\n",ans);
    }
}
