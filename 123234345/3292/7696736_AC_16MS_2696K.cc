#include<stdio.h>
const int N=250001;
int v[N],p[N],pl[N];
void table()
{
     v[0]=1;
     int len=0;
     for(int i=1;i<N;i++)
          if(!v[i])
          {
               pl[len++]=i;
               __int64 t=(__int64)(i*4+1)*(i*4+1);
               if(t>=N*4+1) continue;
               for(int j=t;j<4*N+1;)
               {
                    if((j-1)%4==0) v[(j-1)/4]=1;
                    j+=4*i+1;
               }
          }
     for(int i=0;i<len;i++)
     {
          for(int j=i;j<len;j++)
          {
               __int64 t=((__int64)(4*pl[i]+1)*(4*pl[j]+1)-1)/4;
               if(t>=N) break;
               p[t]=1;
          }
     }
     for(int i=0;i<N;i++)  p[i]+=p[i-1];
}
int main()
{
    table();
    int n;
    while(scanf("%d",&n),n)
    {
        printf("%d %d\n",n,p[(n-1)/4]);
    }
}
