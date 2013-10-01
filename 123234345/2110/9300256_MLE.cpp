#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=128,d[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int h[N][N];
struct Node
{
       int x,y,l,h;
       Node(int i=0,int j=0,int ll=0,int hh=0): x(i),y(j),l(ll),h(hh){}
}q[N*N];
int n,L,H;
bool vst[N][N][N][N];
bool ok(int x)
{
     if(x<0) return false;
     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
             for(int h1=L;h1<=H;h1++)
                for(int h2=L;h2<=H;h2++)
                      vst[i][j][h1][h2]=false;
     int head=0,tail=0;
     q[tail++]=Node(0,0,h[0][0],h[0][0]);
     vst[0][0][h[0][0]][h[0][0]]=true;
     while(head<tail)
     {
           Node cur=q[head++];
           for(int k=0;k<4;k++)
           {
                int nx=cur.x+d[k][0],ny=cur.y+d[k][1];
                int nl=min(cur.l,h[nx][ny]),nh=max(cur.h,h[nx][ny]);
                if(nx<0||nx>=n||ny<0||ny>=n||vst[nx][ny][nl][nh]) continue; 
                if(nh-nl>x) continue;
                vst[nx][ny][nl][nh]=true;
                q[tail++]=Node(nx,ny,nl,nh);
                if(nx==n-1 && ny==n-1) return true;
           }
     }
     return false;
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
    int l=-1,r=256;
    while(l+1<r)
    {
         int mid=l+r>>1;
         if(ok(mid)) r=mid;
         else l=mid;
    }
    printf("%d\n",r);
    //scanf("%'d");
}
