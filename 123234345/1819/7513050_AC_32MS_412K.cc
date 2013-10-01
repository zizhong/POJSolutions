#include<stdio.h>
#include<math.h>
#include<string.h>
const int N=1001;
double r[N],ax[N];
int st[N],p;
int ok(int x)
{
    double r1=r[st[p-1]],r2=r[st[p-2]],cr=r[x];
    double d1,d2;
    if(st[p-2]==0) d2=cr;
    else d2=2*sqrt(cr*r2)+ax[st[p-2]];
    d1=2*sqrt(cr*r1)+ax[st[p-1]];
    if(d2>d1+1e-8) {--p;return 0;}
    else
    {
        ax[x]=d1;
        st[p++]=x;
        return 1;
    }
}
int main()
{
    int n;
    int T=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
         scanf("%lf",&r[i]);
    ax[0]=0;ax[1]=r[1];
    st[p++]=0,st[p++]=1;
    for(int i=2;i<=n;i++)
    {        
         double max=r[i];
         int mp=0;
         for(int k=1;k<p;k++)
         {
              if(2*sqrt(r[i]*r[st[k]])+ax[st[k]]>max)
                     max=ax[st[k]]+2*sqrt(r[i]*r[st[k]]),
                     mp=k;
         }
         ax[i]=max;
         p=mp+1;
         st[p++]=i;
    }
    double rr[N]={0};
    for(int i=0;i<p;i++)
          rr[i]=ax[st[i]]+r[st[i]];
    int mi=0;
    for(int i=1;i<p;i++)
         if(rr[i]>rr[mi]+1e-8) mi=i;
    p=mi+1;
    int v[N]={0};
    for(int i=1;i<p;i++)
         v[st[i]]=1;
    printf("%d\n",n-p+1);
    for(int i=1;i<=n;i++)
       if(v[i]==0)
            printf("%d\n",i);
}
