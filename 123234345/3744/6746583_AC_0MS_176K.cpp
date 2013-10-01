#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
struct Matrix
{
       double a[2][2];
       Matrix operator * (const Matrix &l)
       {
              Matrix temp;
              memset(temp.a,0,sizeof(temp.a));
              for(int i=0;i<2;i++)
                 for(int j=0;j<2;j++)
                     for(int k=0;k<2;k++)
                         temp.a[i][j]+=a[i][k]*l.a[k][j];
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
int main()
{
    int n;
    double p;
    int mine[11];
    while(scanf("%d%lf",&n,&p)==2)
    {
          for(int i=0;i<n;i++)
                  scanf("%d",&mine[i]);
          qsort(mine,n,sizeof(mine[0]),cmp);
          int flag=0;
          for(int i=0;i<n-1&&!flag;i++)
          {
                  if(mine[i]+1==mine[i+1]) flag=1;
          }
          if(flag==1||mine[0]==1)
          {
                  puts("0.0000000");
                  continue;
          }
          M.a[0][0]=0,M.a[0][1]=1,M.a[1][0]=1-p,M.a[1][1]=p;
          for(int i=0;i<n;i++)
          {
                  int j=i+1;
                  while(mine[j]==mine[i]) j++,mine[j]=100000001;
                  i=j-1;
          }
          qsort(mine,n,sizeof(mine[0]),cmp);
          double ans=1;
          int t=1;
          for(int i=0;i<n&&mine[i]<100000001;i++)
          {
                int k=mine[i]-t-1;
                if(k)
                {
                     Matrix temp;
                     temp=pow(M,k);
                     ans*=temp.a[1][1];
                }
                ans*=(1-p);
                t=mine[i]+1;
          }
          printf("%.7f\n",ans);
    }
}
