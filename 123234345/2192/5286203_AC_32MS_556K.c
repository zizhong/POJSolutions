#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d",&n);
    t=n;
    while(t--)
    {
       char s1[202]={'#'},s2[202]={'#'},s3[404]={'#'};
       int f[202][202]={1},len1,len2,len3,i,j;
       scanf("%s%s%s",s1+1,s2+1,s3+1);
       printf("Data set %d: ",n-t);
       f[0][0]=1;
       len1=strlen(s1)-1,len2=strlen(s2)-1,len3=strlen(s3)-1;
       if(len3!=len2+len1)  {printf("no\n");continue;}
       i=1;
       while(s1[i]==s3[i]&&i<=len1) f[i][0]=1,i++;
       i=1;
       while(s2[i]==s3[i]&&i<=len2) f[0][i]=1,i++;
       for(i=1;i<=len1;i++)
          for(j=1;j<=len2;j++)
          if(f[i][j-1]&&s2[j]==s3[i+j]||f[i-1][j]&&s1[i]==s3[i+j]) f[i][j]=1;
       /*printf("\n");
       for(i=0;i<=len1;i++)
       {
          for(j=0;j<=len2;j++)
           printf("%d ",f[i][j]);
          printf("\n");
       }*/
       if(f[len1][len2]) printf("yes\n");
       else printf("no\n");
    }
}
