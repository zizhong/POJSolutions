#include<stdio.h>
int code(char c)
{
    switch(c)
    {
        case 'B':
        case 'F':
        case 'P':
        case 'V':return 1;
        case 'C':
        case 'J':
        case 'G':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z':return 2;
        case 'D':case 'T':return 3;
        case 'L':return 4;
        case 'M':case 'N':return 5;
        case 'R':return 6;
        default :return 0;
    }
}
int main()
{
    char s[30];    
    while(scanf("%s",&s)!=EOF)
    {       
        int find[7]={1};
        int before=0;
        int i,len=strlen(s);
        for(i=0;i<len;i++)
        {
            int num=code(s[i]);
            if(before!=num)
            {
                if(num)
                printf("%d",num);
                find[num]=1;
            }
            before=num;          
        }
        printf("\n");
    }
}
