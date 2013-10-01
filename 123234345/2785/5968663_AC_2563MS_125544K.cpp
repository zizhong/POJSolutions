#include<stdio.h>
#include<string.h>
const int N=4001,p=15999991;
int a[N][4];
int h[N*N],f[N*N];
void hash(int a)
{
     int key=(a%p+p)%p;
     while(f[key]>0&&h[key]!=a) key=(key+1)%p;
     h[key]=a;
     f[key]++;
}
int  find(int a)
{
     int key=(a%p+p)%p;
     while(f[key]>0&&h[key]!=a) key=(key+1)%p;
     return f[key];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            hash(a[i][0]+a[j][1]);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          ans+=find(-(a[i][2]+a[j][3]));
    printf("%d\n",ans);
    //scanf("%d",&n);
}
