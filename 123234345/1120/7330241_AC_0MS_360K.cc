#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int d[16];
    for(int i=0;i<16;i++)
        scanf("%d",&d[i]);
    int g[2][22][22];
    memset(g,0,sizeof(g));
    for(int i=1;i<=20;i++)
      for(int j=1;j<=20;j++)
          scanf("%d",&g[0][i][j]);
    for(int k=1;k<=n;k++)
    {
         int flag=0;
         for(int i=1;i<=20;i++)
            for(int j=1;j<=20;j++)
            {
                int sum= g[k&1^1][i][j]+g[k&1^1][i-1][j]+
                         g[k&1^1][i][j-1]+g[k&1^1][i+1][j]+
                         g[k&1^1][i][j+1];
                g[k&1][i][j]=g[k&1^1][i][j]+d[sum];
                if(g[k&1][i][j]>3) g[k&1][i][j]=3;
                if(g[k&1][i][j]<0) g[k&1][i][j]=0;
                if(g[k&1][i][j]!=g[k&1^1][i][j]) flag=1;
            }
         if(flag==0) break;         
    }
    char des[]={".!X#"};
    for(int i=1;i<=20;i++,puts(""))
          for(int j=1;j<=20;j++)
               putchar(des[g[n&1][i][j]]);
    system("pause");
}
