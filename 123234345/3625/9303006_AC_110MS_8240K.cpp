#include<cstdio>
#include<cstring>
#include<cmath>
const int N=1024;
double g[N][N];
struct Point
{
    double x,y;
    void init(){scanf("%lf%lf",&x,&y);}
}p[N];
double dis(Point &p1,Point &p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int n,m;
double prim()
{
    double d[N];
    int v[N]={0};
    for(int i=0;i<n;i++) d[i]=g[0][i];
    v[0]=0;
    while(true)
    {
        double min=1e9;
        int mi=-1;
        for(int i=0;i<n;i++) if(!v[i]&& min>d[i])
             min=d[i],mi=i;
        if(min>=1e9) break;
        v[mi]=1;
        for(int i=0;i<n;i++) if(!v[i] && g[mi][i]<d[i])
             d[i]=g[mi][i];
    }
    double ret=0;
    for(int i=0;i<n;i++) ret+=d[i];
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) p[i].init();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
             g[j][i]=g[i][j]=dis(p[i],p[j]);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        --x,--y;
        g[x][y]=g[y][x]=0;
    }
    printf("%.2f\n",prim());
}
