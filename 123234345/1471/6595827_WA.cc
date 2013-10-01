#include<stdio.h>
#include<string.h>
const int N=100;
int n,T;
char map[N][2*N];
int _max(int a,int b){return a>b?a:b;}
int dfs(int x,int y,int d)
{
    if(x+d<0||x+d>=n) return 0;
    int ed=d<0?y-d:y+d;
    for(int i=2*y-ed;i<=ed;i++) if(map[x+d][i]!='-')
            return 0;
    return 1;
}
int main()
{
      while(scanf("%d",&n),n)
      {
           memset(map,'#',sizeof(map));
           gets(map[0]);
           for(int i=0;i<n;i++)
           {
               gets(map[i]);
           }
           int ans=0;
           for(int i=0;i<n;i++)
           {
                 for(int j=i;j<2*n-1-i;j++) if(map[i][j]=='-')
                 {
                         int a1=1,a2=1;
                         while(dfs(i,j,a1)) a1++;
                         while(dfs(i,j,-a2)) a2++;
                         ans=_max(ans,_max(a1,a2));
                 }
           }
           printf("Triangle #%d\nThe largest triangle area is %d.\n\n",++T,ans*ans);
      }  
}
