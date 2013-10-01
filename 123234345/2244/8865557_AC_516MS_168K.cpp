#include<stdio.h>
const int N=151;
int f[N],n;
bool ok(int m)
{
     int v[N]={0};
     v[1]=1;
     int p=1;
     for(int i=1;i<n-1;i++)
     {
         int tmp=m;
         while(tmp--)
         {
             p++;
             if(p==n+1) p=1;
             while(v[p])
             {
                  p++;
                  if(p==n+1) p=1;
             }
         }
         v[p]=1;
         if(p==2) return false;
     }
     return true;
}
void solve()
{
     if(f[n])
     {
         printf("%d\n",f[n]);
         return ; 
     }
     for(int i=1;;i++)
     {
          if(ok(i))
          {
              f[n]=i;
              printf("%d\n",i);
              return ;
          }
     }
}
int main()
{
    while(scanf("%d",&n),n)
    {
         solve();
    }
}
