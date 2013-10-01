#include<stdio.h>
int w[3403],
    d[3403],
    c[12881];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
       scanf("%d%d",&w[i],&d[i]);
    
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=1;j--)
           if(j>=w[i])
           {
               if(c[j-w[i]]+d[i]>c[j])
                   c[j]=c[j-w[i]]+d[i];
           }
    }
    printf("%d\n",c[m]);
}
