#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
const int N=100;
vector<int >v[N];
int C[N],D[N],A[N],root,cut[N]; 
void dfs(int k,int f,int d)
{
     int tot,i,n=v[k].size();
     C[k]=1;
     D[k]=d;
     A[k]=d;
     tot=0;
     for(i=0;i<n;i++)
     {
         int t=v[k][i];
         if(t!=f&&C[t]==1)
                A[k]=A[k]<D[t]?A[k]:D[t];
         if(C[t]==0)
         {
              dfs(t,k,d+1);
              tot=tot+1;
              A[k]=A[k]<A[t]?A[k]:A[t];
              if((k==root&&tot>1)||(k!=root&&A[t]>=D[k]))
                   cut[k]=1;
         }
    }
    C[k]=2;
}
void Solve()
{
     memset(C,0,sizeof(C));
     memset(D,0,sizeof(D));
     memset(A,0,sizeof(A));
     memset(cut,0,sizeof(cut));
     root=1;
     dfs(1,1,0);
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         int st;
         for(int i=1;i<=n;i++) v[i].clear();
         while(scanf("%d",&st),st)
         {
              int ed;
              char c;
              while(scanf("%d%c",&ed,&c))
              {
                   v[st].push_back(ed);
                   v[ed].push_back(st);
                   if(c!=' ') break;
              }              
         }
         Solve();
         int Ncut=0;
         for(int i=1;i<=n;i++) if(cut[i]) Ncut++;
         printf("%d\n",Ncut);
    }
}
