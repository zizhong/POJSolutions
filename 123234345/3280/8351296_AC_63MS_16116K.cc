#include<stdio.h>
const int N=2010,inf=0xfffffff;
char str[N];
int n,m,cost[27],f[N][N];
int min(int a,int b){return a<b?a:b;}
int main()
{
    scanf("%d%d%s",&m,&n,str+1);
    for(int i=0;i<26;i++) cost[i]=inf;
    for(int i=0;i<m;i++)
    {
        char ch[2];
        int d1,d2;
        scanf("%s%d%d",ch,&d1,&d2);
        if(d2<d1) d1=d2;
        cost[ch[0]-'a']=d1;
    }
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            f[i][j]=inf;
    f[0][n+1]=0;
    for(int i=1;i<=n;i++) f[i][n+1]=f[i-1][n+1]+cost[str[i]-'a'];
    for(int j=n;j>=1;j--) f[0][j]=f[0][j+1]+cost[str[j]-'a'];
    for(int i=1;i<=n;i++)
       for(int j=n;j>i;j--)
       {
            if(str[i]==str[j])
                f[i][j]=min(f[i][j],f[i-1][j+1]);
            f[i][j]=min(f[i][j],f[i-1][j]+cost[str[i]-'a']);
            f[i][j]=min(f[i][j],f[i][j+1]+cost[str[j]-'a']);
       }
    /*for(int i=0;i<=n+1;i++,puts(""))
       for(int j=0;j<=n+1;j++)
            printf("%13d ",f[i][j]);*/
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,f[i-1][i+1]);
        ans=min(ans,f[i][i+1]);
    }
    printf("%d\n",ans);
}
