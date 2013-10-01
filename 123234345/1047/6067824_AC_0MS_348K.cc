#include<stdio.h>
#include<string.h>
int cycle(int a[],int b[],int n)
{
    if(b[n]) return 0;
    for(int i=0;i<n;i++)
    {
         int j;
         for(j=0;j<n;j++)
             if(a[(i+j)%n]!=b[j]) break;
         if(j==n) return 1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[61];
    while(gets(s))
    {
         int n=strlen(s),a[61]={0};
         int flag=1;
         for(int j=0;j<n/2;j++)
         {
                 char c=s[j];
                 s[j]=s[n-1-j];
                 s[n-1-j]=c;
         }
         for(int i=0;i<n;i++)
                 a[i]=s[i]-'0';
         for(int i=2;i<=n&&flag;i++)
         {
              int ans[61]={0};
              for(int j=0;j<n;j++)
                      ans[j]=a[j];
              int k=0;
              for(int j=0;j<n;j++)
              {
                  ans[j]=i*ans[j]+k;
                  k=ans[j]/10;
                  ans[j]%=10;
              }
              ans[n]=k;
              flag=cycle(a,ans,n);
         }
         for(int j=0;j<n/2;j++)
         {
                 char c=s[j];
                 s[j]=s[n-1-j];
                 s[n-1-j]=c;
         }
         printf("%s is %scyclic\n",s,flag?"":"not ");
    }
}
