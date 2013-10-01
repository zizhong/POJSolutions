#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 900
int match[maxn];
int map[maxn][maxn];
char s[52][52];
int cx[52][52];
int cy[52][52];
bool v[maxn];
int n,m;
int nx,ny;
bool dfs(int p)
{
    int i;
    for(i=1;i<=ny;i++)
    {
        if(map[p][i]&&!v[i])
        {
            v[i]=1;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=p;
                return 1;
            }
        }
    }
    return 0;
}
int Hungry()
{
    int i;
    int ans=0;
    for(i=1;i<=nx;i++)
    {
        memset(v,0,sizeof(v));
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            s[i][j]=getchar();
        }
        getchar();
    }
    nx=0;
    ny=0;
    for(i=1;i<=n;i++)
    {
        j=1;
        while(j<=m)
        {
            if(s[i][j]=='*')
            {
                nx++;
                while(s[i][j]=='*')
                {
                    cx[i][j]=nx;
                    j++;
                }
            }
            else j++;
        }
    }
    for(j=1;j<=m;j++)
    {
        i=1;
        while(i<=n)
        {
            if(s[i][j]=='*')
            {
                ny++;
                while(s[i][j]=='*')
                {
                    cy[i][j]=ny;
                    i++;
                }
            }
            else i++;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i][j]=='*')
            {
                map[cx[i][j]][cy[i][j]]=1;
            }
        }
    }
    memset(match,-1,sizeof(match));
    printf("%d\n",Hungry());}
