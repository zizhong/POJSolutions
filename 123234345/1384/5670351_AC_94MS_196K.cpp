#include<stdio.h>
const int inf=99999999;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int e,fl;
        scanf("%d%d",&e,&fl);
        int V=fl-e;
        int N;
        int w[500],v[500],p[10001];
        for(int i=1;i<=V;i++) p[i]=inf;
        p[0]=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d%d",&v[i],&w[i]);
        for(int i=0;i<N;i++)
        {
            for(int j=w[i];j<=V;j++)
               if(p[j-w[i]]+v[i]<p[j]) p[j]=p[j-w[i]]+v[i]; 
        }
        if(p[V]==inf) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",p[V]);
    }
}
