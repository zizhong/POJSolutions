#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=50010;
int p[N];
int cmp(const int a,const int b)
{
    return abs(a) < abs(b);
}
int main()
{
    int t,n;
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;i++) 
        scanf("%d",&p[i]);
    sort(p,p+n,cmp);
    int ans=0,cur=0;
    for(int i=0;i<n;i++)
    {
         if(t>=abs(p[i]-cur))
         {
              ans++;
              t-=abs(p[i]-cur);
              cur=p[i];
              
         }else break;
    }
    printf("%d\n",ans);
}
