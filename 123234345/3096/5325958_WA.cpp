#include<stdio.h>
#include<string.h>
char s[80];
char c[2][80];
int main()
{
    while(scanf("%s",s)&&s[0]!='*')
    {
        int n=strlen(s),d,i,j,k;
        int flag=1;
        for(d=0;d<n-1;d++)
        {
           for(i=0;i<n-d-1;i++)
               c[0][i]=s[i],c[1][i]=s[i+d+1];
           for(i=0;i<n-d-2;i++)
              for(j=i+1;j<n+d-1;j++)
                 if(c[0][i]==c[0][j]&&c[1][i]==c[1][j])
                 {
                     flag=0;
                     goto END;
                 }
        }
        
        END: ;
        printf("%s is ",s);
        if(!flag) printf("NOT ");
        printf("surprising.\n");
    }
}
