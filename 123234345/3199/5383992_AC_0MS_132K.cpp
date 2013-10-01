#include<stdio.h>
#include<string.h>
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)&&(n||d))
    {
        int c=0;
        int num[50]={1};
        int len=1,i,j;        
        for(i=0;i<d;i++)
        {
           for(j=0;j<len;j++)
           {
            num[j]=num[j]*n+c;
            c=num[j]/10;
            num[j]=num[j]%10;
           }
           while(c!=0)
           {
             num[len++]=c%10;
             c/=10;
           }
        }
        for(i=len-1;i>=0;i--)
        {
             printf("%d",num[i]);
        }
        printf("\n");
    }
}
