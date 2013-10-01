#include<cstdio>
#include<cstring>
int main()
{
    int T=0,n;
    while(scanf("%d",&n),n)
    {
        printf("%d. %s %d\n",++T,(n&1)?"odd":"even",n/2);
    }
}
