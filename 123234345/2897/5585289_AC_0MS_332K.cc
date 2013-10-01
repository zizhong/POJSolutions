#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j;
        scanf("%d%d",&n,&k);
        int num[128]={0},mark[128]={0};
        num[0]=n*k;mark[n*k]=1;
        for(i=1;;i++)
        {
            if(mark[k]) break;
            num[i]=num[i-1]%10*n+num[i-1]/10;
            if(mark[num[i]]==1) break;
            mark[num[i]]=1;
            if(mark[k]) break;
        }
        if(mark[k])
        {
             if(num[i-1]%10==0)
             {
                  printf("0\n");
                  continue;
             }
             if(i-1>0)
                  for(j=i-1;j>=0;j--) printf("%d",num[j]%10);
             printf("%d\n",k);
        }
        else printf("0\n");
    }
}
