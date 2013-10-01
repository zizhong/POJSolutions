#include<stdio.h>
#include<stdlib.h>
#define NMAX 5000000
int a[NMAX];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n1,n2,n;
    while(scanf("%d%d%d",&n1,&n2,&n)&&n)
    {
        int i;
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),cmp);
        double r=0;
        for(i=n1;i<n-n2;i++)
           r+=a[i];
        r/=(n-n1-n2);
        printf("%.6lf\n",r);
    }
}
