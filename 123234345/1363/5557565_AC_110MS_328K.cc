#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
         int stack[1000]={0};
         int i,j,k;
         while(scanf("%d",&stack[0]))
         {
         if(!stack[0]) 
         {
             printf("\n");
             break;
         }
         for(i=1;i<n;i++)
         {
             scanf("%d",&stack[i]);
         }
         int flag=1;
         for(i=0;i<n;i++)
         {
             int min=999999;
             for(j=i+1;j<n;j++)
             {
                 if(stack[j]<stack[i])
                 {
                      if(stack[j]>min)
                      {
                          flag=0;
                          break;
                      }
                      else min=stack[j];
                 }
             }
             if(flag==0) break;
         }
         if(flag) printf("Yes\n");
         else printf("No\n");  
         }       
    }
}
