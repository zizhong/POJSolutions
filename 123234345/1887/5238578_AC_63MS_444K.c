#include<stdio.h>
int a[5000];
int main()
{
    int n,i=0,l=0,t=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
        {
            int max=0,f[5000]={0},j;
            if(l==0) return 0;
            for(i=1;i<l;i++)
               for(j=0;j<i;j++)
                 if(a[j]>=a[i]&&f[j]>=f[i])
                     f[i]=f[j]+1;
            for(i=0;i<l;i++)
               if(max<=f[i]) max=f[i];
            printf("Test #%d:\n  maximum possible interceptions: %d\n\n",t,max+1);             
            l=0,i=0,t++;
        }
        else{
        a[i++]=n;
        l++;
       }
    }
}
