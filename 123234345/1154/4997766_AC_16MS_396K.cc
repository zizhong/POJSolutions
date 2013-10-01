#include<stdio.h>
#include<iostream>
char mark[26]={0};
char a[22][22];
int dfs(int i,int j);
main()
{
    int r,t,i,j;
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
    printf("%d\n",dfs(1,1)+1);
    getchar();getchar();
}
int max(int a,int b)
{
   if(a>b) return a;
   return b;
}
int dfs(int i,int j)
{   
    int p,p1=0,p2=0,p3=0,p4=0;
    mark[a[i][j]-'A']=1;
    if(a[i][j+1]!='*'&&!mark[a[i][j+1]-'A'])
        p1=dfs(i,j+1)+1;
    if(a[i+1][j]!='*'&&!mark[a[i+1][j]-'A'])
        p2=dfs(i+1,j)+1;
    if(a[i-1][j]!='*'&&!mark[a[i-1][j]-'A'])
        p3=dfs(i-1,j)+1;    
    if(a[i][j-1]!='*'&&!mark[a[i][j-1]-'A'])
        p4=dfs(i,j-1)+1;
     p=max(max(p1,p2),max(p3,p4));    
    mark[a[i][j]-'A']=0;
    return p;
}
