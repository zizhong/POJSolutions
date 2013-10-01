#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=20001,M=21;
char s[N][M];
int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
         getchar();
         for(int i=0;i<n;i++)
         {
                 gets(s[i]);
         }
         qsort(s,n,sizeof(s[0]),cmp);
         int ans[N]={0};
         for(int i=0;i<n;i++)
         {
              int m=1;
              while(i<n-1&&strcmp(s[i],s[i+1])==0) i++,m++;
              ans[m]++;
         }
         for(int i=1;i<=n;i++)
         {
              printf("%d\n",ans[i]);
         }
    }
}
