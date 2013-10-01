#include<stdio.h>
#include<stdlib.h>
const int N=10001;
struct Node{int d,v;}ht[N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a;
    Node *p2=(Node *)b;
    return p1->d - p2->d?p1->d - p2->d:p1->v - p2->v;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
            scanf("%d%d",&ht[i].d,&ht[i].v);
         qsort(ht,n,sizeof(ht[0]),cmp);
         int sum=1,min=ht[0].v;
         for(int i=1;i<n;i++)
             if(ht[i].v<min)
             {
                sum++;
                min=ht[i].v;
             }
         printf("%d\n",sum);
    }
}
