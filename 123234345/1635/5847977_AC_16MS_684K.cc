#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
const int Mod=9901,Max=3010,Mul=9110;
vector<int> adj[Max];
int father[Max],hash[Max];
bool cmp(int a, int b)
{
    return hash[a]<hash[b];
}
int rebuild(char *str)
{
    for(int i=0;i<Max;i++) adj[i].clear();
    for(int i=0,j=1,k=0;str[i];i++)
      if(str[i]=='0')
      {
        adj[k].push_back(j);
        father[j]=k;
        k=j;
        j++;
      }
      else k=father[k];
}
int dfs(int k)
{
    int val=0;
    if(adj[k].size()==0) val=1;
    else 
    {
    for(int i=0;i<adj[k].size();i++)
         {
              int j=adj[k][i];
              hash[j]=dfs(j);
         }
    sort(adj[k].begin(),adj[k].end(),cmp);
    val=1908;
    for(int i=0;i<adj[k].size();i++)
    {
         int j=adj[k][i];
         val=((val*Mul)^hash[j])%Mod;
    }
    }
    return val;
}
int main()
{
    int i,j,n;
    char s[Max];
    scanf("%d",&n);
    gets(s);
    while(n--)
    {
        int hash1,hash2;
        gets(s);
        rebuild(s);
        hash1=dfs(0);
        gets(s);
        rebuild(s);
        hash2=dfs(0);
        printf("%s\n",hash1==hash2?"same":"different");
    }
}
