#include<cstdio>
#include<cstring>
const int N=110;
int q[N];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n,m;
         scanf("%d%d",&n,&m);
         for(int i=0;i<n;i++)
              scanf("%d",&q[i]);
         int ans=0;
         int st=0;
         while(1)
         {
              int max=0,mi;
              for(int i=0;i<n;i++) if(max<q[(i+st)%n]) max=q[(i+st)%n],mi=(i+st)%n;
              ans++;
              if(mi==m) break;
              if(mi<m) m--;
              st=mi;
              for(int i=mi;i<n-1;i++) q[i]=q[i+1];
              if(mi==n-1) st=0;
              n--;
         }
         printf("%d\n",ans);
    }
}
