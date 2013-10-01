#include<stdio.h>
#include<string.h>
const int N=27,D=8;
int cc[N][N],p,q,d[D][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int ok(int x,int y)
{
    return x>=1&&x<=p&&y>=1&&y<=q&&!cc[x][y];
}
int st[N][2],top;
int dfs(int x,int y,int n)
{     
     cc[x][y]=1;
     if(n>=p*q) return 1;
     for(int k=0;k<D;k++)
     {
           if(ok(x+d[k][0],y+d[k][1]))
           {
                 if(dfs(x+d[k][0],y+d[k][1],n+1))
                 {
                       st[top][0]=x+d[k][0],st[top][1]=y+d[k][1],top++;
                       return 1;
                 }
                 else cc[x+d[k][0]][y+d[k][1]]=0;
           }
     }
     return 0;
}
int main()
{
    int T,h=0;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d%d",&p,&q);
         memset(cc,0,sizeof(cc));
         printf("Scenario #%d:\n",++h);
         
         top=0;
         if(!dfs(1,1,1)) printf("impossible");
         else
         {
             printf("A1");
             for(int i=top-1;i>=0;i--)
                 printf("%c%d",st[i][1]+'A'-1,st[i][0]);
             
         }
         puts("\n");
    }
}
