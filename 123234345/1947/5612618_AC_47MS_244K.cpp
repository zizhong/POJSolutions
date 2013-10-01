#include<vector>
#include<stdio.h>
using namespace std;
int n,p;
vector<int >Tree[151];
int f[151][151];
const int inf=999999999;
void DFS(int root)
{
     int i,j,k;
     for(i=0;i<Tree[root].size();i++)
        DFS(Tree[root][i]);
     f[root][1]=Tree[root].size();
     for(i=0;i<Tree[root].size();i++)
          for(k=p-1;k>=1;k--)
              if(f[root][k]<inf)
              for(j=1;j<=p-1;j++)
                 if(f[Tree[root][i]][j]<inf)
                 f[root][k+j]= min(f[root][k+j],f[Tree[root][i]][j]+f[root][k]-1);
}
int DP()
{
    int i,j,ans=inf;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f[i][j]=inf;
    DFS(1);
    for(i=2;i<=n;i++)
          ans=min(f[i][p]+1,ans);
    ans=min(f[1][p],ans);
    return ans;
}
int main()
{
    int a,b,i;
    scanf("%d%d",&n,&p);
    for(i=1;i<n;i++)
    {
         scanf("%d%d",&a,&b);
         Tree[a].push_back(b);
    }
    printf("%d\n",DP());
    //system("pause");
}
