#include<stdio.h>
#include<string.h>
const int N=101;
int g[N][N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x2<x1) {int t=x1;x1=x2;x2=t;}
            for(int x=x1;x<=x2;x++)
                g[y1][x]=1;
        }
        int v[N]={0};
        for(int i=0;i<N;i++)
        {
             for(int j=0;j<N;j++)
                 v[i]+=g[j][i];
        }
        int sum=0;
        for(int i=0;i<N;i++)
           if(v[i]-k>sum) sum=v[i]-k;
        printf("%d\n",sum);
    }
}
