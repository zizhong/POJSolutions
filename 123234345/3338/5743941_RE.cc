#include<stdio.h>
#include<string.h>
int r,c;
char cake[50][50];
void dfs(int i,int j)
{
     if(cake[i][j]=='*') return ;
     cake[i][j]='*';
     if(cake[i][j-1]=='.'&&j-2>0) dfs(i,j-2);
     if(cake[i][j+1]=='.'&&j+2<=2*c) dfs(i,j+2);
     if(cake[i-1][j]=='.'&&i-2>0) dfs(i-2,j);
     if(cake[i+1][j]=='.'&&i+2<=2*r) dfs(i+2,j);
}
int main()
{
    while(scanf("%d%d",&r,&c))
    {
        memset(cake,'*',sizeof(cake));
        for(int i=1;i<=r*2-1;i++)
           for(int j=1;j<=2*c-1;j++)
               cake[i][j]='.';
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1*=2,x2*=2,y1*=2,y2*=2;
            for(int i=x1;i<=x2;i++) cake[y1][i]=cake[y2][i]='*';
            for(int i=y1;i<=y2;i++) cake[i][x1]=cake[i][x2]='*';
        }
        int ans=0;
        for(int i=1;i<=2*r;i+=2)
           for(int j=1;j<=2*c;j+=2)
           if(cake[i][j]=='.') ans++,dfs(i,j);           
        printf("%d\n",ans);
    }
}
