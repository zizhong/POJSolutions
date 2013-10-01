#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int i,j,k,n,min=9999999;
    scanf("%d",&n);
    for(i=1;i<=10;i++)
       for(j=i;j<=32;j++)
          for(k=j;k<=1000;k++)
              if(i*k*j==n&&min>2*(i*j+i*k+k*j))
                  min=2*(i*j+i*k+k*j);
    printf("%d\n",min);
    }
}
