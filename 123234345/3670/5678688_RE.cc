#include<stdio.h>
#include<string.h>
const int MAX=1000;
double h[MAX];
int up[MAX],down[MAX];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%lf",&h[i]);
        up[0]=1;
        for(int i=1;i<n;i++)
        {
            up[i]=1;
            for(int j=i-1;j>=0;--j)
               if(h[i]>h[j]&&up[j]+1>up[i])
                   up[i]=up[j]+1;
        }
        down[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
             down[i]=1;
             for(int j=i+1;j<n;j++)
                if(h[i]>h[j]&&down[j]+1>down[i])
                    down[i]=down[j]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
           for(int j=i+1;j<n;j++)
             if(ans<up[i]+down[j])
                ans=up[i]+down[j];
        printf("%d\n",n-ans);
    }
}