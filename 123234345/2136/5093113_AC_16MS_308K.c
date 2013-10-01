#include<stdio.h>
char a[300][27];
int row[300],col[26];
int main()
{
    int i,j,max=0;    
    for(j=0;j<4;j++)
    {
       char c[100]={0};
       gets(c);
       for(i=0;i<strlen(c);i++)
          if(c[i]>='A'&&c[i]<='Z')
          {
          a[col[c[i]-'A']][c[i]-'A']='*';
          col[c[i]-'A']++;
          }
    }
    for(i=0;i<26;i++)
      if(col[i]>max) max=col[i];
    for(i=0;i<max;i++)
       for(j=25;j>=0;j--)
       if(a[i][j]=='*')
       {
          row[i]=j;
          break;
       }
    for(i=max-1;i>=0;i--)
    {
       for(j=0;j<=row[i];j++)
       {
          if(j!=0) printf(" ");
          if(a[i][j]=='*') printf("*");
          else printf(" ");
       }
       printf("\n");
    }
    for(i=0;i<26;i++)
    {
       if(i!=0) printf(" ");
       printf("%c",'A'+i);
    }
    printf("\n");
}
