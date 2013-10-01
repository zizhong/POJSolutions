#include<stdio.h>
#include<stdlib.h>
const int N=250001;
int cmp(const void *a,const void *b)
{
    return *(__int64 *)a - *(__int64 *)b;
}
int dig(char c)
{
    return c>='0'&&c<='9';
}
__int64 NextInt()
{
        __int64 d=0;
        char c;
        while(!dig(c=getchar())) ;
        d=c-'0';
        while(dig(c=getchar())) d=d*10+c-'0';
        return d;
}
__int64 d[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) d[i]=NextInt();
    qsort(d,n,sizeof(d[0]),cmp);
    if(n&1)
    {
        printf("%I64d\n",d[n/2]);
    }else
    {
         __int64 sum=d[n/2]+d[n/2-1];
         if(sum&1) printf("%I64d.5\n",sum/2);
         else printf("%I64d\n",sum/2);
    }
    //scanf("%'d");
}
