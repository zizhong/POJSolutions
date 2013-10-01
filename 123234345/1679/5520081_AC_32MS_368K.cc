#include<stdio.h>
#include<string.h>
#define N 101
#define NIL 9999999
int g[N][N];
int a[3][N];
int MST(int n)
{
    memset(a,0,sizeof(a));
    a[2][0]=1;
    int i,j,tail,min,cost=0;
    for(i=0;i<n;i++)
    {
        a[0][i]=g[0][i];
        a[1][i]=0;
    }
    while(1)
    {
        min=NIL;
        for(i=0;i<n;i++)
           if(a[2][i]==0&&a[0][i]<min)
           {
               min=a[0][i];
               tail=i;
           }
        if(min==NIL) break;
        a[2][tail]=i;
        for(i=0;i<n;i++)
           if(a[2][i]==0&&a[0][i]>g[tail][i])
             {
                 a[0][i]=g[tail][i];
                 a[1][i]=tail;
             }
    }
    for(i=0;i<n;i++)
       cost+=a[0][i];
    return cost;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,j,k,i;
        int e[N][2]={0};
        scanf("%d%d",&n,&m);
        //initialize
        for(i=0;i<n;i++)
           for(j=i+1;j<n;j++)
             g[i][j]=g[j][i]=NIL;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&j,&k);
            j--,k--;
            if(j!=k) scanf("%d",&g[j][k]);
            g[k][j]=g[j][k];
        }
        int minp=MST(n);
        for(i=1;i<n;i++)
          {
              e[i][0]=i;
              e[i][1]=a[1][i];
          }
        
        for(i=1;i<n;i++)
        {
            int s=g[e[i][0]][e[i][1]];
                g[e[i][0]][e[i][1]]=g[e[i][1]][e[i][0]]=NIL;
            int minp2=MST(n);
            if(minp2==minp) break;
            g[e[i][0]][e[i][1]]=g[e[i][1]][e[i][0]]=s;
        }
        if(i<n) printf("Not Unique!\n");
        else printf("%d\n",minp);
    }
}
