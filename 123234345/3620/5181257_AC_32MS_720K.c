#include<stdio.h>
char a[101][101];
int dfs(int i,int j)
{
     int imax=1;
     if(a[i][j]=='*') return 0;
     a[i][j]='*';
     imax+=dfs(i-1,j)+dfs(i,j-1)+dfs(i+1,j)+dfs(i,j+1);
     return imax;
     
}
int main()
{
    int n,m,k,i,j,r,c,max=0;
    scanf("%d%d%d",&n,&m,&k);
    memset(a,'*',sizeof(a));
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&r,&c);
        a[r][c]='#';
    }
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       if(a[i][j]=='#')
       { 
       int imax=dfs(i,j);
       if(imax>max) max=imax;
       }
    printf("%d\n",max);
}
