#include<stdio.h>
#define N 1000000
int ans[N],nans,used[10];
void dfs(int n,int leftLen)
{
     if(nans>N)
         return ;
     if(leftLen==0)
     {
         ans[nans++]=n;
         return ;
     }
     for(int i=0;i<10;i++)
     {
         if(i!=0||n!=0)
         {
             if(!used[i])
             {
                 used[i]=1;
                 dfs(10*n+i,leftLen-1);
                 used[i]=0;
             }
         }
     }
}
int main()
{
    int i,n;
    for(i=1;i<9;i++)
      dfs(0,i);
    while(scanf("%d",&n)&&n)
        printf("%d\n",ans[n-1]);
}
