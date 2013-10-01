#include<cstdio>
#include<cstring>
const int N=21,L=8,M=1077773,mod=M/30;
int n,m,len;
int map[N][N];
struct Holedox
{
     int step;  
     int x[L],y[L];
}org,q[mod];
int h[M],lv[M],lvl;
bool issame(Holedox &h1,Holedox &h2)
{
     for(int i=0;i<len;i++)
         if(h1.x[i]!=h2.x[i] || h1.y[i]!=h2.y[i])
             return false;
     return true;
}
int hash(Holedox & obj,int p)
{
    int key=1;
    for(int i=0;i<len;i++)
        key=(key*713+obj.x[i])%M,
        key=(key*713+obj.y[i])%M;
    while(lv[key]==lvl && !issame(obj,q[h[key]]))
        key=(key+1)%M;
    if(h[key]==lvl) return -1;
    h[key]=p,lv[key]=lvl;
    return key;
}
int d[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
    int T=0;
    while(scanf("%d%d%d",&n,&m,&len),n)
    {
         ++lvl;
         for(int i=0;i<len;i++) scanf("%d%d",&org.x[i],&org.y[i]);
         int tmp;
         scanf("%d",&tmp);
         memset(map,0,sizeof(map));
         while(tmp--)
         {
             int x,y;
             scanf("%d%d",&x,&y);
             map[x][y]=1;
         }
         org.step=0;
         int head=0,tail=0;
         q[tail++]=org;
         hash(org,0);
         printf("Case %d: ",++T);
         int flag=0;
         while(head!=tail)
         {
             Holedox cur=q[head++];
             head%=mod;
             //printf("<%d %d>:%d\n",cur.x[0],cur.y[0],cur.step);
             if(cur.x[0]==1 && cur.y[0]==1)
             {
                   printf("%d\n",cur.step);
                   flag=1;
                   break;
             }
             for(int k=0;k<4;k++)
             {
                  int nx=cur.x[0]+d[k][0],
                      ny=cur.y[0]+d[k][1];
                  if(nx<=0 || nx>n || ny<=0 ||ny>m|| map[nx][ny]) continue;
                  bool inbody=false;
                  for(int i=1;!inbody && i<len;i++) if(nx==cur.x[i]&&ny==cur.y[i])
                      inbody=true;
                  if(inbody) continue;
                  Holedox nh;
                  nh.step=cur.step+1;
                  nh.x[0]=nx,nh.y[0]=ny;
                  for(int i=0;i<len-1;i++) nh.x[i+1]=cur.x[i],nh.y[i+1]=cur.y[i];
                  if(hash(nh,tail)!=-1) q[tail++]=nh;
                  tail%=mod;
             }
         }
         if(!flag) puts("-1");
    }
}

