#include<stdio.h>
int main()
{
    char s[100]={0};
    while(scanf("%s",s)&&strcmp(s,"0"))
    {
        while(strlen(s)!=1)
        {
        int i,sum=0;
        char snum[100]={0};
        for(i=0;i<strlen(s);i++)
            sum+=(s[i]-'0');
        sprintf(snum,"%d",sum);
        strcpy(s,snum);
       }
      printf("%d\n",s[0]-'0');
   }
}
