#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[1001]={0};
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
           a[i]*=n-i;
        int max=0;
        for(int i=0;i<n;i++)
           if(max<a[i]) max=a[i];
        printf("%d\n",max);
    }
}
