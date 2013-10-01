#include<stdio.h>
const int MAX=100000;
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int num[MAX]={0};
        int i=0;
        for(;i<n;i++)
            scanf("%d",&num[i]);
        int a[MAX]={0},b[MAX]={0};
        for(i=0;i<n;i++)
        {
           if(i) a[i]=a[i-1]+num[i];
           else a[i]=num[i];
           if(a[i]<0) a[i]=0; 
        }
        for(i=n-1;i>=0;i--)
        {
           if(i!=n-1) b[i]=b[i+1]+num[i];
           else b[i]=num[i];
           if(b[i]<0) b[i]=0;
        }
        for(i=0;i<n;i++)
           if(i&&a[i]<a[i-1]) a[i]=a[i-1];
        for(i=n-1;i>=0;i--)
           if(i!=n-1&&b[i]<b[i+1]) b[i]=b[i+1];
        int max=-999999999;
        for(i=0;i<n-1;i++)
           max=a[i]+b[i+1]>max?a[i]+b[i+1]:max;
        printf("%d\n",max);   
    }
}
