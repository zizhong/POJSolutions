#include<stdio.h>
#include<string.h>
char s[80];
char c[80][2];
int main()
{
    while(scanf("%s",s)&&s[0]!='*')
    {
        int n=strlen(s),d,i,j,k;
        int flag=1;
        for(d=0;d<n-1;d++)
        {
           memset(c,0,sizeof(c));
           for(i=0;i<n-d-1;i++)
               c[i][0]=s[i],c[i][1]=s[i+d+1];
           for(i=0;i<n-d-2;i++)
              for(j=i+1;j<n+d-1;j++)
                 if(c[i][0]==c[j][0]&&c[i][1]==c[j][1])
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
    getchar();getchar();getchar();
}
