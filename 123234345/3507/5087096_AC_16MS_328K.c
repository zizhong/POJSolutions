#include<stdio.h>
main()
{
   while(1)
  { 
        int num[6]={0},i,sum=0,max=0,min=9999999;
        for(i=0;i<6;i++)
        {    
             scanf("%d",&num[i]);
             sum+=num[i];
             if(num[i]<min) min=num[i];
             if(num[i]>max) max=num[i];
        }
        if(!sum) break;
        printf("%g\n",(sum-min-max)/4.0);   
  }
}
