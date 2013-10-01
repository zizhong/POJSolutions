#include<stdio.h>
const int N=3001;
int a[N],next[N];
int main()
{

    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)k++;
    }
    int h1=0,h2=k+1;
    for(i=1;i<=n;i++)
    {
         if(a[i]=0) next[h1++]=i;
         else next[h2++]=i;
    }
    k=1;
    for(i=1;i<=n;i++)
    {
        k=next[k];
        printf("%d ",a[k]);
    }
}
