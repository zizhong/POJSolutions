#include<stdio.h>
const int N=65536;
int v[N+10];
int main()
{
    int a,b,c,s;
    while(scanf("%d",&a),a)
    {
         scanf("%d%d%d",&b,&c,&s);
         for(int i=0;i<c;i++) v[i]=0;
         long long d=s;
         while(!v[d])
         {
              v[d]=1;
              d=(a*d+b)%c;
         }
         for(int i=15;i>=0;i--)
         {
              int bit=(s>>i)&1,flag=0;
              for(int j=0;j<c;j++)
                   if(v[j]&&((j>>i)&1)!=bit)
                       flag=1;
              putchar(flag?'?':'0'+bit);
         }
         puts("");
    }
}
