#include<stdio.h>
#include<string.h>
const int N=21;
__int64 f[N],n;
int v[N];
int main()
{
    f[0]=1;
    for(int i=1;i<N;i++) f[i]=3*f[i-1];
    int T;
    scanf("%d",&T);
    while(T--)
    {
         memset(v,0,sizeof(v));
         scanf("%I64d",&n);
         __int64 x=n,ni=0;
         while(x)
         {
               v[ni++]=x%3;
               x/=3;
         }
         for(int i=0;i<ni;i++)
         {
                 if(i==ni-1&&v[i]>1) ni++;
                 if(v[i]==2) v[i]=-1,v[i+1]++;
                 else if(v[i]==3) v[i]=0,v[i+1]++;
         }
         int nl=0,nr=0;
         for(int i=0;i<N;i++) if(v[i]==-1)
         {
               nl++;
               if(nl>1) putchar(',');
               printf("%I64d",f[i]);
         }
         if(!nl) printf("empty");
         putchar(' ');
         for(int i=0;i<N;i++) if(v[i]==1)
         {
                nr++;
                if(nr>1) putchar(',');
                printf("%I64d",f[i]);
         }
         if(!nr) printf("empty");
         puts("");
    }
}
