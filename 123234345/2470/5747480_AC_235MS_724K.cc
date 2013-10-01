#include<stdio.h>
const int N=100001;
int a[N];
int main()
{
    int n,i;
    while(scanf("%d",&n),n)
    {
         for(i=1;i<=n;i++)
             scanf("%d",&a[i]);
         for(i=1;i<=n;i++)
            if(a[a[i]]!=i) break;
         if(i>n) puts("ambiguous");
         else puts("not ambiguous");
    }
}
