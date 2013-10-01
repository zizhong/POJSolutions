#include<stdio.h>
#include<string.h>
#include<math.h>
const int N=34;
char s[N],p[N],c[N*2];
int pos(char s[],char c)
{
    int i=0;
    while(s[i]!=c) i++;
    return i;
}
int num(int m1,int m2)
{
    int k=0;
    for(;(m1^k)!=m2;k++) ;
    return k;
}
int main()
{
    int x;
    while(scanf("%d",&x),x)
    {
         scanf("%s%s%s",s,p,c);
         char m[N*2];
         int n=strlen(c),d=(int)(n*sqrt(n)+x)%n;
         m[n]=0;
         int m1,m2;
         m1=pos(s,c[d]);
         m[d]=p[m1];
         for(int i=0;i<n-1;i++)
         {
                m1=pos(s,m[(d-i+n)%n]);
                m2=pos(s,c[(d-i+n-1)%n]);
                int k=num(m1,m2);
                m[(-i-1+d+n)%n]=p[k];
         }
         puts(m);
    }
}
