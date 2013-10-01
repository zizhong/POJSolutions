#include<stdio.h>
#include<stdlib.h>
const int N=80001;
int d[N],q[N],head,tail;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    __int64 sum=0;
    q[tail++]=d[1];
    for(int i=2;i<=n;i++)
    {
        while(head<tail&&q[tail-1]<=d[i]) tail--;
        sum+=tail-head;
        q[tail++]=d[i];
    }
    printf("%I64d\n",sum);
}
