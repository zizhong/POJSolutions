#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
         int a=0,b=0,c=0,m=n-k;
         while(n) {n/=2;a+=n;}
         while(k) {k/=2;b+=k;}
         while(m) {m/=2;c+=m;}
         if(a>b+c) printf("0\n");
         else printf("1\n");
    }
    
}
