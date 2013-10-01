#include<stdio.h>
int a[10001];
main()
{
    int i=1,j;
    for(i=1;i<10000;i++)
    {
       if(a[i]==0) printf("%d\n",i);
       j=i;
       while(j<10000)
       {
          a[j]=1;
          j+=j/1000%10+j/100%10+j/10%10+j%10;
       }
    }
}
