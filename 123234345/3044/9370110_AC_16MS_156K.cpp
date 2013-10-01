#include<cstdio>
#include<cstring>
const int N=50010;
int st[N],top;
int main()
{
    int n,x,y;
    scanf("%d%d",&n,&x);
    top=0;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i<n) scanf("%d%d",&x,&y);
        else y=0;
        while(top && st[top-1]>y) top--,ans++;
        if(top==0 || st[top-1]<y) st[top++]=y;
    }
    printf("%d\n",ans);
}
