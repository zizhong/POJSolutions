#include<stdio.h>
#include<string.h>
char table[30][5]={".-","-...","-.-.","-..",".","..-.","--.",
                   "....","..",".---","-.-",".-..","--","-.",
                   "---",".--.","--.-",".-.","...","-","..-",
                   "...-",".--","-..-","-.--","--..",
                   "..--",".-.-","---.","----"};
int  m[30]={2,4,4,3,1,4,3,
            4,2,4,3,4,2,2,
            3,4,4,3,3,1,3,
            4,3,4,4,4,4,4,
            4,4};
int change(char c)
{
    if(c>='A'&&c<='Z') return c-'A';
    if(c=='_') return 26;
    if(c==',') return 27;
    if(c=='.') return 28;
    return 29;
}
char ichange(int num)
{
     if(num<26) return num+'A';
     if(num==26) return '_';
     if(num==27) return ',';
     if(num==28) return '.';
     return '?';
}
int main()
{
    int t,h;
    scanf("%d",&t);
    h=t;
    while(t--)
    {
        char s[100];
        int num[100];
        char code[400];
        char r[100];
        memset(code,'\0',sizeof(code));
        memset(r,'\0',sizeof(r));    
        scanf("%s",s);
        int len=strlen(s);
        
        for(int i=0;i<len;i++)
        {
            int j=change(s[i]);
            strcat(code,table[j]);
            num[len-i-1]=m[j];
        }        int k=0;      
        for(int i=0;i<len;i++)
        {
            char sub[5];
            for(int j=0;j<num[i];j++)
                sub[j]=code[k+j];
            sub[num[i]]='\0';
            int j;
            for( j=0;j<30;j++)
               if(!strcmp(sub,table[j])) break;
            k+=num[i];
            r[i]=ichange(j);
        }      
              
        printf("%d: %s\n",h-t,r);  
        
    }
}
