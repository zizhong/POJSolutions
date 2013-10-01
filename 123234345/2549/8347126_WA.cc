#include<stdio.h>
#include<stdlib.h>
const int N=1010;
struct Node
{
    int val,id;
}d[N/2*N];
int num[N];
int cmp(const void *a,const void *b)
{
    return ((Node *)a)->val - ((Node *)b)->val;
}
int main()
{
    //freopen("")
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%d",&num[i]);
         int cnt=0;
         for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
             {
                 d[cnt].val=num[i]+num[j];
                 d[cnt].id=i*n+j;
                 cnt++;
             }
         qsort(d,cnt,sizeof(d[0]),cmp);
         int flag=0;
         for(int i=n-1;i>=0;i--)
         {
              for(int j=i-1;j>=0&&!flag;j--)
              {
                   int l=0,r=cnt-1,key=num[i]-num[j];
                   while(l<=r)
                   {
                       int mid=(l+r)/2;
                       if(d[mid].val<key) l=mid+1;
                       else if(d[mid].val>=key) r=mid-1;
                   }
                   int x=l-1,y=l+1;
                   while(x>0&&d[x].val==key) --x;
                   while(y<n-1&&d[y].val==key) ++y;
                   for(int k=x;k<=y;k++)
                        if(d[k].id%n<j) {flag=1;break;}
              }
              if(flag)
              {
                   printf("%d\n",num[i]);
                   break;
              }
         }
         if(!flag) puts("no solution");
    }
}
