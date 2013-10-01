#include<stdio.h>
#include<string.h>
const int N=1001;
bool c[N][N];
int n,m;
int lowbit(int x) {return x&(-x);}
void insert(int x,int y)
{
     while(x>0)
     {
          int t=y;
          while(t>0)
          {
               c[x][t]^=1;
               t-=lowbit(t);
          }
          x-=lowbit(x);
     }
}
int find(int x,int y)
{
    int ans=0;
    while(x<=n)
    {
         int t=y;
         while(t<=n)
         {
               ans^=c[x][t];
               t+=lowbit(t);
         }
         x+=lowbit(x);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        char s[4];
        int x1,y1,x2,y2;
        while(m--)
        {
              scanf("%s",s);
              if(s[0]=='C')
              {
                   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                   insert(x2,y2),insert(x1-1,y2),insert(x2,y1-1),insert(x1-1,y1-1);
              }
              else
              {
                  scanf("%d%d",&x1,&y1);
                  printf("%d\n",find(x1,y1));
              }
        }
        if(T) puts("");
    }
}
