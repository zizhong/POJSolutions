#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=101;
int g[N][N];
struct Node{int i,v;}d[N];
int cmp(const void *a,const void *b)
{
    return ((Node *)b)->v - ((Node *)a)->v;
}
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
        int ans=0;
        for(int j=0;j<N;j++)
        {    /*if(j<9)
             for(int t=0;t<4;t++,puts(""))
                for(int i=0;i<9;i++) printf("%d ",g[t][i]);*/
             int sum=0;
             for(int i=0;i<N;i++)
                sum+=g[i][j];
             int m=sum-k;
             //if(j<9) printf("%d %d %d\n",j,ans,sum);
             if(m<=0) continue;
             ans+=m;
             int dn=0;
             for(int i=0;i<N;i++)
                if(g[i][j])
                {
                    d[dn].i=i;
                    d[dn].v=0;
                    int k=j+1;
                    while(k<N&&g[i][k]) k++,d[dn].v++;
                    dn++;
                }
            qsort(d,dn,sizeof(d[0]),cmp);
            for(int i=0;i<m;i++)
            {
                int k=j+1;
                while(k<N&&g[d[i].i][k]) g[d[i].i][k]=0,k++;
            }
        }
        printf("%d\n",ans);
    }
}
