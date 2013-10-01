#include<stdio.h>
main()
{
     char c;
     int i=0;
     c=getchar();
     while(c!=EOF)
     {
        if(c!='"') printf("%c",c);
        else if(i%2==0) {printf("``");i++;}
        else {printf("''");i++;}
        c=getchar();
     } 
} 
