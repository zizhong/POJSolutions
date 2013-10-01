#include<cstdio>
#include<cstring>
const int N=4,mod=2005;
struct Matrix
{
       int a[N][N];
       Matrix(){memset(a,0,sizeof(a));}
       void One(){for(int i=0;i<N;i++) a[i][i]=1;}
       Matrix operator *(Matrix &l)
       {
              Matrix tmp;
              for(int i=0;i<N;i++)
                  for(int j=0;j<N;j++)
                  {
                       for(int k=0;k<N;k++)
                            tmp.a[i][j]+=a[i][k]*l.a[k][j];
                       tmp.a[i][j]%=mod;
                  }
              return tmp;
       }
}M;
Matrix pow(Matrix &t,int k)
{
       Matrix tmp;
       tmp.One();
       while(k)
       {
            if(k&1) tmp=tmp*t;
            t=t*t;
            k>>=1;
       }
       return tmp;
}
void init_M()
{
     memset(M.a,0,sizeof(M.a));
     for(int i=1;i<N;i++) M.a[i-1][i]=1;
     M.a[3][0]=1;
     M.a[3][1]=1;
     M.a[3][3]=1;
}/*
void disp(Matrix &mm)
{
     puts("---------------");
     for(int i=0;i<N;i++,puts(""))
         for(int j=0;j<N;j++)
             printf("%d ",mm.a[i][j]);
}*/
int n,f[6]={0,2,4,6,9};
int solve()
{
    if(n<=4) return f[n];
    init_M();
    Matrix ans=pow(M,n-4);
    int ret=0;
    for(int i=0;i<N;i++)
        ret+=ans.a[3][i]*f[i+1];
    return ret%mod;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
         printf("%d\n",solve());
    }
}
