#include<stdio.h>
#include<stdlib.h>
const int N=25010;
struct Node
{
       int x,y;
}cow[N];
int n,t;
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a;
    Node *p2=(Node *)b;
    if(p1->x != p2->x) return p1->x - p2->x;
    return p1->y - p2->y;
}
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d%d",&cow[i].x,&cow[i].y);
    qsort(cow,n,sizeof(cow[0]),cmp);
    cow[n].x=t+2;
    int flag=-1,last=1,ans=0,max=0,ok=0;
    for(int i=0;i<=n;i++)
    {
         if(cow[i].x<=last)
         {
              if(cow[i].y>max) max=cow[i].y,flag=i;
         }
         else
         {
              if(flag==-1) break;
              ans++;
              if(max==t) {ok=1;break;}
              last=cow[flag].y+1;
              flag=-1;
              if(cow[i].x<=last&&cow[i].y>=max)
              {
                    flag=i;
                    max=cow[i].y;
              }
         }
         //printf("%d %d %d %d %d\n",flag,last,ans,max,ok);
    }
    printf("%d\n",ok?ans:-1);
    
}
