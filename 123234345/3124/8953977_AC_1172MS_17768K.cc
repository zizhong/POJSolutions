#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2110,inf=0x3fffffff;
int f[N][N];
struct Node{int h,t;}book[128];
int max(int a,int b){return a>b?a:b;}
bool cmp(const Node &a,const Node &b)
{
     return a.h>b.h;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n,len=0;
         scanf("%d",&n);
         for(int i=0;i<n;i++)
         {
              scanf("%d%d",&book[i].h,&book[i].t);
              len+=book[i].t;
         }
         sort(book,book+n,cmp);
         for(int i=0;i<=len;i++) for(int j=0;j<=len;j++)
             f[i][j]=inf;
         f[0][0]=0;
         len=0;
         for(int k=1;k<n;k++)
         {
               len+=book[k].t;
               for(int i=len;i>=0;i--) 
                   for(int j=len;j>=0;j--) if(f[i][j]!=inf)
                   {
                        if(i==0&&j==0)
                        {
                             f[0][book[k].t]=book[k].h;
                             f[book[k].t][0]=book[k].h;
                        }
                        if(i==0&&j)
                        {
                             if(f[book[k].t][j]>f[0][j]+book[k].h) f[book[k].t][j]=f[0][j]+book[k].h;
                             if(f[0][j+book[k].t]>f[0][j]) f[0][j+book[k].t]=f[0][j];
                        }
                        if(i&&j==0)
                        {
                             if(f[i][book[k].t]>f[i][j]+book[k].h) f[i][book[k].t]=f[i][j]+book[k].h;
                             if(f[i+book[k].t][0]>f[i][0]) f[i+book[k].t][0]=f[i][0];
                        }
                        if(i&&j)
                        {
                             if(f[i+book[k].t][j]>f[i][j]) f[i+book[k].t][j]=f[i][j];
                             if(f[i][j+book[k].t]>f[i][j]) f[i][j+book[k].t]=f[i][j];
                        }
                   }
               }
         int ans=inf;
         for(int i=1;i<=len;i++)
            for(int j=1;j<=len;j++) if(f[i][j]<inf)
            {
                 if(ans>(book[0].h+f[i][j])*max(len+book[0].t-i-j,max(i,j)))
                      ans=(book[0].h+f[i][j])*max(len+book[0].t-i-j,max(i,j));
            }
         printf("%d\n",ans);
    }
}
