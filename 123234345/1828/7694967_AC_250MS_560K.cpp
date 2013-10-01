#include<stdio.h>
#include<stdlib.h>
const int N=50001;
struct Node
{
       int x,y;
}d[N],d2[N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a;
    Node *p2=(Node *)b;
    return p1->x - p2->x?p1->x - p2->x:p1->y - p2->y;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
             scanf("%d%d",&d[i].x,&d[i].y);
        }
        qsort(d,n,sizeof(d[0]),cmp);
        int ans=1;
        int my=d[n-1].y;
        for(int i=n-2;i>=0;i--) if(d[i].x!=d[i+1].x)
        {
            if(my<d[i].y)
            {
                 ans++;
                 my=d[i].y;
            }
        }
        printf("%d\n",ans);
    }
}
