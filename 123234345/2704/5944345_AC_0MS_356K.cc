#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n),n!=-1)
    {
         char b[35][35];         
         getchar();
         for(int i=0;i<n;i++) gets(b[i]);
         __int64 f[35][35];
         memset(f,0,sizeof(f));
         f[0][0]=1;
         for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                    if(b[i][j]=='0') continue;
                    int step=b[i][j]-'0';
                    if(step+i<n) f[step+i][j]+=f[i][j];
                    if(step+j<n) f[i][step+j]+=f[i][j];
            }
         printf("%I64d\n",f[n-1][n-1]);
    }
}
