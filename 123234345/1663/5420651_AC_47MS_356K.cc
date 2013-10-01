#include<stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
       int x,y;
       scanf("%d%d",&x,&y);
       if(y==x)
       {
           if(x%2) printf("%d\n",2*x-1);
           else printf("%d\n",2*x);
       }
       else if(y==x-2)
       {
           if(x%2) printf("%d\n",2*x-3);
           else printf("%d\n",2*x-2); 
       }
       else printf("No Number\n");
   }   
}
