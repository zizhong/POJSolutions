#include<stdio.h>
#include<stdlib.h>
int start,stick[64];
bool used[64];
int cmp(const void* a,const void *b)
{
    return *(int *)b-*(int *)a;
}
bool deal(int n,int m,int left,int len)
{
     int i;
     if(m==0&&left==0) return true;
     if(left==0) i=0,left=len;
     else i=start+1;
     for(int pre=-1;i<n;++i)
     {
         if(stick[i]==pre||used[i]||stick[i]>left) continue;
         pre=stick[i];
         used[i]=true;
         start=i;
         if(deal(n,m-1,left-stick[i],len)) return true;
         used[i]=false;
         if(left==stick[i]||left==len) break;
     }
     return false;
}
int main()
{
    int i,n,sum;
    while(scanf("%d",&n)&&n)
    {
         sum=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&stick[i]);
             sum+=stick[i];
             used[i]=false;
         }
         qsort(stick,n,sizeof(stick[0]),cmp);
         for(i=stick[0];i<=sum;i++)
         {
             if(sum%i!=0) continue;
             if(deal(n,n,0,i))
             {
                 printf("%d\n",i);
                 break;
             }
         }
    }
}
