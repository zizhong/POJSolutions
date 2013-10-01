#include<stdio.h>
const int N=3001;
int a[N],b[N],next[N];
bool used[N];
int main()
{

    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)k++;
        used[i]=false;
    }
    for(i=1;i<=n-k;i++)   b[i]=0;
    for(i=n-k+1;i<=n;i++) b[i]=1; 
    for(i=1;i<=n;i++)
    {
        j=1;
        while((b[i]!=a[j])||(used[j]==true))j++;
        used[j]=true;
        next[i]=j;
    }
    k=1;
    for(i=1;i<=n;i++)
    {
        k=next[k];
        printf("%d ",a[k]);
    }
}
