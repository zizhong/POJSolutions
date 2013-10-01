#include<stdio.h>
int main()
{
    int n;
    int t=0,i;
    while(scanf("%d",&n)&&n)
    {
       char a[20][30];
       for(i=1;i<=n;i++)
       {
          scanf("%s",a[i]);
       }
       ++t;
       printf("SET %d\n",t);
       for(i=1;i<=n;i++)
       {
          int num;
          if(n%2)
          {
              if(i<=n/2+1) num=2*i-1;
              else num=(n-1)-(i-(n/2)-2)*2;
          }
          else
          {
              if(i<=n/2) num=2*i-1;
              else num=n-(i-n/2-1)*2;
          }
          printf("%s\n",a[num]);
       }
    }
    
}
