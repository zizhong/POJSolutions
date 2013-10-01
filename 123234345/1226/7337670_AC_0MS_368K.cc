#include<stdio.h>
#include<string.h>
const int N=101;
char s[101][101];
int n;
int exists(int st,int len)
{
    char s1[N],s2[N];
    for(int i=st;i<st+len;i++)
         s1[i-st]=s[1][i],s2[len-1-i+st]=s[1][i];
    s1[len]=s2[len]=0;
    for(int i=2;i<=n;i++)
       if(strstr(s[i],s1)==NULL&&strstr(s[i],s2)==NULL) return 0;
    return 1;
}
int solve()
{
     int len=strlen(s[1]);
     int k;
     for(k=len;k>=1;k--)
     {
          for(int i=0;i<=len-k;i++)
          {
              if(exists(i,k)) return k;
          }
     }
     return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
             gets(s[i]);
        printf("%d\n",solve());
    }
}
