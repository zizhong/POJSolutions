#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d",&m);
    while(m--)
    {
              scanf("%d",&n);
              struct Card
              {
                     int v,op;
              }q[1000];
              int head=1,tail=n;
              for(int i=1;i<=n;i++) q[i].op=i;
              int ans[14]={0};
              for(int i=1;i<=n;i++)
              {
                      int f=i;
                      while(f--) q[++tail]=q[head++];
                      ans[q[head++].op]=i;
              }
              for(int i=1;i<=n;i++)
                 printf("%d%c",ans[i],i==n?'\n':' ');
    }
}
