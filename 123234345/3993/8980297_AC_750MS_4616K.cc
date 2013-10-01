#include<stdio.h>
const int N=1000001;
int plen=0,pl[N/2];
int v[N]={1,1};
void table()
{
     for(int i=2;i<N;i++)
         if(v[i]==0)
         {
              pl[plen++]=i;
              for(int j=i+i;j<N;j+=i)
                 v[j]=1;
         }
}
int main()
{
    table();
    int a,b;
    int T=1;
    while(scanf("%d%d",&a,&b),a)
    {
         int sum=0,nl=0;
         for(int i=0;i<plen;i++)
         {
               int x=0,y=0;
               while(a%pl[i]==0) a/=pl[i],x++;
               while(b%pl[i]==0) b/=pl[i],y++;
               if(x+y) nl++; 
               sum+=x>y?x-y:y-x;
         }
         printf("%d. %d:%d\n",T++,nl,sum);
    }
}