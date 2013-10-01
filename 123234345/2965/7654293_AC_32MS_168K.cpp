#include<stdio.h>
const int N=4;
int f[N][N];
int main()
{
    char s[5][5];
    for(int i=0;i<N;i++)
       gets(s[i]);
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
       {
            if(s[i][j]=='+')
            {
                for(int k=0;k<N;k++)
                   f[i][k]^=1,f[k][j]^=1;
                f[i][j]^=1;
            }           
       }
    int ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
           ans+=f[i][j];
    printf("%d\n",ans);
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++) if(f[i][j])
          printf("%d %d\n",i+1,j+1);
       
} 
