#include<stdio.h>
int main()
{
    int n,i,j,max=0,maxi=0,score;
    for(i=1;i<=n;i++)
    {
       int win=0;
       for(j=0;j<n;j++)
       {
          scanf("%d",&score);
          if(score>=3) win++;
       }
       if(win>max)
       {
          max=win;
          maxi=i;
       }
    }
    printf("%d\n",maxi);
}