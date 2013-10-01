#include<stdio.h>
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,t,p;
        scanf("%d%d%d",&n,&t,&m);
        for(int i=0;i<m;i++)  scanf("%d",&p);
        printf("%d %d\n",p+t,m/n+(m%n!=0));
    }
}
