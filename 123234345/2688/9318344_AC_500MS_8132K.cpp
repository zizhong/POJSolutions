#include<cstdio>
#include<cstring>
const int inf=0x3fffffff;
int dp[1<<10][21][21],d[][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[21][21];
int num[21][21],cnt;
struct Node
{
       int x,y,s,step;
       Node(int i=0,int j=0,int k=0,int st=0): x(i),y(j),s(k),step(st){}
}q[1024*21*21];
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%s",map[i]);
         cnt=0;
         int sx,sy;
         for(int i=0;i<n;i++)
              for(int j=0;j<m;j++)
              {
                  if(map[i][j]=='o') sx=i,sy=j;
                  if(map[i][j]=='*') num[i][j]=cnt++;
              }
         int K=(1<<cnt)-1;
         for(int i=0;i<1<<cnt;i++)
             for(int j=0;j<n;j++)
                 for(int k=0;k<m;k++)
                      dp[i][j][k]=inf;
         dp[K][sx][sy]=0;
         int head=0,tail=0;
         q[tail++]=Node(sx,sy,K,0);
         while(head<tail)
         {          
               Node cur=q[head++];
               //printf("%d %d %d %d\n",cur.x,cur.y,cur.s,cur.step);
               for(int k=0;k<4;k++)
               {
                   int nx=cur.x+d[k][0],ny=cur.y+d[k][1];
                   if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]=='x') continue;
                   int np=cur.s;
                   if(map[nx][ny]=='*'&&((np>>num[nx][ny])&1)) np^=(1<<num[nx][ny]);
                   if(dp[np][nx][ny]<=cur.step+1) continue;
                   dp[np][nx][ny]=cur.step+1;
                   q[tail++]=Node(nx,ny,np,cur.step+1);
               }
         }
         int ans=inf;
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                if(ans>dp[0][i][j])
                    ans=dp[0][i][j];
         printf("%d\n",ans==inf?-1:ans);
    }
}
