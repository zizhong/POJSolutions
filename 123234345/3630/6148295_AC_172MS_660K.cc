#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100001][11];
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          int n;
          scanf("%d",&n);
          getchar();          
          for(int i=0;i<n;i++) gets(s[i]);
          qsort(s,n,sizeof(s[0]),cmp);
          int flag=1,j;
          for(int i=0;i<n-1&&flag;i++)
          {
               int len=strlen(s[i]);
               for(j=0;j<len;j++)
                   if(s[i][j]!=s[i+1][j]) break;
               flag=(j!=len);
          }
          puts(flag?"YES":"NO");
    }
}
