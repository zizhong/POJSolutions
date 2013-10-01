#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    int ans=0;
    while(T--)
    {              
          int a[8][8]={0},b[8][8]={0};
          for(int i=1;i<=5;i++)
             for(int j=1;j<=6;j++)
                scanf("%d",&a[i][j]);
          for(int k=0;k<64;k++)
          {
              for(int i=1;i<=6;i++)
                  b[1][i]=(k>>(i-1)&1);
              for(int i=2;i<=5;i++)
                  for(int j=1;j<=6;j++)
                     b[i][j]=(a[i-1][j]+b[i-1][j]+b[i-1][j-1]+
                              b[i-1][j+1]+b[i-2][j])>>1;
              bool find=false;
              for(int i=1;i<=6;i++)
                 if((b[4][i]+b[5][i+1]+b[5][i-1]+b[5][i])%2!=a[5][i]) find=true;
              if(find) continue;
              printf("PUZZLE #%d\n",++ans);
              for(int i=1;i<=5;i++)
                 for(int j=1;j<=6;j++)
                    printf("%d%c",b[i][j],j==6?'\n':' ');
              break;
          }
    }
}
