#include<stdio.h>
const int M=6001;
const int Mid=M>>1;
const int inf=99999999;
int f[2][M];
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int n,a,b,x,d;
    scanf("%d",&n);
    for(int i=0;i<M;i++) f[0][i]=inf;
    f[0][Mid]=0;
    x=d=Mid;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<M;j++)
           f[i&1][j]=inf;
        scanf("%d%d",&a,&b);
        for(int j=x;j<=d;j++)
        {
            if(f[i&1^1][j]!=inf)
            {
                //printf("j==%d\n",j);
                if(j+a-b>=0&&j+a-b<M)
                {
                    f[i&1][j+a-b]=min(f[i&1][j+a-b],f[i&1^1][j]);
                    if(x>j+a-b) x=j+a-b;
                    if(d<j+a-b) d=j+a-b;
                }
                if(j-a+b>=0&&j-a+b<M)
                {
                    f[i&1][j-a+b]=min(f[i&1][j-a+b],f[i&1^1][j]+1);
                    if(x>j-a+b) x=j-a+b;
                    if(d<j-a+b) d=j-a+b;
                }
            }
        }
    }
    int i=0;
    while(f[n&1][Mid+i]==inf&&f[n&1][Mid-i]==inf) i++;
    int m=min(f[n&1][Mid+i],f[n&1][Mid-i]);
    //printf("%d,%d,\n",f[n&1][Mid+i],f[n&1][Mid-i]);
    printf("%d\n",m);
   // scanf("%d",&m);
}
