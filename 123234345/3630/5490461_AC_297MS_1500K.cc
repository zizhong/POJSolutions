#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[10000][100];
int cmp(const void *a,const void*b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int n,i;
         scanf("%d",&n);
         for(i=0;i<n;i++)
            scanf("%s",s[i]);
         qsort(s,n,sizeof(s[0]),cmp);
         for(i=0;i<n-1;i++)
         {
              if(strncmp(s[i],s[i+1],strlen(s[i]))==0)
                  break;
         }
         if(i<n-1) printf("NO\n");
         else printf("YES\n");
    }
}
