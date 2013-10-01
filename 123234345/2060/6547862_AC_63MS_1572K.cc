#include<stdio.h>
#include<string.h>
const int N=502,M=502;
int n,g[N][N],mv[N],t[N],d[N][4],vst[N],n_v[N];
int Abs(int a){return a>0?a:-a;}
int TM(int x1,int y1,int x2,int y2){return Abs(x1-x2)+Abs(y1-y2);}
int dfs(int nv)
{
    for(int i=0;i<n;i++)
       if(vst[i]==0&&g[nv][i])
       {
           vst[i]=1;
           if(mv[i]==-1||dfs(mv[i]))
           {
                mv[i]=nv;
                n_v[nv]=i;
                return 1;
           }
       }
    return 0;
}
int main()
{    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
             char s[8];
             scanf("%s%d%d%d%d",s,&d[i][0],&d[i][1],&d[i][2],&d[i][3]);
             t[i]=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
        }
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
              int t1=t[i]+TM(d[i][0],d[i][1],d[i][2],d[i][3]);
              for(int j=0;j<n;j++)
                  if((t1+TM(d[i][2],d[i][3],d[j][0],d[j][1]))<t[j])
                    g[i][j]=1;
        }
        int ans=0;
        memset(mv,-1,sizeof(mv));
        memset(n_v,-1,sizeof(n_v));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]&&mv[j]==-1) {n_v[i]=j,mv[j]=i,ans++;break;}
        for(int i=0;i<n;i++) if(n_v[i]==-1)
        {
             memset(vst,0,sizeof(vst));
             if(dfs(i)) ans++;
        }
        printf("%d\n",n-ans);
    }
}
