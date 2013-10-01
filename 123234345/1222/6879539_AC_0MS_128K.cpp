#include<stdio.h>
#include<string.h>
const int N=31;
int a[N][N],n=30,m=30,x[N];
int gcd(int a,int b){return b?gcd(b,b%a):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
int _abs(int a){return a>0?a:-a;}
void Gauss()
{
    int i,j;
    for(int k=0,col=0;k<n&&col<m;k++,col++)
    {
         int mi=k;
         for(i=k+1;i<n;i++)
            if(_abs(a[i][col])>_abs(a[mi][col])) mi=i;
         if(mi!=k) for(j=k;j<N;j++) 
             {int t=a[k][j];a[k][j]=a[mi][j];a[mi][j]=t;}
         for(i=k+1;i<n;i++)
         {
              if(a[i][col])
              {
                   int LCM=lcm(_abs(a[i][col]),_abs(a[k][col]));
                   int ta=LCM/_abs(a[i][col]),tb=LCM/_abs(a[k][col]);
                   if(a[i][col]*a[k][col]<0) tb*=-1;
                   for(j=col;j<N;j++)
                        a[i][j]=((a[i][j]*ta-a[k][j]*tb)%2+2)%2;
              }
         }
    }
    for(i=n-1;i>=0;i--)
    {
        int t=a[i][n];
        for(j=i+1;j<m;j++)
            t=((t-a[i][j]*x[j])+2)%2;        
        x[i]=t/a[i][i];
    } 
   
}
int main()
{
    int T,i;
    scanf("%d",&T);
    int h=T;
    while(T--)
    {
         memset(a,0,sizeof(a));
         for(i=0;i<n;i++)
         {
              scanf("%d",&a[i][n]);
              a[i][i]=1;
              if(i%6) a[i][i-1]=1;
              if((i+1)%6) a[i][i+1]=1;
              if(i-6>=0) a[i][i-6]=1;
              if(i+6<n) a[i][i+6]=1;
         }
         Gauss();
         printf("PUZZLE #%d\n",h-T);
         for(i=0;i<n;i++) printf("%d%c",x[i],(i+1)%6?' ':'\n');
    }
}
