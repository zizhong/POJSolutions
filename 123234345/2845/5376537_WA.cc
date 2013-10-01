#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char s[2][100];
        memset(s,0,sizeof(s));
        scanf("%s%s",s[0],s[1]);
        int n1=strlen(s[0]),n2=strlen(s[1]);
        int num[100]={0};
        int temp=0;
        int j;
        for(j=0;j<n1||j<n2;j++)
        {
            char c1='0',c2='0';
            if(j<n1) c1=s[0][n1-1-j];
            if(j<n2) c2=s[1][n2-1-j];
            num[j]=c1+c2-'0'*2+temp;
            //printf("%d %d  %d\n",c1,c2,num[j]);
            temp=num[j]/2;
            num[j]%=2;
        }
        num[j]=temp;
        j=100;
        while(!num[--j]);
        printf("%d ",i);
        for(;j>=0;j--)
            printf("%d",num[j]);
        printf("\n");
    }
}
