#include<stdio.h>
#include<string.h>
#include<math.h>
int m;
bool prime(int n)
{
     int sq=int(sqrt(n*1.0));
     for(int i=2;i<=sq;i++)
     {
          if(n%i==0) return false;
     }
     return true;
}
int modpow(int a,int p)
{
    if(p==1) return a;
    int r=modpow(a,p/2)%m*modpow(a,p/2)%m;
    if(p&1) r=r*a%m;
    return r;       
}
int main()
{
    int p,a;
    while(scanf("%d%d",&p,&a)&&(p||a))
    {
        m=p;
        if(prime(p)) printf("no\n");
        else
        {
            if(modpow(a,p)==a)
               printf("yes\n");
            else printf("no\n");
        }
    }
}
