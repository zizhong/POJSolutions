#include<stdio.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
          int num[301]={0};
          getchar();
          char s[601];
          for(int i=0;i<m;i++)
          {
                  gets(s);
                  for(int j=0;j<n;j++)
                      num[j]+=s[2*j]-'0';
          }
          int i;
          for( i=0;i<n;i++) if(num[i]==1) break;
          puts(i<n?"Yes, I found it":"It is impossible");
    }
}
