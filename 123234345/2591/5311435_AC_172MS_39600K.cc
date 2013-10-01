#include<stdio.h>
int a[10000001];
void maketable()
{
     a[1]=1;
     int mi=1,mj=1;
     int i=2;
     for(;i<10000001;i++)
     {
     if(2*a[mi]+1<3*a[mj]+1)
            a[i]=2*a[mi++]+1;
        else
            a[i]=3*a[mj++]+1;
        if(a[i]==a[i-1]) i--;
     }
}
int main()
{
    int n;
    maketable();
    while(scanf("%d",&n)!=EOF) printf("%d\n",a[n]);
}
