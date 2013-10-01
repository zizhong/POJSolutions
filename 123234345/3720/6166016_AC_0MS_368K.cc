#include<stdio.h>
int num[101][10];
int main()
{
    for(int n=2;n<101;n++)
    {
         int vst[101]={0};
         int rem=1;
         while(rem&&!vst[rem])
         {
              vst[rem]=1;
              rem*=10;
              num[n][rem/n]++;
              rem%=n;
         }
    }  
    for(int k=0;k<10;k++)
       for(int i=3;i<101;i++)
       {         
          num[i][k]+=num[i-1][k];
       }
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)  printf("%d\n",num[n][k]);
}
