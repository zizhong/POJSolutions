#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d",&N)&&N)
    {
         int i;         
         int wood=0;
         int f[5000]={0};
         int flag0=0,flag1=0;
         for(i=0;i<N;i++)
         {
             scanf("%d",&f[i]);
             if(flag0==0&&f[i])  flag0=1;
             if(flag1==0&&!f[i]) flag1=1;
         }
         if(flag0==0)
         {
             wood=N/2;
             if(N&1) wood++;
             printf("%d\n",wood);
             continue;
         }
         if(flag1==0)
         {
              printf("0\n");
              continue;
         }
         int st=1;
         while(!(f[st-1]==0&&f[st]==1)) st++;
         i=st+1;
         if(i==N) i=0;
         while(1)
         {
              while(f[i])
              {
                 ++i;
                 if(i==N) i=0;
              }
              int miss=0;
              while(!f[i])
              {
                  ++i;
                  if(i==N) i=0;
                  miss++;
              }
              wood+=miss/2;
              if(i==st) break;
         }
         printf("%d\n",wood);
    }
}
