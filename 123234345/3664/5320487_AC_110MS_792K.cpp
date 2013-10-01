#include<stdio.h>
#include<stdlib.h>
struct Cow
{
    int no,
        a,
        b;
}cow[50001];
int cmp(const void *a,const void *b)
{
    Cow *c=(Cow *)(a);
    Cow *d=(Cow*)(b);
    return d->a - c->a;
}
int main()
{
    int n,k;
    int i=1;
    scanf("%d%d",&n,&k); 
    for(i=0;i<n;i++)
    {
       scanf("%d%d",&cow[i].a,&cow[i].b);
       cow[i].no=i+1;
    }
    qsort(cow,n,sizeof(cow[0]),cmp);
    int max=0,mi=-1;
    for(i=0;i<k;i++)
    {
        if(cow[i].b>max)
        {
           max=cow[i].b;
           mi=cow[i].no;
        }
    }
    printf("%d\n",mi);
}
