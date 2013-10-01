#include<stdio.h>
char s1[1000]={'1'},s2[1000]={'2'};
int f[1000][1000];
int main()
{
    int i,j,n,m;
    while(scanf("%s%s",s1+1,s2+1)!=EOF)
    {        
        n=strlen(s1);
        m=strlen(s2);
        for(i=0;i<n;i++) f[i][0]=0;         
        for(j=0;j<m;j++) f[0][j]=0;
        for(i=1;i<n;i++)
           for(j=1;j<m;j++)
           if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
           else f[i][j]=f[i][j-1]>f[i-1][j]?f[i][j-1]:f[i-1][j];
        printf("%d\n",f[n-1][m-1]);
    }
}
