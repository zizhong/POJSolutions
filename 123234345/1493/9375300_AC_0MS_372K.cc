#include<cstdio>
#include<cstring>
int n,d[15];
int main()
{
    while(scanf("%d",&n),n)
    {
         getchar();
         for(int i=0;i<n;i++)
         {
              char s[50];
              scanf("%s",s);
              int len1=strlen(s);
              if(len1==25) d[i]=0;
              else
              {
                  scanf("%s",s);
                  int len2=strlen(s);
                  d[i]=25-len1-len2;
              }
         }
         int min=25,ans=0;
         for(int i=0;i<n;i++)
             if(min>d[i]) min=d[i];
         for(int i=0;i<n;i++)
             ans+=d[i]-min;
         printf("%d\n",ans);
    }
}
