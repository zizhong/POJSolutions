#include<stdio.h>
main()
{
    int a[1000],b[1000];
    int f[1000]={0},n,i,k,j,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }  
    f[0]=1;  
    for(i=1;i<n;i++)
    {
       f[i]=1;
       for(j=0;j<i;j++)
       {
        if(a[i]>a[j] && f[i]<=f[j])
           f[i]=f[j]+1;                                    
       }                                        
    } 
    max=0;
    for(j=0;j<n;j++)
      {
          if(max<f[j]) max=f[j];          
      }
    printf("%d\n",max);  
}
