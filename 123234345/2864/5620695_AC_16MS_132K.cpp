#include<stdio.h>
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d),n||d)
    {
        int p[101]={0};
        for(int i=0;i<d;i++)
        {
             for(int j=0;j<n;j++)
             {
                 int t;
                 scanf("%d",&t);
                 p[j]+=t;
             }
        }
        int i;
        for(i=0;i<n;i++)
           if(p[i]==d) break;
        if(i<n) printf("yes\n");
        else printf("no\n");
    }    
}
