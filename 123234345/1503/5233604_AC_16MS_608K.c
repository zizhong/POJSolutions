#include<stdio.h>
int sum[200];
int main()
{
    char a[200]={0};
    int i,f=0;
    while(scanf("%s",a)&&strcmp(a,"0"))
    {
        int c=0,n,j;
        for(i=0;a[i]=='0';)
        {
            for(j=i;j<strlen(a);j++)
                a[j]=a[j+1];
        }
        
        n=strlen(a);  
        strrev(a);
        for(i=0;i<n;i++)
        {
           sum[i]+=(a[i]-'0')+c;
           c=sum[i]/10;
           sum[i]%=10;
        }
        sum[i]+=c;
        while(sum[i]>9)
        {
           sum[i+1]+=sum[i]/10;
           sum[i]%=10;
           i++;
        }        
    }
    i=199;
    while(!sum[i]) i--;
    for(;i>=0;i--)
      printf("%d",sum[i]);
    printf("\n");
}
