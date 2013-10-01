/*
ID: zhangzz4
PROG: twofive
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int m,a[5],l[26],f[6][6][6][6][6];
char s[30];
int dp(int p)
{
    if(f[a[0]+1][a[1]+1][a[2]+1][a[3]+1][a[4]+1]>=0)
        return f[a[0]+1][a[1]+1][a[2]+1][a[3]+1][a[4]+1];
    int ans=0;
    if(p==25) ans=1;
    else if(l[p]>=0)
    {
         int x=l[p]%5,
             y=l[p]/5;
             if(a[y]!=x-1) ans=0;
             else
             {
                 ++a[y];
                 ans+=dp(p+1);
                 --a[y];
             }
    }
    else
    {
        for(int y=0;y<5;y++)
        {
             int x=a[y]+1;
             if(y==0&&x<=4 || y>0&&x<=a[y-1])
             {
                  ++a[y];
                  ans+=dp(p+1);
                  --a[y];
             }
        }
    }
    f[a[0]+1][a[1]+1][a[2]+1][a[3]+1][a[4]+1]=ans;
    return ans;
}
int find()
{
    memset(a,-1,sizeof(a));
    memset(f,-1,sizeof(f));
    memset(l,-1,sizeof(l));
    for(int i=0;i<=m;i++)
    {
         if(l[s[i]-'A']!=-1) return 0;
         if(i/5!=0 && s[i-5]>s[i]) return 0;
         if(i%5!=0 && s[i-1]>s[i]) return 0;
         l[s[i]-'A']=i;
    }
    return dp(0);
}
void doit_N()
{
     int n;
     scanf("%d",&n);
     --n;
     for(m=0;m<25;m++)
     {
         s[m]='A';
         int p;
         while(p=find(),p<=n)
         {
              n-=p;
              ++s[m];
         }
     }
     for(int i=0;i<25;i++)
          putchar(s[i]);
     puts("");
}
void doit_W()
{
     int ans=0;
     char t[30];
     scanf("%s",t);
     for(m=0;m<25;m++)
     {
          s[m]='A';
          while(s[m]<t[m])
          {
               ans+=find();
               ++s[m];
          }
     }
     ++ans;
     printf("%d\n",ans);
}
int main()
{
    //freopen("twofive.in","r",stdin);
    //freopen("twofive.out","w",stdout);
    char c=getchar();
    if(c=='N') doit_N();
    if(c=='W') doit_W();
}
