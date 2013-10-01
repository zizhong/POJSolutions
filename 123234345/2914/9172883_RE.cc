#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int mat[1000][1000],res;
void Mincut(int n)
{
     int node[1000],dist[1000];
     bool visit[1000];
     int i,prev,maxj,j,k;
     for(int i=0;i<n;i++) node[i]=i;
     while(n>1)
     {
         int maxj=1;
         for(i=1;i<n;i++)
         {
              dist[node[i]]=mat[node[0]][node[i]];
              if(dist[node[i]]>dist[node[maxj]]) maxj=i;
         }
         prev=0;
         memset(visit,false,sizeof(visit));
         visit[node[0]]=true;
         for(i=1;i<n;i++)
         {
             if(i==n-1)
             {
                 res=min(res,dist[node[maxj]]);
                 for(k=0;k<n;k++)
                     mat[node[k]][node[prev]] =
                            (mat[node[prev]][node[k]] += mat[node[k]][node[maxj]]);
                     node[maxj]=node[--n];
             }         
             visit[node[maxj]]=true;
             prev=maxj;
             maxj=-1;
             for(j=1;j<n;j++) if(!visit[node[j]])
             {
                  dist[node[j]]+=mat[node[prev]][node[j]];
                  if(maxj == -1 || dist[maxj]<dist[node[j]])
                      maxj=j;
             }
         }
     }     
}
int main()
{
    int n,m,a,b,v,k;
    while(scanf("%d%d%d",&n,&m,&k),n)
    {
         res=0x7fffffff;
         memset(mat,0,sizeof(mat));
         while(m--)
         {
             scanf("%d%d%d",&a,&b,&v);
             --a,--b;
             mat[a][b]+=v,mat[b][a]+=v;
         }
         Mincut(n);
         printf("%d\n",res);
    }    
}
