#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=11;
struct Node{int d,i;}g[N];
int map[N][N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a;
    Node *p2=(Node *)b;
    return p1->d - p2->d; 
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++)
    {
          int n;
          scanf("%d",&n);
          for(int i=0;i<n;i++)
          {
               scanf("%d",&g[i].d);
               g[i].i=i;
          }
          memset(map,0,sizeof(map));
          int flag=0;
          for(int i=n-1;i>=0;i--)
          {
               qsort(g,i+1,sizeof(g[0]),cmp);
               //for(int j=0;j<i;j++) printf("%d ",g[j].d);
               //puts("");
               if(g[i].d>i||g[0].d<0) {flag=1;break;}
               for(int j=i-g[i].d;j<i;j++)
               {
                     g[j].d--;
                     map[g[i].i][g[j].i]=map[g[j].i][g[i].i]=1;
               }
               g[i].d=0;
          }
          qsort(g,n,sizeof(g[0]),cmp);
          if(g[0].d<0) flag=1;
          printf("%s%s\n",tt?"\n":"",flag?"NO":"YES");
          if(!flag)
          {
                   for(int i=0;i<n;i++)
                      for(int j=0;j<n;j++)
                          printf("%d%c",map[i][j],j==n-1?'\n':' ');
          }
    }
}
