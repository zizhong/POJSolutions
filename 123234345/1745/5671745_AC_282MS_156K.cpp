#include<stdio.h>
int f[2][101];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        a=(a%k+k)%k;
        {
        for(int j=0;j<k;j++) f[i&1][j]=0;
        for(int j=0;j<k;j++)
           if(f[(i+1)&1][j])
                    f[i&1][(j+a)%k]=f[i&1][((j-a)%k+k)%k]=1;
        }
    }
    if(f[n&1][0]) printf("Divisible\n");
    else printf("Not divisible\n");
}
