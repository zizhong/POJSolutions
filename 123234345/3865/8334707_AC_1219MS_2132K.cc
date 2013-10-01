#include<stdio.h>
#include<string.h>
const int N=10010,M=81,mod=15437;
char data[N][M];
struct Idx{int st,ed;}str[N][11];
int n,m;
int v[mod],cnt,h[mod];
int diff(int r1,int r2,int c1,int c2)
{
    if(str[r1][c1].ed - str[r1][c1].st != str[r2][c1].ed - str[r2][c1].st) return 1;
    if(str[r1][c2].ed - str[r1][c2].st != str[r2][c2].ed - str[r2][c2].st) return 1;
    if( strncmp(data[r1]+str[r1][c1].st,data[r2]+str[r2][c1].st,str[r1][c1].ed - str[r1][c1].st + 1)||
        strncmp(data[r1]+str[r1][c2].st,data[r2]+str[r2][c2].st,str[r1][c2].ed - str[r1][c2].st + 1))
        return 1;
    return 0;
}
int findstr(int r2,int c1,int c2)
{
    int key=1;
    for(int i=str[r2][c1].st;i<=str[r2][c1].ed;i++) key=(key*data[r2][i])%mod;
    key=(key+11123)%mod;
    for(int i=str[r2][c2].st;i<=str[r2][c2].ed;i++) key=(key*data[r2][i])%mod;
    int flag=0;
    while(1)
    {
         if(v[key]!=cnt) break;
         if(!diff(h[key],r2,c1,c2)) {flag=1;break;}
         key=(key+1)%mod;
    }
    if(flag)
    {
         puts("NO");
         printf("%d %d\n%d %d\n",h[key],r2,c1,c2);
         return 1;
    }
    v[key]=cnt;
    h[key]=r2;
    return 0;
}
int main()
{
    
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++)
    {
         gets(data[i]);
         int j=0;
         for(int k=1;k<m;k++)
         {
              while(data[i][j]!=',') ++j;
              str[i][k].ed=j-1;
              str[i][k+1].st=j+1;
              ++j;
         }
         str[i][1].st=0,str[i][m].ed=strlen(data[i])-1;
    }
    int flag=0;
    for(int i=1;i<=m&&!flag;i++)
        for(int j=i+1;j<=m&&!flag;j++)
        {
             ++cnt;
             for(int k=1;k<=n&&!flag;k++)
             {
                  if(findstr(k,i,j))
                      flag=1;
             }
        }
    //printf("%d\n",diff(1,2,2,3));
    if(!flag) puts("YES");
}
