#include<stdio.h>
int main()
{
    double e=0,k=1;
    int i;
    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
    for(i=0;i<10;i++)
    {
       if(i)  k*=i;
       e+=1/k;
      if(i>=3)
       printf("%d %.9lf\n",i,e);
    }
}
