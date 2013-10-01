#include<stdio.h>
#include<string.h>
const int N=10000,M=1230;
int pl[N],np,v[N];
void table()
{
     v[0]=v[1]=1;
     for(int i=2;i<N;i++) if(!v[i])
     {
            pl[np++]=i;
            for(int j=i+i;j<N;j+=i) v[j]=1;
     }
}
int fac[M],tmp[M];
void add_fac(int x,int flag)
{
    for(int i=0;i<np;i++)
    {
         tmp[i]=0;
         int a=pl[i];
         while(a<=x)
         {
              tmp[i]+=x/a;
              a*=pl[i];
         }
    }
    for(int i=0;i<np;i++)
       if(flag) fac[i]-=tmp[i];
       else fac[i]+=tmp[i];
}
double power(int p,int n)
{
       if(n==0) return 1.0;
       double ans=1.0;
       for(int i=0;i<n;i++) ans*=p;
       return ans;
}
int main()
{
    table();
    int p,q,r,s;
    while(scanf("%d%d%d%d",&p,&q,&r,&s)==4)
    {
          memset(fac,0,sizeof(fac));
          add_fac(p,0);
          add_fac(s,0);
          add_fac(r-s,0);
          add_fac(q,1);
          add_fac(p-q,1);
          add_fac(r,1);
          double num=1,dom=1,ans=1.0;
          for(int i=0;i<np;i++)
          {
             if(fac[i]>0) ans*=power(pl[i],fac[i]);
             else ans/=power(pl[i],-fac[i]);
          }
          printf("%.5lf\n",ans);
          //printf("%.5f\n",num/dom);
    }
}
