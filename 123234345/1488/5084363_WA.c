#include<stdio.h>
main()
{
     char c;
     int i=0;
     c=getchar();
     while(c!=EOF)
     {
        i++;
        if(c!='"') printf("%c",c);
        else if(i%2) printf("''");
        else printf("``");
        c=getchar();
     } 
} 
