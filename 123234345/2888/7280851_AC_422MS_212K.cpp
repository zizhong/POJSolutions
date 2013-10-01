#include<stdio.h>
#include<string.h>
const int N=11,mod=9973;
int m,n;
struct Matrix
{
       int a[N][N];
       int n;
       Matrix operator * (const Matrix &l)
       {
              Matrix temp;
              temp.n=n;
              memset(temp.a,0,sizeof(temp.a));
              for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                 {
                     for(int k=0;k<n;k++)
                         temp.a[i][j]+=a[i][k]*l.a[k][j];
                 temp.a[i][j]%=mod; 
                 }
              return temp;
       }
}M;
Matrix pow(Matrix &t,int x)
{
       Matrix temp=t;
       if(x==1) return t;
       temp=t*t;
       if(x&1) return pow(temp,x/2)*t;
       return pow(temp,x/2);
}
int phi(int n)
{
    int res=1;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        {
             res=res*(i-1);
             n/=i;
             while(n%i==0)
             {
                  res=res*i;
                  n/=i;
             }             
        }
    if(n>1) res=res*(n-1);
    return res%mod;
}
int gettr(int x)
{
    Matrix t;
    t=pow(M,x);
    int res=0;
    for(int i=0;i<t.n;i++)
          res=(res+t.a[i][i])%mod;
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d%d",&n,&m);
         int k;
         M.n=m;
         for(int i=0;i<m;i++)
              for(int j=0;j<m;j++)
                  M.a[i][j]=1;
         scanf("%d",&k);
         for(int i=0;i<k;i++)
         {
              int x,y;
              scanf("%d%d",&x,&y);
              x--,y--;
              M.a[x][y]=M.a[y][x]=0;
         }
         int ans=0;
         for(int i=1;i*i<=n;i++) if(n%i==0)
         {
              ans=(ans+phi(n/i)*gettr(i)%mod)%mod;
              if(i*i<n) ans=(ans+phi(i)*gettr(n/i)%mod)%mod;
         }
         int tt;
         for(tt=1;;tt++) 
              if(((long long)n*tt-ans)%mod==0)
                   break;
         printf("%d\n",tt%mod);
    }
}
