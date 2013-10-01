#include<cstdio>
#include<cstring>
const int N=110;
int n;
struct Matrix
{
       __int64 a[N][N];
       Matrix()
       {
             memset(a,0,sizeof(a));
       }
       Matrix(char ch)
       {
           memset(a,0,sizeof(a));
           for(int i=0;i<n;i++)a[i][i]=1;
           int x,y;
           switch(ch)
           {
                 case 'g':
                      scanf("%d",&x);
                      a[n-1][x-1]=1;
                      break;
                 case 'e':
                      scanf("%d",&x);
                      a[x-1][x-1]=0;
                      break;
                 case 's':
                      scanf("%d%d",&x,&y);
                      if(x==y) break;
                      a[x-1][x-1]=a[y-1][y-1]=0;
                      a[x-1][y-1]=a[y-1][x-1]=1;
                      break;
           }
       }
       Matrix operator * (Matrix &l)
       {
              Matrix tmp;
              for(int i=0;i<n;i++)
                  for(int j=0;j<n;j++)
                     for(int k=0;k<n;k++)
                          tmp.a[i][j]+=a[i][k]*l.a[k][j];
              return tmp;
       }
       void One(){for(int i=0;i<n;i++) a[i][i]=1;}
};
Matrix pow(Matrix &t,int n)
{
       Matrix tmp;
       tmp.One();
       while(n)
       {
            if(n&1)  tmp=tmp*t;
            n>>=1;
            t=t*t;
       }
       return tmp;
}
int m,k;
int main()
{
    while(scanf("%d%d%d",&n,&m,&k),n+m+k)
    {
          n++;
          Matrix m1;
          m1.One();
          for(int i=0;i<k;i++)
          {
                char s[2];
                scanf("%s",s);
                Matrix t1(s[0]);
                m1=m1*t1;
          }
          Matrix ans=pow(m1,m);
          //for(int i=0;i<n;i++,puts(""))
          //    for(int j=0;j<n;j++)
          //        printf("%d ",ans.a[i][j]);
          for(int i=0;i<n-1;i++) 
               printf("%I64d%c",ans.a[n-1][i],i==n-2?'\n':' ');
    }
}
