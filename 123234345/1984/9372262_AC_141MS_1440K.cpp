#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=40010;
int pre[N];
struct Point{int x,y;}p[N];
void disp(Point &p1){printf("<%d,%d>\n",p1.x,p1.y);}
struct Data
{
     int a,b,d;
     char dir[2];
     void init()
     {
         scanf("%d%d%d",&a,&b,&d);
         scanf("%s",dir);
     }
}data[N];
int n,m,q;
struct Query
{
     int a,b,i,idx;
     void init(int ii){scanf("%d%d%d",&a,&b,&i);idx=ii;}
}query[10010];
bool cmp(const Query& q1,const Query& q2)
{
     return q1.i < q2.i;
}
int ans[10010];
void init_set()
{
     memset(pre,-1,sizeof(pre));
     memset(p,0,sizeof(p));
}
int findr(int x)
{
    int r=x;
    int xsum=0,ysum=0;
    while(pre[r]>=0)
    {
          xsum+=p[r].x;
          ysum+=p[r].y;
          r=pre[r];          
    }
    while(x!=r)
    {
         int x1=p[x].x,y1=p[x].y;
         p[x].x=xsum,p[x].y=ysum;
         int t=pre[x];
         pre[x]=r;
         x=t;
         xsum-=x1,ysum-=y1;
    }
    return r;
}
void insert(Data & d1)
{
     int r1 = findr(d1.a);
     int r2 = findr(d1.b);
     if(r1 == r2) return;
     int num1=-pre[r1],num2=-pre[r2];
     int x=0,y=0;
     switch(d1.dir[0])
     {
          case 'E':x=d1.d;break;
          case 'W':x=-d1.d;break;
          case 'N':y=d1.d;break;
          case 'S':y=-d1.d;break;
     }
     x+=p[d1.a].x-p[d1.b].x,y+=p[d1.a].y-p[d1.b].y;
     if(num1>num2)
     {
         pre[r1]=-num1-num2;
         pre[r2]=r1;
         p[r2].x=x,p[r2].y=y;
     }
     else
     {
          pre[r1]=r2;
          pre[r2]=-num1-num2;
          p[r1].x=-x,p[r1].y=-y;          
     }
}
int solve(Query &q1)
{
    int r1=findr(q1.a),
        r2=findr(q1.b);
    if(r1!=r2) return -1;
    return abs(p[q1.a].x-p[q1.b].x) +
           abs(p[q1.a].y-p[q1.b].y);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
         data[i].init();
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
         query[i].init(i);
    sort(query+1,query+1+q,cmp);
    query[0].i=0;
    init_set();
    for(int i=1;i<=q;i++)
    {
          for(int j=query[i-1].i+1;j<=query[i].i;j++)
               insert(data[j]);
          ans[query[i].idx]=solve(query[i]);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}
