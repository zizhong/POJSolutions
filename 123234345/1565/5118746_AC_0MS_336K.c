#include<stdio.h>
#include<string.h>
char skew[50];
double bi[33];
main()
{
    int i;
    bi[0]=1;
    for(i=1;i<=31;i++)
       bi[i]=bi[i-1]*2;
    while(scanf("%s",skew)&&strcmp(skew,"0")!=0)
    {
         int m=0;
         for(i=0;i<strlen(skew);i++)
            m+=(skew[i]-'0')*(bi[strlen(skew)-i]-1);
         printf("%ld\n",m);
    }
}
