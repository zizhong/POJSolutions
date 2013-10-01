#include<stdio.h>
long long ten[16],num[26];
int dig[22],nd;
void digit(int x)
{
     nd=0;
     while(x)
     {
          dig[nd++]=x%10;
          x/=10;
     }
     for(int i=0;i<nd/2;i++)
     {
          int t=dig[i];
          dig[i]=dig[nd-1-i];
          dig[nd-1-i]=t;
     }
}
int main()
{
    ten[0]=1;
    for(int i=1;i<15;i++) ten[i]=ten[i-1]*10;
    for(int i=1;;i++)
    {
         num[i]=ten[(i-1)>>1]-1+8*ten[(i-1)>>1];
         if(num[i]>2*ten[9]) break;   
    }
    long long n;
    while(scanf("%lld",&n),n)
    {
          int d=1;
          while(n>num[d]) n-=num[d],d++;
          digit(n-d+ten[(d-1)>>1]);
          if(d&1)
          {
               for(int i=0;i<nd;i++) putchar(dig[i]+'0');
               for(int i=nd-2;i>=0;i--) putchar(dig[i]+'0');
               puts("");
          } 
          else
          {
               for(int i=0;i<nd;i++) putchar(dig[i]+'0');
               for(int i=nd-1;i>=0;i--) putchar(dig[i]+'0');
               puts("");
          }
    }
}
