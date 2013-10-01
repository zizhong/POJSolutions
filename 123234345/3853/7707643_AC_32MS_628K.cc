#include<stdio.h>
#include<queue>
using namespace std;
const int N=101;
int a[N][N];
int n,m;
int ans[2*N];
void solve()
{
     int cnt=0;
     int kk[N*N]={0};
     priority_queue <int > q;
     int key[2*N]={0};
     for(int i=1;i<=n;i++)
     {
          int j,k;
          for(j=1;j<=m;j++)
              for(k=j+1;k<=m;k++)
                  if(a[i][j]==a[i][k])
                       key[i]=a[i][j],kk[a[i][j]]=i;
     }
     for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
           for(int k=j+1;k<=n;k++)
               if(a[j][i]==a[k][i])
                  key[n+i]=a[j][i],kk[a[j][i]]=n+i;
     while(1)
     {
          int num=0;
          int p[2*N]={0};
          /*puts("-------");
          for(int i=1;i<=n;i++,puts(""))
              for(int j=1;j<=m;j++)
                  printf("%d ",a[i][j]);*/
          for(int i=1;i<=n;i++)
          {
               int j,s,k;
               for(j=1;j<=m&&a[i][j]==0;j++) ;
               if(j>m) continue;
               s=a[i][j];
               for(j=1;j<=m&&(a[i][j]==s||a[i][j]==0);j++) ;
               
               if(j>m&&(kk[s]==0||kk[s]==i))
               {
                    p[i]=1;
                    num++;
                    q.push(s);
               }                   
          }
          for(int i=1;i<=m;i++)
          {
                int j,s,k;
                for(j=1;j<=n&&a[j][i]==0;j++) ;                
                if(j>n) continue;
                s=a[j][i];
                for(j=1;j<=n&&(a[j][i]==s||a[j][i]==0);j++);                
                if(j>n&&(kk[s]==0||kk[s]==n+i))
                {
                   q.push(s);
                   num++;
                   p[n+i]=1;
                }
          }
          if(num==0) break;
          while(!q.empty())
             ans[cnt++]=q.top(),q.pop();
          for(int i=1;i<=n;i++)
               if(p[i]==1)
               for(int j=1;j<=m;j++)
                  a[i][j]=0;
          for(int j=1;j<=m;j++)
            if(p[n+j])
               for(int i=1;i<=n;i++)
                    a[i][j]=0;
          
     }
     for(int i=cnt-1;i>=0;i--)
        printf("%d%c",ans[i],i?' ':'\n');
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n)
    {
         for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
         solve(); 
    }
}
