#include<stdio.h>
const int N=101;
int d[N][N];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int a=-1,b=-1,std=0;
        for(int i=1;i<=n;i++)
        {
             for(int j=1;j<=n;j++)
                 scanf("%d",&d[i][j]);
        }
        int num1=0,num2=0;
        for(int i=1;i<=n;i++)
        {
              int flag=0;
              for(int j=1;j<=n;j++)
                 flag+=d[i][j];
              if(flag&1)
              {
                  a=i;
                  num1++; 
              }
        }
        for(int i=1;i<=n;i++)
        {
             int flag=0;
             for(int j=1;j<=n;j++)
                 flag+=d[j][i];
             if(flag&1)
             {
                 b=i;
                 num2++;
             }
        }
        if(num1==0&&num2==0) puts("OK");
        else if(num1==1&&num2==1) printf("Change bit (%d,%d)\n",a,b);
        else puts("Corrupt");
    }
}
