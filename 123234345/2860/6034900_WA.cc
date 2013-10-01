#include<stdio.h>
const int N=31;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k;
    int st[N],ed;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
       scanf("%d",&st[i]);
    for(int i=0;i<n;i++)
       scanf("%d",&ed),st[i]-=ed;
    int ans=0;
    for(int i=0;i<n;i++) if(st[i]>0) ans+=st[i];
    printf("%d\n",ans);
}
