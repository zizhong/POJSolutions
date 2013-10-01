# include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
   int h,c,maxh;
}data[401];
bool cmp(const node &a,const node &b)
{
   return a.maxh<b.maxh;
}
bool dp[40001];
int q[40001][2];
int main()
 {
     int num,maxnum=-1;
    scanf("%d",&num);
     for(int i=0;i<num;i++)
    scanf("%d%d%d",&data[i].h,&data[i].maxh,&data[i].c);
    sort(data,data+num,cmp);
    maxnum=data[num-1].maxh;
     memset(dp,false,sizeof(dp));
    memset(q,-1,sizeof(q));
   dp[0]=true;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<=data[i].maxh;j++)
        {
           if(!dp[j]&&j-data[i].h>=0&&dp[j-data[i].h])
           {
              if(q[j-data[i].h][0]!=i)
              {
                   q[j][0]=i;
                  q[j][1]=1;
                     dp[j]=true;
                }
               else if(q[j-data[i].h][1]<data[i].c)
                {
                  q[j][0]=i;
                   q[j][1]=q[j-data[i].h][1]+1;
                   dp[j]=true;
                }
            }
        }
     }
    for(int i=maxnum;i>=0;i--)
    {
        if(dp[i])
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;

}
