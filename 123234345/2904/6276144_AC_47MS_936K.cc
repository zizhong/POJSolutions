#include<stdio.h>
const int N=101;
int F[11][N][N];
int _max(int a,int b){return a>b?a:b;}
int _min(int a,int b){return a<b?a:b;}
int f(int k,int m1,int m2)
{
    if(m1>m2) return 0;
    if(m1==m2) return m1;
    if(k==1) return (m1+m2)*(m2-m1+1)/2;
    if(F[k][m1][m2]) return F[k][m1][m2];
    F[k][m1][m2]=0x7fffffff;
    for(int i=m1;i<=m2;i++)
        F[k][m1][m2]=_min(F[k][m1][m2],i+_max(f(k-1,m1,i-1),f(k,i+1,m2)));
    return F[k][m1][m2];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int k,m;
         scanf("%d%d",&k,&m);
         printf("%d\n",f(k,0,m));
    }
}
