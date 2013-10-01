#include<stdio.h>
const int N=1121;
int v[N],pl[N],nn;
void table()
{
     v[0]=v[1]=1;
     for(int i=2;i<N;i++) if(v[i]==0)
     {
         pl[++nn]=i;
         for(int j=i*i;j<N;j+=i)
            v[j]=1;
     }     
}
int f[200][15][1121];
int main()
{
    table();
    for(int i=0;i<1121;i++)
       f[1][1][i]=-0x3fffffff;
    for(int i=1;i<=nn;i++)
       f[i][1][pl[i]]=1; 
    for(int i=2;i<=nn;i++)
       for(int j=1;j<=14;j++)
           for(int k=0;k<1121;k++)
           {
                 if(f[i-1][j][k]>0)
                      f[i][j][k]+=f[i-1][j][k];
                 if(k+pl[i]<1121)
                      f[i][j][k+pl[i]]+=f[i-1][j-1][k];
           }
    int n,m;
    while(scanf("%d%d",&n,&m),n)
         printf("%d\n",f[nn][m][n]);
}
