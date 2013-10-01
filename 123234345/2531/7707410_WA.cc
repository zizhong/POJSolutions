#include<stdio.h>
const int N=21;
int g[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
           scanf("%d",&g[i][j]);
    int ans=0;
    for(int k=1;k<(1<<(n-1))-1;k++)
    {
         int r=0;
         for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((k&(1<<i))!=(k&(1<<j)))
                      r+=g[i][j];
         if(r>ans) ans=r;
    }
    printf("%d\n",ans);
}
