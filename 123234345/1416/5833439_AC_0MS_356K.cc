#include<stdio.h>
#include<string.h>
int main()
{
    char s[10];
    int num1;
    while(scanf("%d%s",&num1,s),num1)
    {      
         int len=strlen(s);
         int n=1<<(len-1);
         
         int r=-1,way=-1,er=0;
         for(int i=0;i<n;i++)
         {
              int sum=0,last=s[0]-'0';
              for(int j=0;j<len-1;j++)
              {
                   int flag=(i>>j)&1;
                   if(flag) sum+=last,last=s[j+1]-'0';
                   else last=last*10+s[j+1]-'0';
              }
              sum+=last;
              if(sum<=num1&&sum==r) er=1;
              if(sum<=num1&&sum>r) r=sum,way=i,er=0;
         }
         if(r==-1) printf("error\n");
         else if(er) printf("rejected\n");
         else
         {
             printf("%d %d",r,s[0]-'0');
             for(int i=0;i<len-1;i++)
             {
                  if((way>>i)&1) printf(" ");
                  printf("%d",s[i+1]-'0');
             }
             printf("\n");
         }
    }
}
