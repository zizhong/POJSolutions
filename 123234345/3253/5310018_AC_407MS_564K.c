#include<stdio.h>
long long a[20001];
long long cmp(const void *a,const void *b)
{
    return *(long long *)b-*(long long *)a;
}
int main()
{
    int n,i,j,k=0;
    long long sum=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),cmp);
    while(n>=2)
    {   if(k)
        {
        for(i=0;i<n&&t<a[i];i++) ;
        for(j=n-2;j>=i;j--) a[j+1]=a[j];
        a[i]=t;
        }
        t=a[n-1]+a[n-2];
        sum+=t;
        n--;
        k=1;
    }
    printf("%lld\n",sum);
}
