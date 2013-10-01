#include<stdio.h>
#include<string.h>
const int N=3003;
char s[N][N],elm,g[7][7];
int n,m,d[26][2],z;
void dfs(int x,int y,int z,int r)
{
     if(z==1)
     {
             for(int k=0;k<m;k++)
                     s[x+d[k][0]][y+d[k][1]]=elm;
             return ;
     }
     for(int k=0;k<m;k++)
     {
           dfs(x+d[k][0]*r/n,y+d[k][1]*r/n,z-1,r/n);
     }
}
int main()
{
    while(scanf("%d",&n),n)
    {
         m=0;
         gets(g[0]);
         for(int i=0;i<n;i++)
              gets(g[i]);
         for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
             {
                  if(g[i][j]==' ') continue;
                  elm=g[i][j];
                  d[m][0]=i,d[m][1]=j;
                  m++;
             }
         scanf("%d",&z);
         memset(s,' ',sizeof(s));
         int r=1;
         for(int i=0;i<z;i++)  r*=n;
         dfs(0,0,z,r);
         for(int i=0,j=r;i<r;i++,j=r) while(j>=0&&s[i][j]==' ') s[i][j]=0,--j;
         for(int i=0;i<r;i++) puts(s[i]);
    }
}
