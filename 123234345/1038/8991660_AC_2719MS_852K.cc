#include<cstdio>
#include<cstring>
const int N=160,M=64,S=59100;
int n,m,nb;
int bad[N],f[2][S];
int x,y,st[16];
int code23(const int b[],int x)
{
    int a[16];
    memcpy(a,b,sizeof(a));
    for(int i=0;i<m;i++)
    {
         a[i]--;
         if(a[i]<0) a[i]=0;
    }
    for(int i=0;i<m;i++)
       if((x>>i)&1) a[i]=2;
    int ret=0;
    for(int i=m-1;i>=0;i--) ret=ret*3+a[i];
    return ret;
}
void decode2st(int *a,int p)
{
     for(int i=0;i<m;i++)
     {
           a[i]=p%3;
           p/=3;
     }
}
int now;
void dfs(int c,int k,int p)
{
     //printf("%d %d %d\n",c,k,p);
     if(c==m)
     {
           //printf("%d %d\n",x,k); 
           //for(int i=0;i<m;i++) printf("%d ",st[i]);puts("");
           int t=code23(st,p);//decode2st(st,t);for(int i=0;i<m;i++) printf("%d ",st[i]);puts("");
           if(f[now][t]<f[now^1][y]+k)
               f[now][t]=f[now^1][y]+k;
           return ;
     }
     dfs(c+1,k,p);
     if(c>m-2|| st[c]==2|| st[c+1]==2 ||(p>>c)&1 || (p>>(c+1))&1 ) return ;
     if(st[c]==0 && st[c+1]==0)
           dfs(c+2,k+1,p+(3<<c)); 
     if(c>m-3 ||st[c+2]==2 || (p>>(c+2))&1 ) return ;
     dfs(c+3,k+1,p+(7<<c));
}
int main()
{    int T;
    for(scanf("%d",&T);T--;)
    {
         scanf("%d%d%d",&n,&m,&nb);
         memset(bad,0,sizeof(bad));
         for(int i=0;i<nb;i++)
         {
             int x,y;
             scanf("%d%d",&x,&y);
             bad[x-1]|=(1<<(y-1));
         }
         memset(f,-1,sizeof(f));
         for(int i=0;i<m;i++) st[i]=2;
         f[1][code23(st,bad[0])]=0;
         int t=code23(st,bad[0]);
         decode2st(st,t);
         //for(int i=0;i<m;i++) printf("%d ",st[i]);puts("");
         int K=1;
         for(int i=0;i<m;i++) K*=3;
         now=0;
         for(x=1;x<n;x++)
         {
              memset(f[now],-1,sizeof(f[now]));
              for(y=0;y<K;y++) if(f[now^1][y]!=-1)
              {
                   decode2st(st,y);
                   dfs(0,0,bad[x]);
              }
              now^=1;
         }
         int ans=0;
         for(int j=0;j<K;j++)
            if(ans<f[now^1][j]) ans=f[now^1][j];
         printf("%d\n",ans);
    }
}
