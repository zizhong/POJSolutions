#include<stdio.h>
const int N=10000;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int d[N]={0};
    int sum=0;
    for(int i=0;i<n;i++)
    {
        double dl;
        scanf("%lf",&dl);
        d[i]=(int)(dl*100);
        sum+=d[i];
    }
    if(sum<k){printf("0.00\n");return 0;}
    int low=1,high=sum/k,mid=(low+high)>>1;
    while(low+1<high)
    {
         int f=0;
         for(int i=0;i<n;i++)
            f+=d[i]/mid;
         if(f>=k) low=mid;
         else high=mid;
         mid=(low+high)>>1;
    }
    printf("%.2f\n",low*0.01);
    //scanf("%d%d",&n,&k);
}
