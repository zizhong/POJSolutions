#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int n,m;
struct Matrix
{
       int a[31][62];
       Matrix operator * (const Matrix &l)
       {
              Matrix temp;
              int i,j,k;
              memset(temp.a,0,sizeof(temp.a));
              for(i=0;i<n;i++)
                  for(j=0;j<n;j++)
                     for(k=0;k<n;k++)
                         temp.a[i][j]=(temp.a[i][j]+a[i][k]*l.a[k][j])%m;
              for(i=0;i<n;i++)
                 for(j=n;j<2*n;j++)
                 {
                      temp.a[i][j]=(temp.a[i][j]+l.a[i][j])%m;
                      for(k=0;k<n;k++)
                         temp.a[i][j]=(temp.a[i][j]+l.a[i][k]*a[k][j])%m;
                 }
              return temp;
       }
}K;
Matrix pow(Matrix &t,int k)
{
       Matrix temp;
       if(k==1) return t;
       temp=t*t;
       if(k&1) return pow(temp,k/2)*t;
       else return pow(temp,k/2);
}
int main()
{
    Matrix ss;
    int k,i,j;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
          scanf("%d",&K.a[i][j]);
    for(i=0,j=n;i<n;i++,j++) K.a[i][j]=1;
    ss=pow(K,k+1);
    for(i=0,j=n;i<n;i++,j++) ss.a[i][j]-=1;
    for(i=0;i<n;i++)
    {
       for(j=n;j<2*n-1;j++)
           printf("%d ",ss.a[i][j]%m);
       printf("%d\n",ss.a[i][j]%m);
    }
}
