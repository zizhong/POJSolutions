#include<stdio.h>
const __int64 max=1<<30;
__int64 f[16][800000];
int cnt[16];
int main()
{
    cnt[1]=1;
    f[1][1]=0;
    for(int i=2;i<=14;i++)
    {
         for(int t1=1;t1<i;t1++)
         {
             int t2=i-t1;
             for(int j=1;j<=cnt[t1];j++)
                 for(int k=1;k<=cnt[t2];k++)
                 {
                      if((t1+t2-1)*2>=30) break;
                     f[i][++cnt[i]]= (1<<((t1+t2-1)*2)) + (1<<t2)*f[t1][j] + f[t2][k];
                 }
         }
    }
    /*for(int i=1;i<=15;i++)
       printf("%d\n",cnt[i]);*/
    int n;
    scanf("%d",&n);
    int k=30;
    while(k--)
       if((1<<k)&n) break;
    int m=(k+2)/2,mi=0;
    for(int i=1;i<=cnt[m];i++)
         if(n==f[m][i]) {mi=i;break;}
    printf("%I64d\n",f[m][mi%cnt[m]+1]);
    //scanf("%'d");
}
