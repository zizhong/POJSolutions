#include<stdio.h>
#include<string.h>
const int INF=99999999;
int dis[232][232],link[31][16],vlink[31];
int k,c,m,s;
bool g[31][201],b[31];
void input()
{
     scanf("%d%d%d",&k,&c,&m);
     s=k+c;
     for(int i=0;i<s;++i)
        for(int j=0;j<s;j++)
        {
             scanf("%d",&dis[i][j]);
             if(dis[i][j]==0) dis[i][j]=INF;
        }
}
void floyd()
{
     for(int x=0;x<s;++x)
        for(int i=0;i<s;i++)
           for(int j=0;j<s;j++)
              if(dis[i][j]>dis[i][x]+dis[x][j])
                   dis[i][j]=dis[i][x]+dis[x][j];
}
bool findroad(int p)
{
     for(int i=0;i<k;i++)
        if(g[i][p]&&!b[i])
        {
             b[i]=true;
             if(vlink[i]<m)
             {
                   link[i][vlink[i]++]=p;
                   return true;
             }
             for(int j=0;j<vlink[i];++j)
                 if(findroad(link[i][j]))
                 {
                      link[i][j]=p;
                      return true;
                 }
        }
     return false;
}
bool isOK(int mid)
{
     int i,j;
     memset(g,0,sizeof(g)),
     memset(link,0,sizeof(link)),
     memset(vlink,0,sizeof(vlink));
     for(i=0;i<k;++i)
         for(j=k;j<s;++j)
            if(dis[i][j]<=mid)
              g[i][j-k]=1;
     for(i=0;i<c;i++)
     {
          memset(b,0,sizeof(b));
          if(!findroad(i))  return false;
     }
     return true;
}
void binary_search()
{
     int min,max,mid;
     min=max=0;
     for(int i=0;i<k;i++)
        for(int j=k;j<s;j++)
            if(dis[i][j]>max) max=dis[i][j];
     while(min<max)
     {
          mid=(min+max)>>1;
          if(isOK(mid)) max=mid;
          else min=mid+1;
     }
     printf("%d\n",max);
}
int main()
{
    input();
    floyd();
    binary_search();
    //input();
    return 0;
}
