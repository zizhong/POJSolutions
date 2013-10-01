#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
         int s[1000]={1},num[10]={0};
         int i,c=0,j,len=1;
         for(i=2;i<=n;i++)
         {
             for(j=0;j<len;j++)
             {
                 s[j]=s[j]*i+c;
                 c=s[j]/10;
                 s[j]%=10;
             }
             while(c)
             {
                 s[len++]=c%10;
                 c/=10;
             }
         }
         while(!s[len-1]) len--;
         for(j=0;j<len;j++)
         {
            num[s[j]]++;
         }
         printf("%d! --\n",n);
         /*for(i=0;i<=9;i++)
         {
            if(i==5) printf("\n");
            printf("   (%d)%5d",i,num[i]);            
         }
         printf("\n");*/
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",num[0],num[1],num[2],num[3],num[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",num[5],num[6],num[7],num[8],num[9]);
    }
}
