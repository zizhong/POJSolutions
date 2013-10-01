#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100,d[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int h[N][N];
int n,L,H;
bool vst[N][N];
bool dfs(int x,int y,int l1,int h1,int delta,int dep)
{
     if(x==n-1 && y==n-1) return true;
     if(dep>=n*n || h1-l1>delta) return false;
     for(int k=0;k<4;k++)
     {
          int nx=x+d[k][0],ny=y+d[k][1];
          int nl=min(l1,h[nx][ny]),nh=max(h1,h[nx][ny]);
          if(nx<0||nx>=n||ny<0||ny>=n||nh-nl>delta||vst[nx][ny]) continue;
          vst[nx][ny]=true;
          if(dfs(nx,ny,nl,nh,delta,dep+1)) return true; 
          vst[nx][ny]=false;
     }
     return false;
}
bool ok(int x)
{     
     if(x<0) return false;
     memset(vst,false,sizeof(vst));
     vst[0][0]=true;
     return dfs(0,0,h[0][0],h[0][0],x,0);
}
int main()
{
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
