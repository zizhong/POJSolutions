#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int> > cows;
    for(int i=0;i<n;i++)
    {
         int x;
         scanf("%d",&x);
         cows.push_back(make_pair(x,i));
    }
    sort(cows.begin(),cows.end());
    int ans=0,m=cows[0].first;
    for(int i=0;i<n;i++)
    {
            if(cows[i].second==-1) continue;
            int j=cows[i].second,w=cows[i].first,k=1;
            cows[i].second=-1;
            while(j!=i)
            {
                  k++;
                  ans+=cows[j].first;
                  int t=cows[j].second;
                  cows[j].second=-1;
                  j=t;
            }
            ans+=min((k-1)*w,(k-1)*m+2*(m+w));
    }
    printf("%d\n",ans);
    }
