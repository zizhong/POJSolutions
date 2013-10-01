#include<stdio.h>
#include<string.h>
int p[10001];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(p,0,sizeof(p));
        int k=n*m,a,max=0,mi;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&a);
            p[a]++;
            if(p[a]>max) max=p[a],mi=a;
        }
        p[mi]=0;
        max=0;
        for(int i=0;i<10001;i++)
            if(p[i]>max) max=p[i];
        int first=1;
        for(int i=1;i<=10000;i++)
        {
            if(p[i]==max)
            {
                if(!first) printf(" ");
                first=0;
                printf("%d",i);
            }
        }
        printf("\n");
    }
}
