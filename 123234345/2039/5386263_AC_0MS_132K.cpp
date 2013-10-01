#include<stdio.h>
#include<string.h>
int main()
{
    int c;
    while(scanf("%d",&c)&&c)
    {
        char s[201],m[100][20];
        scanf("%s",s);
        int len=strlen(s);
        int i,j,n=len/c;
        for(i=0;i<n;i++)
        {
            if(i%2==0)
               for(j=0;j<c;j++)
                  m[i][j]=s[i*c+j];
            else
               for(j=c-1;j>=0;j--)
                  m[i][j]=s[i*c+(c-j)-1];
        }
        /*for(i=0;i<4;i++)
        {
           for(j=0;j<4;j++)
            printf("%c",m[i][j]);
           printf("\n");
        }*/
        for(i=0;i<c;i++)
           for(j=0;j<n;j++)
           printf("%c",m[j][i]);
        printf("\n");        
    }
}
