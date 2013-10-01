#include<stdio.h>
const int N=100000;
int mod[N];
int main()
{
    int c,n;
    while(scanf("%d%d",&c,&n),c)
    {
         for(int i=0;i<c;i++)
             mod[i]=-1;
         mod[0]=0;
         int r=0,num=0,sum=0,flag=0,l=0;
         for(int i=1;i<=n;i++)
         {
              scanf("%d",&num);
              if(flag==0)
              {
                   sum+=num;
                   sum%=c;
                   if(mod[sum]>=0)
                   {
                         l=mod[sum]+1;
                         flag=1;
                         r=i;
                   }
                   else mod[sum]=i;
              }
         }
         for(int i=l;i<=r;i++) printf("%d%c",i,i==r?'\n':' ');
    }
}
