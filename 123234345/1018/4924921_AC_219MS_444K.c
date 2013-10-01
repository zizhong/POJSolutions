#include<stdio.h>
int m[101],v[101][101][2];
int b[10001];
main()
{
   int t,i,j,k,n,h;
   float maxi,sum,minr;
   scanf("%d",&t);
   while(t--)
   {  
     scanf("%d",&n);
     h=1;
     for(i=1;i<=n;i++)
     {
       scanf("%d",&m[i]);
       for(j=1;j<=m[i];j++)
       {
           scanf("%d%d",&v[i][j][0],&v[i][j][1]);
           b[h++]=v[i][j][0];
       }
     }
     maxi=0;
     for(i=1;i<h-1;i++)
         for(j=i+1;j<h;j++)
         if(b[j]==b[i]) b[j]=0;
     for(i=1;i<h;i++)
     {
         if(!b[i]) continue;
        sum=0;
         for(j=1;j<=n;j++)
        {   minr=100000;
            for(k=1;k<=m[j];k++)
            if(b[i]<=v[j][k][0]&&minr>v[j][k][1])
               minr=v[j][k][1];
         sum=minr+sum;
        }
        if(maxi<b[i]/sum)
          maxi=b[i]/sum;
     }
     printf("%.3f\n",maxi);
   }
}
