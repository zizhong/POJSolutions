#include<stdio.h>
#include<stdlib.h>
int a[6];
const int TM=4000037;
int xcb[110],ans1[TM],f[TM];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int hin(int val)
{
    int pos=(val%TM+TM)%TM;
    while(f[pos]&&ans1[pos]!=val)
        pos=(pos+1)%TM;
    f[pos]++,ans1[pos]=val;
}
int hs(int val)
{
    int pos=(val%TM+TM)%TM;
    while(f[pos]&&ans1[pos]!=val)
        pos=(pos+1)%TM;
    return f[pos];
}
int main()
{
    int res=0,i,x1,x2,x3,x4,x5;
    for(i=-50;i<=50;i++)
       if(i) xcb[i+50]=i*i*i;
    for(i=1;i<=5;i++) scanf("%d",&a[i]);
    for(x1=-50;x1<=50;x1++)
        if(x1)
        for(x2=-50;x2<=50;x2++)
            if(x2)
                  hin(a[1]*xcb[x1+50]+a[2]*xcb[x2+50]);
    for(x3=-50;x3<=50;x3++)
       if(x3)
       for(x4=-50;x4<=50;x4++)
          if(x4)
          for(x5=-50;x5<=50;x5++)
             if(x5)
             {
                   int val=a[3]*xcb[x3+50]+a[4]*xcb[x4+50]+a[5]*xcb[x5+50];
                   res+=hs(-val);
             }
    printf("%d\n",res);
    //system("pause");
}
