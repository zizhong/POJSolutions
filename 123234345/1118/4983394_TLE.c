#include<stdio.h>
#define NMAX 9999999
double a[2][700];
int main()
{
    int n=0;
    while(scanf("%d",&n)&&n)
    {  
       short connect[700][700]={0};
       int x,y,i,j,k,ans=2,max=0;
       double k1=0,k2=0;
       for(i=1;i<=n;i++)
           scanf("%lf%lf",&a[0][i],&a[1][i]);
       for(i=1;i<=n-ans;i++)
       {    
         max=0;
           for(j=i+1;j<=n+1-ans;j++)
         {   
             if(!connect[i][j])
            { 
            connect[i][j]=1;
            max=2;
            if(a[0][i]-a[0][j])
               k1=(a[1][i]-a[1][j])/(a[0][i]-a[0][j]);
            else k1=NMAX;
            for(k=j+1;k<n+2-ans;k++)
             {  
               if(!connect[i][k])
                {
                if(a[0][i]-a[0][k]) k2=(a[1][i]-a[1][k])/(a[0][i]-a[0][k]);
                else k2=NMAX;
                if(k1==k2)
                  { connect[i][k]=connect[j][k]=1;
                   max++;}
                }
             }
            if(max>ans) ans=max;
            }
         }         
      }
      printf("%d\n",ans);
    }
}
