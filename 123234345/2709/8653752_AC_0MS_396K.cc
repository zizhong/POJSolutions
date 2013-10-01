#include<stdio.h>
#include<stdlib.h>
const int N=12;
int d[N],n;
int cmp(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}
int ok(int cnt,int g)
{
    int rem[N];
    for(int i=0;i<n;i++)
        rem[i]=cnt*50-d[i];
    while(g>0)
    {
         qsort(rem,n,sizeof(rem[0]),cmp);
         if(rem[2])
         {
              int key=(rem[2]==1)?1:rem[2]/2;
              g-=key;
              rem[0]-=key;
              rem[1]-=key;
              rem[2]-=key;
         } else break;
    }
    return g<=0;
}
int main()
{
    int g;
    while(scanf("%d",&n),n)
    {
         int ans=0;
         for(int i=0;i<n;i++)
         {
             scanf("%d",&d[i]);
             while(ans*50<d[i]) ans++; 
         }
         scanf("%d",&g);
         while(!ok(ans,g)) ans++;
         printf("%d\n",ans);
    }
}
