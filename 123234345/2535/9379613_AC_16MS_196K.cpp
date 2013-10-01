#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int g[N][N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
             scanf("%d",&g[i][j]);
    bool sm[N];
    int num[N]={0};
    memset(sm,true,sizeof(sm));
    for(int i=0;i<n;i++)
    {            
        int mi=1100,ma=0;
        for(int j=0;j<m;j++)
        {
             mi=min(mi,g[i][j]);
             ma=max(ma,g[i][j]);
        }
        for(int j=0;j<m;j++) if(g[i][j]==mi) num[j]++;
        for(int j=0;j<m;j++) if(g[i][j]==ma) sm[j]=false;
    }
    int fir=0;
    for(int i=0;i<m;i++)
        if(sm[i] && num[i]>n/2)
        {
              if(fir) putchar(' ');fir=1;
              printf("%d",i+1);
        }
    puts(fir?"":"0");
}
