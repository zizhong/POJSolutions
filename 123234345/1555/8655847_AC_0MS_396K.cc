#include<stdio.h>
int c[8];
void disx(int i)
{
     if(i>1) printf("x^%d",i);
     else if(i==1) printf("x");
}
int main()
{
    while(scanf("%d",&c[0])==1)
    {
         for(int i=1;i<9;i++)
              scanf("%d",&c[i]);
         int fir=-1;
         for(int i=0;i<8;i++) if(c[i])
         {
             if(fir==-1)
             {
                 fir=i;
                 if(c[i]!=1&&c[i]!=-1) printf("%d",c[i]);
                 else if(c[i]==-1) putchar('-'),c[i]=-c[i];
                 disx(8-i);
             }else
             {
                  if(c[i]>0) printf(" + ");
                  else printf(" - "),c[i]=-c[i];
                  if(c[i]!=1) printf("%d",c[i]);
                  disx(8-i);
             }
         }
         if(c[8]!=0)
         {
               if(fir==-1)
               {
                  fir=7;
                  printf("%d",c[8]);
               }
               else 
               {
                    if(c[8]>0) printf(" + ");
                    else printf(" - "),c[8]=-c[8];
                    printf("%d",c[8]);
               }
         }    
         if(fir==-1) putchar('0');
         puts("");
    }
}
