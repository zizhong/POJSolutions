#include<stdio.h>
#include<string.h>
char skew[50];
unsigned long bi[33];
main()
{
    int i;
    bi[0]=1;
    for(i=1;i<=31;i++)
       bi[i]=bi[i-1]*2;
    while(scanf("%s",skew)&&strcmp(skew,"0")!=0)
    {
         int m=0;
         for(i=0;i<strlen(skew)-1;i++)
            m+=(skew[i]-'0')*(bi[strlen(skew)-i]-1);
         if(strlen(skew)<32) m+=(skew[strlen(skew)-1]-'0')*(bi[strlen(skew)-1]-1);
         else m+(skew[strlen(skew)-1]-'0')*2147483647u;
         printf("%ld\n",m);
    }
}
