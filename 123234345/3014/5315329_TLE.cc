#include<stdio.h>
const int bignum=1000000007;
int f(int m,int n)
{ 
   if(m<0) return 0;
   if(m==0||n==1)
   return 1;
   return (f(m-n,n)%bignum+f(m,n-1)%bignum)%bignum;
}
int main()
{
    int m,n,k=0;
    scanf("%d%d",&n,&m);
    printf("%d\n",f(m,n));
}
