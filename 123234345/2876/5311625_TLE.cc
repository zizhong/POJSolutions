#include<stdio.h>
#include<string.h>
int o3[13]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441};
void dfs(char *a,int m,int n)
{
    if(n<0) return ;
    int i;
    for(i=0;i<o3[n];i++)
       a[i+m]=' ';
    dfs(a,m-2*o3[n-1],n-1);
    dfs(a,m+o3[n-1]+o3[n],n-1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        char a[o3[n]+1];
        int i;
        memset(a,'-',sizeof(a));
        dfs(a,o3[n-1],n-1);
        for(i=0;i<o3[n];i++)
           printf("%c",a[i]);
        printf("\n");
    }
}
