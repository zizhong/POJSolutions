#include<stdio.h>
int main()
{
    int a,b,yushu[1200],r,i,j;
    int find;
    while(scanf("%d%d",&a,&b)&&a!=0&&b!=0)
   {
        yushu[0] = a;
        printf(".");
        i = 1;
        find = 0;
        while(1)
        {
            r = yushu[i-1]*10/b;
            yushu[i] = yushu[i-1]*10%b;
            printf("%d",r);
            if(yushu[i]==0)
            {
               find=2;
               break;
            }
           for(j=0;j<i;j++)
           {
              if(yushu[j]==yushu[i])
              {
                 find = 1;
                 break;
              }
          }

          if(find==1||find==2)break;
          if( (i==49)||((i>51)&&((i+1)%50==0)))  printf("\n");  
          i++;
        }
        if(find==1)
        printf("\nThe last %d digits repeat forever.\n",i-j);
        else   printf("\nThis expansion terminates.\n");
     }


 }
