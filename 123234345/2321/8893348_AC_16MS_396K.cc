#include<cstdio>
#include<cstring>
const int N=11;
int d[N*N],key[N*N],a[N][N],num[N];
double p[N][N];
int main()
{
    for(int i=1;i<=10;i++)
          key[i*i]=i;
    int n=0;
    while(scanf("%d",&d[n])==1) n++;
    n=key[n];
    for(int i=0;i<n;i++)
    {
       num[i]=0;
       for(int j=0;j<n;j++)
           a[i][j]=d[i*n+j],num[i]+=a[i][j];
    }
    memset(p,0,sizeof(p));
    p[0][0]=1.0;
    for(int i=0;i<10;i++)
         for(int j=0;j<n;j++)
               for(int k=0;k<n;k++)
                   p[i+1][k]+=p[i][j]*a[j][k]/num[j];
    for(int i=0;i<10;i++)
    {
          for(int j=0;j<n;j++)
             printf("%.5f%c",p[i][j],j==n-1?'\n':' ');
    }
}
