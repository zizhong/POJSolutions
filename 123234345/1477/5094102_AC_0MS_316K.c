#include<stdio.h>
main()
{
   int j=1;
   int n;
   while(scanf("%d",&n)&&n)
   {
      int a[51]={0};
      int i,sum=0,ave,r=0;
      for(i=0;i<n;i++)
       {  
       scanf("%d",&a[i]);
       sum+=a[i];
       }
      ave=sum/n;
      for(i=0;i<n;i++)
        if(ave<a[i]) r+=a[i]-ave;
      printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,r);
      j++;
   }
}
