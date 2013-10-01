#include<stdio.h>
#include<string.h>
const int N=500;
int num[251][500];
void intRev(int a[])
{
     for(int i=1;i<=a[0]/2;i++)
     {
          int t=a[i];
          a[i]=a[a[0]-i+1];
          a[a[0]-i+1]=t;
     }
}
void intCpy(int a[],int b[])
{
     for(int i=0;i<=b[0];i++) a[i]=b[i];
}
void dis(int a[])
{
     int n=a[0];
     for(int i=1;i<=n;i++) printf("%d",a[i]);
     printf("\n");
}
void bigPuls(int a[],int b[],int c[])
{
     memset(c,0,sizeof(int)*N);
     c[0]=a[0]>b[0]?a[0]:b[0];
     intRev(a);
     if(a!=b) intRev(b);
     for(int i=1;i<=c[0];i++)
     {
             if(i>a[0]) a[i]=0;
             if(i>b[0]) b[i]=0;
             c[i]+=a[i]+b[i];
             c[i+1]=c[i]/10;
             c[i]%=10;
     }
     if(c[c[0]+1]) c[0]++;
     intRev(c);
}
void table()
{
     int a[N],b[N],c[N];
     num[0][0]=num[0][1]=num[1][0]=num[1][1]=1;
     for(int i=2;i<=250;i++)
     {
             intCpy(a,num[i-2]),intCpy(b,num[i-1]);
             bigPuls(a,a,c);
             intCpy(a,c);
             bigPuls(a,b,c);
             intCpy(num[i],c);
     }
}
int main()
{
    table();
    int n;
    while(scanf("%d",&n)!=EOF)   dis(num[n]);
}
