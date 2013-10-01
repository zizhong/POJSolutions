#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=50010,inf=0x3fffffff;
vector<int>tree[N];
int ans,st[N],top;
int after[N];
int n;
void dfs(int x,int pre)
{
     after[x]=1;
     int max=inf;
     for(int i=0;i<tree[x].size();i++) if(tree[x][i]!=pre)
     {
           dfs(tree[x][i],x);
           after[x]+=after[tree[x][i]];
           if(max==inf) max=after[tree[x][i]];
           else if(max<after[tree[x][i]]) max=after[tree[x][i]]; 
     }
     if(max==inf) max=n-1;
     else max=n-after[x]>max?n-after[x]:max;
     if(ans==max)
     {
          st[top++]=x;
     }else if(ans>max)
     {
           ans=max;
           top=0;
           st[top++]=x;
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) tree[i].clear();
    for(int i=0;i<n-1;i++)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         tree[a-1].push_back(b-1);
         tree[b-1].push_back(a-1);
    }
    ans=inf;
    dfs(0,0);
    sort(st,st+top);
    for(int i=0;i<top;i++) printf("%d%c",st[i]+1,i==top-1?'\n':' ');
    //scanf("%'d");
}
