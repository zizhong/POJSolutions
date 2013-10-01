#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)&&(a+b+c+d))
    {
        int imgl=max(a,b),
            imgw=a+b-imgl,
            papl=max(c,d),
            papw=c+d-papl;
        int r=0;
        if((1.0*papl/imgl)<(1.0*papw/imgw)) r=int(100.0*papl/imgl);
        else r=int(100.0*papw/imgw);
        if(r>100) r=100;
        printf("%d%%\n",r);
    }
}
