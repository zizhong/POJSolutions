#include<stdio.h>
int f[2][101];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        a=(a%k+a)%k;
        if(i==1)
        {
            f[i][a]=1,f[i][0]=1;
        }
        else
        for(int j=0;j<=k;j++)
           if(f[(i+1)%2][j])
               f[i%2][(j+a)%k]=f[i%2][((j-a)%k+k)%k]=1;
    }
    if(f[n%2][0]) printf("Divisible\n");
    else printf("Not divisible\n");
    //scanf("%d",&n);
}
