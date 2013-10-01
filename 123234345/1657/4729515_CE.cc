#include<stdio.h>
#include<math.h>
void main()
{
   int nCase,i;
   scanf("%d",&nCase);
   for(i=0;i<nCase;i++)
   {
     char begin[5],end[5];
     scanf("%s %s",begin,end);
     int x,y;
     x=abs(begin[0]-end[0]);
     y=abs(begin[1]-end[1]);
     if(x==0&&y==0)
     printf("0 0 0 0\n");
     else
     {
        if(x<y) printf("%d",y);
        else printf("%d",x);
        if(x==0||y==0||x==y)  printf(" 1");
        else printf(" 2");
        if(x==0||y==0) printf(" 1");
        else printf(" 2");
        if(abs(x-y)!=0) printf(" Inf\n");
        else if(x==y) printf(" 1\n");
        else printf(" 2\n");
     }
   }
}
