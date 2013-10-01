#include<iostream>
#include<cstring>
using namespace std;
int a[7],s[7];
char can[120100];
bool solve()
{
     for(int i=1;i<=6;i++)
          s[i]=a[i]*i+s[i-1];
     if(s[6]%2) return false;
     memset(can,false,sizeof(char)*(s[6]+1));
     can[0]=1;
     for(int i=1;i<=6;i++)
     {
          if(a[i])
          {
               int ss=s[i]-s[i-1];
               for(int k=s[i-1];k>=0;k--)
                  if(can[k]) can[k+ss]=2;
               for(int j=0;j<i;j++)
               {
                   int n=0;
                   for(int k=s[i]-j;k>=0;k-=i)
                   if(can[k]==2)  can[k]=1,n=a[i];
                   else if(n>0) can[k]=1,n--;
               }
          }
     }
     return can[s[6]/2];
}
int main()
{
    int ncase=0;
    while(1)
    {
        for(int i=1;i<=6;i++)
            cin>>a[i];
        if(!(a[1]||a[2]||a[3]||a[4]||a[5]||a[6])) break;
        printf("Collection #%d:\nCan%s be divided.\n\n",++ncase,solve()?"":"'t");
    }
}
