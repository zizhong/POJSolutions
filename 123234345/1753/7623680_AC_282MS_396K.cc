#include<stdio.h>
#include<string.h>
const int N=4;
int cc[N][N];
int main()
{
    for(int i=0;i<N;i++)
    {
         char bb[5];
         scanf("%s",bb);
         for(int j=0;bb[j];j++)
              cc[i][j]=(bb[j]=='w');
    }
    int ans=17;
    for(int k=0;k<(1<<16);k++)
    {
         int f[N][N]={0},nf=0;
         for(int i=0;i<16;i++)
            if(k&(1<<i))
            {
                nf++;
                f[i/4][i%4]++;
                if(i>3) f[i/4-1][i%4]++;
                if(i<12) f[i/4+1][i%4]++;
                if(i%4) f[i/4][i%4-1]++;
                if(i%4<3) f[i/4][i%4+1]++;
            }
         int sum=0;
         for(int i=0;i<16;i++)
         {
              sum+=(cc[i/4][i%4]^(f[i/4][i%4]&1));
         }
         if(sum==16||sum==0)
         {
              if(nf<ans) ans=nf;
         }
    }
    if(ans<17)
    {
          printf("%d\n",ans);
    }
    else puts("Impossible");
}
