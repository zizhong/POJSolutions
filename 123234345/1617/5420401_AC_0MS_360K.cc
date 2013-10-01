#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;   
}
int main()
{
    char key[11];
    while(scanf("%s",key)&&strcmp(key,"THEEND"))
    {
        char cipertext[101],ikey[11];
        char plaintext[11][11];
        int c[11]={0},n,m;
        memset(plaintext,'\0',sizeof(cipertext));
        scanf("%s",cipertext);
        strcpy(ikey,key);
        m=strlen(key),n=strlen(cipertext)/m;
        
        qsort(ikey,m,sizeof(ikey[0]),cmp);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
               if(ikey[j]==key[i])
               {
                  ikey[j]='\0';
                  c[j]=i;
                  break;
               }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                plaintext[j][c[i]]=cipertext[n*i+j];
            }
        }
        
        for(int i=0;i<n;i++)
           {
           for(int j=0;j<m;j++)
              printf("%c",plaintext[i][j]);
           }
        printf("\n");
    }
}
