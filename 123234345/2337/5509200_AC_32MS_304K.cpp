#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,t;
int route[1000];
int io[26],adj[26][26];
bool vis[26][26],used[1000];
string dict[1000];
class List
{
      public:
             int head,
                 tail;
}L[1000];
void dfs(int v,int u)
{
     vis[v][u]=true;
     for(int i=0;i<26;i++)
        if(!vis[u][i]&&adj[u][i]) dfs(u,i);
}
bool legal(int v,int u)
{
     memset(vis,0,sizeof(vis));
     dfs(v,u);
     for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
          if(!vis[i][j]&&adj[i][j]) return false;
     return true;
}
int main()
{
    int i,j,l;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(L,0,sizeof(L));
        memset(adj,0,sizeof(adj));
        memset(io,0,sizeof(io));
        for(i=0;i<n;i++)
           cin>>dict[i];
        sort(dict,dict+n);
        for(i=0;i<n;i++)
        {
           L[i].head=dict[i][0]-'a';
           L[i].tail=dict[i][dict[i].length()-1]-'a';
           adj[L[i].head][L[i].tail]++;
           io[L[i].head]--,io[L[i].tail]++;
        }
        int head=-1,tail=-1;
        for(i=0;i<26;i++)
        {
           if(io[i]<0)
           {
             if(head==-1) head=i;
             else head=tail=-2;
           }
           else if(io[i]>0)
           {
              if(tail==-1) tail=i;
              else head=tail=-2;
           }
        }
        memset(used,0,sizeof(used));
        i=0;
        if(head!=-2)
        {
            if(head==-1) head=L[0].head;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   if(!used[j]&&L[j].head==head)
                   {
                       adj[L[j].head][L[j].tail]--;
                       if(legal(L[j].head,L[j].tail)) break;
                       adj[L[j].head][L[j].tail]++;
                   }
                }
                if(j==n) break;
                route[i]=j;
                used[j]=true;
                head=L[j].tail;
            }
        }
        if(i==n) 
        {
                 for(i=0;i<n-1;i++)
                    cout<<dict[route[i]]<<'.';
                 cout<<dict[route[n-1]]<<endl;
        }
        else cout<<"***"<<endl;
    }
}
