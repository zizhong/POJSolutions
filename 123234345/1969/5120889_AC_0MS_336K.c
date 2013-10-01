#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,a,b,m;
        for(i=1;i*(i+1)/2.0<n;i++);
        a=i,b=1;
        m=n-(i-1)*i/2.0-1;
        while(m--)  a--,b++;
        if(i%2) printf("TERM %d IS %d/%d\n",n,a,b);
        else printf("TERM %d IS %d/%d\n",n,b,a);
    }
}
