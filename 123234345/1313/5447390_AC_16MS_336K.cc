#include<stdio.h>
#include<math.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)&&n)
    {
         int p=ceil(n*1.0/4)*2,a[64]={0},b[64]={0};
         for(int i=1;i<=p;i++)
             a[i]=i;
         for(int i=p+1;i<=n;i++)
             b[2*p-i+1]=i;
         printf("Printing order for %d pages:\n",n);
         if(n==1)
              printf("Sheet 1, front: Blank, 1\n");
         else
         for(int i=1;i<=p;i++)
         {
             printf("Sheet %d, ",(i+1)/2);
             if(i&1)
             {
                  printf("front:");
                  if(b[i]==0) printf(" Blank,");
                  else printf(" %d,",b[i]);
                  printf(" %d\n",a[i]);
             }
             else
             {
                 printf("back :");
                 printf(" %d,",a[i]);
                 if(b[i]==0) printf(" Blank\n");
                 else printf(" %d\n",b[i]);
             }
         }
    }
}
