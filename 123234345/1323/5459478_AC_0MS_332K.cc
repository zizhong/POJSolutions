#include<stdio.h>

int a[51];
int i,j,m,n,max,now,cas=0;

bool have(int x)
{
    for(j=1;j<=n;j++)
        if(x==a[j])return true;
    return false;

}

int main()
{

    while(1)
    {
        cas++;
    scanf("%d%d",&m,&n);
    if(m==0&&n==0)return 0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=0;now=0;
    for(i=n*m;i>=1;i--)
    {
        
        if(have(i)){now++;if(now>max)max=now;}
        else now--;

    }
    printf("Case %d: %d\n",cas,max);
    }
}
