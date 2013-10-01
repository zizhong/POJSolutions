#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[250][250];
    int num=0;
    for(int i=1;num<n*m;i++)
    {
            for(int j=i;j<=m-i&&num<n*m;j++) a[i][j]=(num++)%26;
            for(int j=i;j<=n-i&&num<n*m;j++) a[j][m-i+1]=(num++)%26;
            for(int j=m-i+1;j>i&&num<n*m;j--) a[n-i+1][j]=(num++)%26;
            for(int j=n-i+1;j>i&&num<n*m;j--) a[j][i]=(num++)%26;
    }
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=m;j++)
              printf("   %c",a[i][j]+'A');
         puts("");
    }
}
