#include<stdio.h>
#include<stdlib.h>
const int N=1001;
struct Node
{
       int i,v;
}song[N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a,*p2=(Node *)b;
    return p1->v - p2->v?p2->v - p1->v:p1->i - p2->i;
}
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&song[i].v),song[i].i=i+1;
    qsort(song,n,sizeof(song[0]),cmp);
    for(int i=0;i<t;i++)
        printf("%d\n",song[i%n].i);
    scanf("%'d");
}
