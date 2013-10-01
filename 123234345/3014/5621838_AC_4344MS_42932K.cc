#include<stdio.h>
int d[4510][4510];
const int bignum=1000000007;
int f(int m,int n)
{ 
    
   if(m<0) return 0;
   if(m==0||n==1)   return 1;
   if(d[m][n]) return d[m][n];
   return d[m][n]=(f(m-n,n)+f(m,n-1))%bignum;
}
int main()
{
    int m,n,k=0;
    scanf("%d%d",&n,&m);
    printf("%d\n",f(m,n));
}

