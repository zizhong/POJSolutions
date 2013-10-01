#include<stdio.h>
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)&&(n||q))
    {
        int i,j,date[101]={0},m,g=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
               int d;
               scanf("%d",&d);
               date[d]++;
            }
        }
        for(i=1;i<=100;i++)
            if(date[i]>date[g]) g=i;
        if(date[g]<q) g=0;
        printf("%d\n",g);
    }
}
