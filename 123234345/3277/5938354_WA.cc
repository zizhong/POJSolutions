#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Line
{
       int x,h,mk;
};
Line city[40000*2];
int cmp(const void *a,const void *b)
{
    Line *p1=(Line *)a;
    Line *p2=(Line *)b;
    return (Line *)p1->x - (Line *)p2->x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d%d%d",&city[i*2].x,&city[i*2+1].x,&city[i*2].h);
         city[i*2+1].h=city[i*2].h;
         city[i*2].mk=1;
         city[i*2+1].mk=-1;
    }
    n*=2;
    qsort(city,n,sizeof(city[0]),cmp);
    int f=0,ans=0;
    for(int i=0;i<n-1;i++)
    {
        f+=city[i].mk;
        if(f>0)
        {
             int a=city[i].h>city[i+1].h?city[i].h:city[i+1].h;
             ans+=a*(city[i+1].x-city[i].x);
        }
    }
    printf("%d\n",ans);
    //scanf("%d",&n);
}
