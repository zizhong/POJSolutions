#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=10010;
struct Node
{
    int d,o;
    void init(){scanf("%d%d",&d,&o);}
}sd[N];
bool cmp(const Node &a,const Node &b)
{
     return a.d < b.d;
}
int n,l,p;
int solve()
{
    priority_queue<int> q1;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        while(!q1.empty() && sd[i].d>p)
        {
              p+=q1.top();
              ret++;
              q1.pop();
        }
        if(sd[i].d>p) return -1;
        q1.push(sd[i].o);
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) sd[i].init();
    scanf("%d%d",&l,&p);
    for(int i=0;i<n;i++) sd[i].d=l-sd[i].d;
    sd[n].d=l,sd[n++].o=0;
    sort(sd,sd+n,cmp);
    //for(int i=0;i<n;i++) printf("<%d,%d>\n",sd[i].d,sd[i].o);
    int ans=solve();
    printf("%d\n",ans);
    //scanf("%'d");
}
