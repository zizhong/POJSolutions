#include<stdio.h>
#include<stdlib.h>
struct Node
{
       int id,v;
}d[1001],f[10001];
int n,k;
int ok(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=x/d[i].v;
    return sum>=k;
}
int cmp(const void *a,const void *b)
{
    return ((Node *)a)->v - ((Node *)b)->v ?
           ((Node *)a)->v - ((Node *)b)->v:
           ((Node *)a)->id - ((Node *)b)->id;
}
void solve(int x)
{
     int i=0,j,h;
     for(j=1;j<=n;j++)
     {
             int t=x/d[j].v;
             for(h=1;h<=t;h++)
             {
                 f[i].id=d[j].id;
                 f[i].v=h*d[j].v;
                 i++;
             }             
     }
     qsort(f,i,sizeof(f[0]),cmp);
     for(j=0;j<i;j++) printf("%d\n",f[j].id);
}
int main()
{
    char s[16];
    while(scanf("%s",s),s[0]!='#')
    {
          n++;
          scanf("%d%d",&d[n].id,&d[n].v);
    }
    scanf("%d",&k);
    int l=0,r=3000*k;
    while(l+1<r)
    {
         int mid=l+r>>1; 
         if(ok(mid)) r=mid;
         else l=mid;
    }
    solve(r);
}
