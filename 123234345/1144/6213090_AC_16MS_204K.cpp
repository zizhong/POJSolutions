#include<stdio.h>
#include<string.h>
const int N=100;
int n,g[N][N],nn;
int C[N],D[N],A[N],root;
int cut[N],time; 
void dfs(int k,int f,int d)
{
     int i,tot=0;
     C[k]=1,D[k]=A[k]=d;
     for(i=1;i<=n;i++)
     {
           if(g[i][k]==nn&&i!=f&&C[i]==1)
                if(A[k]>D[i]) A[k]=D[i];
           if(g[i][k]==nn&&C[i]==0) 
           {
               dfs(i,k,d+1);
               tot++;
               if(A[k]>A[i]) A[k]=A[i];
               if((k!=root&&A[i]>=D[k])||(k==root&&tot>1)) cut[k]=1;
           }
     }
     C[k]=2;
}
void Solve()
{
     memset(cut,0,sizeof(cut));
     memset(C,0,sizeof(C));
     memset(D,0,sizeof(D));
     memset(A,0,sizeof(A));
     root=1,time=0;
     dfs(1,0,1);
}
int main()
{
    while(scanf("%d",&n),n)
    {
         int st;
         nn++;
         while(scanf("%d",&st),st)
         {
              int ed;
              char c;
              while(scanf("%d%c",&ed,&c))
              {
                   g[ed][st]=g[st][ed]=nn;
                   if(c!=' ') break;
              }              
         }
         Solve();
         int Ncut=0;
         for(int i=1;i<=n;i++) if(cut[i]) Ncut++;
         printf("%d\n",Ncut);
    }
}
