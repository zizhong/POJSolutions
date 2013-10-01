#include<stdio.h>
short mark[26],f[21][21];
char a[22][22];
int dfs(int i,int j);
main()
{
    int r,t,i,j,max;
    char c;
    scanf("%d%d",&r,&t);
    memset(a,'*',22*22*sizeof(char));
    for(i=1;i<=r;i++)
       for(j=1;j<=t;j++)
       {
          c=getchar();
          while(!(c>='A'&&c<='Z'))
              c=getchar();
          a[i][j]=c;
       }
    for(i=1;i<=r;i++)
       for(j=1;j<=t;j++)
       {
          f[i][j]=dfs(i,j);
       }
    max=0;
    for(i=1;i<=r;i++)
       for(j=1;j<=t;j++)
         max=f[i][j]>max?f[i][j]:max;
    printf("%d\n",max);
}
int dfs(int i,int j)
{
    int p=0;
    if(a[i-1][j]!='*'&&!mark[a[i-1][j]-'A'])
    {
        mark[a[i-1][j]-'A']=1;
        p=1;
        p=p+dfs(i-1,j);
    } 
    if(a[i+1][j]!='*'&&!mark[a[i+1][j]-'A'])
    {
        mark[a[i+1][j]-'A']=1;
        p=1;
        p=p+dfs(i+1,j);
    } 
    if(a[i][j-1]!='*'&&!mark[a[i][j-1]-'A'])
    {
        mark[a[i][j-1]-'A']=1;
        p=1;
        p=p+dfs(i,j-1);
    } 
    if(a[i][j+1]!='*'&&!mark[a[i][j+1]-'A'])
    {
        mark[a[i][j+1]-'A']=1;
        p=1;
        p=p+dfs(i,j+1);
    } 
    return p;
}
