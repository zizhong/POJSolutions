#include<stdio.h>
#include<string.h>
const __int64 inf = ((__int64)1)<<60;
__int64 p[510],done[510];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n,k;
         scanf("%d%d",&n,&k);
         int b1[500]={0};
         __int64 l=0,r=0;
         for(int i=0;i<n;i++)
         {
              scanf("%I64d",&p[i]);
              if(p[i]>l) l=p[i];
              r+=p[i];
         }
         l--;
         while(l+1<r)
         {
              int num=1;
              __int64 mid=l+r>>1;
              memset(done,0,sizeof(done));
              for(int i=0;i<n;i++)
              {
                   if(done[num]+p[i]>mid)
                   {
                        num++;
                        done[num]=p[i];
                   } else done[num]+=p[i];
                   b1[i]=num;
              }
              if(num>k) l=mid;
              else r=mid;
              //printf("%d %lld %lld %I64d\n",num,l,r,mid);
         }
         
         int num=1;
         memset(done,0,sizeof(done));
         for(int i=n-1;i>=0;i--)
         {
            if(done[num]+p[i]>r)
            {
                  num++;
                  done[num]=p[i];
            }else done[num]+=p[i];
            b1[i]=num;
         }
         int h=0,t=-1;
         while(num<k)
         {
              for(;h<n-1;h++)
              {
                    if(b1[h]==b1[h+1])
                    {
                        b1[h]=t;
                        t--;
                        num++;
                        break;
                    }
              }
         }
         
         for(int i=0;i<n;i++)
         {
               if(i==0) printf("%I64d",p[i]);
               else
               {
                   if(b1[i-1]!=b1[i]) printf(" /");
                   printf(" %I64d",p[i]);
               }
         }
         puts("");
    }
}
