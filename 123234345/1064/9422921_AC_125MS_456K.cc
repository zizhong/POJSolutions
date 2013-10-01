#include<stdio.h>
const int N=10000;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    __int64 d[N]={0},sum=0;
    for(int i=0;i<n;i++)
    {
        double dl;
        scanf("%lf",&dl);
        d[i]=(__int64)(dl*100);
        sum+=d[i];
    }
    if(sum<k){printf("0.00\n");return 0;}
    __int64 low=1,high=sum/k+1;
    while(low+1<high)
    {
         __int64 f=0,mid=low+high>>1;
         for(int i=0;i<n;i++)
            f+=d[i]/mid;
         if(f>=k) low=mid;
         else high=mid;
    }
    //printf("%I64d\n",low);
    printf("%.2f\n",low*0.01);
}
