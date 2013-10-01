#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
const int N=500;
vector<int> g[N];
int match[N],n,vst[N];
bool Hungary(int u)
{
     for(vector<int>::size_type tx=0;tx<g[u].size();tx++)
     {
           int v=g[u][tx];
           if(!vst[v])
           {
                vst[v]=1;
                if(match[v]==-1||Hungary(match[v]))
                {
                      match[u]=v;
                      match[v]=u;
                      return true;
                }
           }
     }
     return false;
}
int max_match()
{
    int ans=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<n;i++)
    {
         if(match[i]==-1)
         {
               memset(vst,0,sizeof(vst));
               vst[i]=1;
               if(g[i].size()>0&&Hungary(i)) ans++;
         }
    }
    return ans;
}
int main()
{
    int m;
    while(scanf("%d",&n)!=EOF)
    {         
         for(int i=0;i<n;i++) g[i].clear();
         for(int v=0;v<n;v++)
         {
              scanf("%*s (%d)",&m);
              while(m--)
              {
                   int u;
                   scanf("%d",&u);
                   g[u].push_back(v);
                   g[v].push_back(u);
              }
         }
         printf("%d\n",n-max_match());                 
    }
}
