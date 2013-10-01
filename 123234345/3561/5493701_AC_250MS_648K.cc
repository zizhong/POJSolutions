#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int n,m,i,j;
         char s[12][12];
         memset(s,'.',sizeof(s));
         scanf("%d%d",&n,&m);
         for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
               cin>>s[i][j];
            }
         int count=0;
         for(i=1;i<=n;i++)
         {
           for(j=1;j<=m;j++)
           {
               if(s[i][j]!='.')
               {
                  count++;
                  int ki=i,kj=j;
                  switch (s[i][j])
                         {
                             case '|':
                                  while(ki<=n&&s[ki][j]=='|')
                                     s[ki][j]='.',ki++;
                                  break;
                             case '-':
                                  while(kj<=m&&s[ki][kj]=='-')
                                     s[i][kj]='.',kj++;
                                  break;
                             case '\\':
                                  while(ki<=n&&kj<=m&&s[ki][kj]=='\\')
                                     s[ki][kj]='.',ki++,kj++;
                                  break;
                             case '/':
                                  while(ki>=1&&kj<=m&&s[ki][kj]=='/')
                                     s[ki][kj]='.',ki++,kj--;
                                  break;
                         }
               }
           }
           if(count>=2) break;
         }
         if(count==1) printf("CORRECT\n");
         else printf("INCORRECT\n");
    }
}
