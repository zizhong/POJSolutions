#include<stdio.h>
int main()
{
    int n;
    char a[100],b[100];
    scanf("%d",&n);
    while(n--)
    {
        int i,j,c=0,sum[100]={0},la,lb;        
        scanf("%s%s",a,b);
        la=strlen(a),lb=strlen(b);
        for(i=0;i<la||i<lb;i++)
        {
            if(i>=la) a[i]='0';
            if(i>=lb) b[i]='0';
            sum[i]+=a[i]+b[i]-2*'0'+c;
            c=sum[i]/10;
            sum[i]%=10;
        }
        sum[i]+=c;
        i=99;
        while(!sum[i]) i--;
        j=0;
        while(!sum[j]) j++;
        for(;j<=i;j++)
            printf("%d",sum[j]);
        printf("\n");
    }
}
