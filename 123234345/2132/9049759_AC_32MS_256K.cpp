#include<iostream>
using namespace std;
typedef __int64 int64;
int64 gcd(int64 a,int64 b)
{
      return b?gcd(b,a%b):a;
}
int64 lcm(int64 a,int64 b)
{
      if(a==0) return b;
      if(b==0) return a;
      return a/gcd(a,b)*b;
}
int64 d[32][32],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
           cin>>d[i][j];
    for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++) if(d[i][k])
               for(int j=1;j<=n;j++) if(d[k][j])
                    d[i][j]=lcm(d[i][j],gcd(d[i][k],d[k][j]));
    cout<<d[1][2]<<endl;
    //cin>>n;
}
