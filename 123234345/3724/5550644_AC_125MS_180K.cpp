#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[11];
double cor[21][2];
int con=1;
int n;
double cal(double x)
{
       double y=0;
       for(int i=1;i<=10;i++)
           y+=pow(exp(1.0),a[i]*x);
       return y;
}
bool success()
{    
     int i;
     for(i=0;i<n;i++)
         if((int)(cal(cor[i][0])*1000+0.5)!=(int)(cor[i][1]*1000)) break;
     if(i<n) return false;
     return true;
}
void dfs(int i,int st)
{
     if(i>10)
     {
         if(success()) con=0;
         return ;
     }
     for(int j=st;j<=10&&con;j++)
     {
         a[i]=j;
         dfs(i+1,j);
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&cor[i][0],&cor[i][1]);
    }
    dfs(1,1);
    for(int i=1;i<=10;i++)
          printf("%d\n",a[i]);
    //system("pause");
}
