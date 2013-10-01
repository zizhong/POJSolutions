#include<stdio.h>
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int DinY(int y)
{
    if(y%400==0||(y%4==0&&y%100)) return 366;
    return 365;
}
char s[7][16]=
{
     "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" , "Saturday"
};
int main()
{
    int n;
    while(scanf("%d",&n),n!=-1)
    {
         int y=2000;
         int x=n;
         n++;
         while(1)
         {
              int num=DinY(y);
              if(num>=n) break;
              n-=num;
              y++; 
         }
         int m=1;
         while(1)
         {
              int num=mon[m];
              if(m==2&&DinY(y)==366) num++;
              if(num>=n) break;
              n-=num;
              m++;
         }
         int d=n;
         printf("%d-%02d-%02d %s\n",y,m,d,s[(6+x)%7]);
    }
}
