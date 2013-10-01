#include<stdio.h>
#include<string.h>
const int N=500;
int g[N][N],nv[N],mv[N],vst[N],r[N][N];
int n,m,ki,ii;
int dfs(int n_v,int level)
{
    for(int i=0;i<m;i++)
       if(vst[i]!=level&&g[n_v][i]==ii)
       {
            vst[i]=level;
            if(mv[i]||dfs(mv[i],level))
            {
                mv[i]=n_v;
                nv[n_v]=i;
                return 1;
            }
       }
    return 0;
}
int main()
{
    int ns;
    while(scanf("%d",&ns)!=EOF)
    {
         n=m=0;
         ii++;
         int sex[N]={0},n_num[N],m_num[N];
         memset(n_num,-1,sizeof(n_num));
         memset(m_num,-1,sizeof(m_num));
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         for(int x=0;x<ns;x++)
         {
              char s[10];
              int ni=0,y;
              scanf("%*s%s",s);
              for(int i=1;s[i]!=')';i++) ni=ni*10+s[i]-'0';
              if(ni&&!sex[x]) sex[x]=1;
              while(ni--)
              {
                   scanf("%d",&y);
                   sex[y]=sex[x]+1;
                   if(sex[y]>2) sex[y]=1;
                   if(sex[x]==1) r[x][y]=ii;
              }
         }
         for(int i=0;i<ns;i++)
         {
              if(sex[i]==1) n_num[n++]=i;
              else if(sex[i]==2) m_num[m++]=i;
         }
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                g[i][j]=r[n_num[i]][m_num[j]];
         int ans=0;
         for(int i=0;i<n;i++)
         {
              if(nv[i]==-1)
              {
                   ki++;
                   if(dfs(i,ki)) ans++;
              }
         }
         printf("%d\n",ns-ans);
    }
}
