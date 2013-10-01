#include<stdio.h>
char s[1001];
char r[1001];
int num[10];
int div(int d)
{
    int len=strlen(s);
    int i,t=0;
    for(i=0;i<len;i++)
    {
        t=10*t+s[i]-'0';
        r[i]=t/d+'0';
        t=t%d;
    }
    if(r[0]=='0')
    {
        for(i=1;i<len;i++)
           r[i-1]=r[i];
        r[len-1]='\0';
    }
    return t;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
     while(scanf("%s",s)&&s[0]!='-')
    {
         if(strlen(s)==1)
         {
             printf("1%s\n",s);
         }
         else
         {
             int i;
             memset(num,0,sizeof(num));
             for(i=9;i>=2;i--)
             {
                 while(!div(i))
                 {
                     num[i]++;
                     strcpy(s,r);
                     memset(r,0,sizeof(r));
                 }
             }
             if(strcmp(s,"1"))
                 printf("There is no such number.\n");
              // printf("s==%s\n",s);  
             else
             {
                 for(i=2;i<=9;i++)
                 {
                     while(num[i]--)
                        printf("%d",i);
                 }
                 printf("\n");
             }
         }
    }
}
