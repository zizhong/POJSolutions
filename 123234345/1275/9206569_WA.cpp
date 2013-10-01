#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 30;
const int INF = 1000000000;

bool in[MAXN];
int cnt[MAXN],dist[MAXN];
int r[MAXN],t[MAXN];
vector<pair<int,int> > E[MAXN];

void reset(int x24)
{
    for(int i=0;i<=24;i++)
        E[i].clear();
    // 0<=x[i]-x[i-1]<=t[i]
    for(int i=1;i<=24;i++)
    {
        E[i-1].push_back(make_pair(i,0));
        E[i].push_back(make_pair(i-1,-t[i]));
    }
    //x[24]+x[i]-x[i-8+24]>=r[i]
    for(int i=1;i<=8;i++)
        E[i-8+24].push_back(make_pair(i,r[i]-x24));
    //x[i]-x[i-8]>=r[i]
    for(int i=9;i<=24;i++)
        E[i-8].push_back(make_pair(i,r[i]));
    //x[24]-x[0]>=x[24]
    E[0].push_back(make_pair(24,x24));
}

bool spfa(int x24)
{
    fill(dist,dist+25,INF);//±ßÈ¨¿ÉÒÔÎª¸º£¬ËùÒÔ¸³Îª-INF
    fill(in,in+25,false);
    fill(cnt,cnt+25,0);
    in[0]=1;
    dist[0]=0;
    cnt[0]=1;
    queue<int>Q;
    Q.push(0);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        in[u]=false;
        for(vector<pair<int,int> >::iterator it=E[u].begin();it!=E[u].end();it++)
        {
            if(dist[it->first]<dist[u]+it->second)
            {
                dist[it->first]=dist[u]+it->second;
                if(in[it->first]==false)
                {
                    if(++cnt[it->first]>25)return false;
                    in[it->first]=true;
                    Q.push(it->first);
                }            
            }
        }
    }
    return dist[24]==x24;
}
int main()
{
    //freopen("in","r",stdin);
    int T,n;
    for(scanf("%d",&T);T--;)
    {
        for(int i=1;i<=24;i++)
        {
            scanf("%d",&r[i]);
            t[i]=0;
        }
        scanf("%d",&n);            
        for(int i=1,x;i<=n;i++)
        {
            scanf("%d",&x);
            t[x+1]++;
        }
        int left=0,right=n+1;
        while(right-left>1)
        {
            int mid=(left+right)>>1;
            reset(mid);
            if(spfa(mid))right=mid;
            else left=mid;
        }
        if(right==n+1)puts("No Solution");
        else printf("%d\n",right);
    }
    return 0;
}
