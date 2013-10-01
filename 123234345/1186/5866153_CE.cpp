#include<stdio.h>
#include<stdlib.h>
const int N=150*150*150,M=6;
int n,m,cnt,ans;
int k[M],p[M],array[N];
int cmp(const void *a,const void* b)
{
    return *(int *)a-*(int *)b;
}
int bs(int val)
{
    int sum=0,low=0,high=cnt-1;
    while(low<=high)
    {
         int mid=(low+high)>>1;
         if(array[mid]==val)
         {
              int left=mid-1,right=mid+1,sum=1;
              while(left>=0&&array[left--]==val) sum++;
              while(right<cnt&&array[right++]==val) sum++;
              return sum; 
         }
         else if(array[mid]<val)
              low=mid+1;
         else high=mid-1;
    }
    return 0;
}
int qpow(int b,int e)
{
    int pro=1;
    for(int i=1;i<=e;i++) pro*=b;
    return pro;
}
void Dfs(int val,int depth)
{
     if(depth==n/2)
     {
          array[cnt++]=val;
          return ;
     }
     for(int i=1;i<=m;i++)
        dfs(val+k[depth]*qpow(i,p[depth]),depth+1);
}
void dfs(int val,int depth)
{
     if(depth==n)
     {
         ans+=bs(-val);
         return ;
     }
     for(int i=1;i<=m;i++)
         dfs(val+k[depth]*qpow(i,p[depth]),depth+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
       scanf("%d%d",&k[i],&p[i]);
    Dfs(0,0);
    qsort(array,cnt,sizeof(int),cmp);
    dfs(0,n/2);
    printf("%d\n",ans);
}