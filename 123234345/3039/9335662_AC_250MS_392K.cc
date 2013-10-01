#include<cstdio>
#include<cstring>
#include<cmath>
int n,d;
int ans[2];
double delta;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    scanf("%d%d",&n,&d);
    delta=1e10;
    for(int i=1;i<=32767;i++)
    {
         int j1=(int)floor(n*i*1.0/d);
         int j2=(int)ceil(n*i*1.0/d);
         if(i==d)
         {
               j1=n-1;
               j2=n+1;
         }
         while(j1>=1 && gcd(j1,i)>1) j1--;
         while(j2<=32767 && gcd(j2,i)>1) j2++;
         if(j1>=1)
         {
              double eps=fabs(n*1.0/d - j1*1.0/i);
              if(eps<delta)
              {
                   delta=eps;
                   ans[0]=j1;
                   ans[1]=i;
              }
         }
         if(j2>=1)
         {
              double eps=fabs(n*1.0/d - j2*1.0/i);
              if(eps<delta)
              {
                   delta=eps;
                   ans[0]=j2;
                   ans[1]=i;
              }
         }
    }
    printf("%d %d\n",ans[0],ans[1]);
    //scanf("%'d");
}
