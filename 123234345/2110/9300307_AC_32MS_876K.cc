#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100,d[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int h[N][N];
int n,L,H,l1,h1;
bool vst[N][N];
bool dfs(int x,int y)
{
    // printf("<%d %d %d %d>\n",x,y,l1,h1);
     if(x==n-1 && y==n-1) return true;
     for(int k=0;k<4;k++)
     {
          int nx=x+d[k][0],ny=y+d[k][1];
          if(nx<0||nx>=n||ny<0||ny>=n||vst[nx][ny]||l1>h[nx][ny]||h[nx][ny]>h1) continue;
          vst[nx][ny]=true;
          if(dfs(nx,ny)) return true; 
          //vst[nx][ny]=false;
     }
     return false;
}
bool ok(int x)
{     
     if(x<0) return false;
     if(x>=H-L) return true;
     for(int ll=L;ll+x<=H;ll++) 
          if(h[0][0]>=ll && h[0][0]<=ll+x &&
             h[n-1][n-1]>=ll && h[n-1][n-1]<=ll+x)
             {
                   memset(vst,false,sizeof(vst));
                   vst[0][0]=true;
                   l1=ll,h1=ll+x;
                   if(dfs(0,0)) return true;
             }
     return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    L=111,H=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       {
            scanf("%d",&h[i][j]);
            L=min(L,h[i][j]);
            H=max(H,h[i][j]);
       }
    int l=-1,r=110;
    while(l+1<r)
    {
         int mid=l+r>>1;
         if(ok(mid)) r=mid;
         else l=mid;
    }
    printf("%d\n",r);
    //scanf("%'d");
}
