#include<stdio.h>
const int N=16;
int f[4][4];
int main()
{
    char s[5];
    for(int i=0;i<4;i++)
    {
        scanf("%s",s);
        for(int j=0;j<4;j++)
            if(s[j]=='+') f[i][j]=1;
            else f[i][j]=0;
    }
    int ans=N+1,tk=-1;
    for(int k=1;k<(1<<N);k++)
    {
        int cnt=0;
        for(int i=0;i<N;i++)
          if(k&(1<<i)) cnt++;
        if(cnt>=ans) continue;
        int t[4][4];
        for(int i=0;i<4;i++)
           for(int j=0;j<4;j++)
               t[i][j]=f[i][j];
        for(int i=0;i<N;i++) if(k&(1<<i))
        {
           int x=i/4,y=i%4;
           for(int i=0;i<4;i++) t[i][y]^=1,t[x][i]^=1;
           t[x][y]^=1;
        }
        int flag=0;
        for(int i=0;i<4;i++)
           for(int j=0;j<4;j++)
              flag+=t[i][j];
        if(flag==0) ans=cnt,tk=k;   
    }
    printf("%d\n",ans);
    for(int i=0;i<N;i++) if(tk&(1<<i))
       printf("%d %d\n",i/4+1,i%4+1);
} 
