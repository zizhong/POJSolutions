#include<stdio.h>
const int N=65;
char str[N][17],n,w,s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]);
    scanf("%d,%d",&w,&s);
    w--,s--;
    int a[N];
    for(int i=1;i<=64;i++)
         a[i-1]=i;
    for(int i=n;i>=1;i--)
    {
         w=(w+s)%i;
         puts(str[a[w]]);
         for(int j=w;j<i;j++)
             a[j]=a[j+1];
    }
}
