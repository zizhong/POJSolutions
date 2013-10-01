#include<stdio.h>
#include<string.h>
const int N=30001;
int a[N],b[N],c[N];
int res,n,maxs1=-1,maxs2=-1;
int len1,len2;
int bi(int n)
{
    int left=0,right=len1,mid=(left+right)/2;
    while(left<=right)
    {
        if(n>=c[mid]) left=mid+1;
        else right=mid-1;
        mid=(left+right)/2;
    }
    return left;
}
int bd(int n)
{
    int left=0,right=len2,mid=(left+right)/2;
    while(left<=right)
    {
        if(n>c[mid]) left=mid+1;
        else right=mid-1;
        mid=(left+right)/2;
    }
    return left;
}
void LIS()
{
     int loc;
     for(int i=1;i<n;i++)
     {
         loc=bi(a[i]);
         c[loc]=a[i];
         if(loc>len1) len1=loc;
     }
}
void LDS()
{
     int loc;
     for(int i=1;i<n;i++)
     {
         loc=bd(a[i]);
         c[loc]=a[i];
         if(loc>len2) len2=loc;
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    b[0]=1,c[0]=-1,c[1]=a[0],len1=1;
    LIS();
    memset(b,0,sizeof(b)),memset(c,0,sizeof(c));
    c[0]=9999999,c[1]=a[0],b[0]=1,len2=1;
    LDS();
    printf("%d\n",n-(len1>len2?len1:len2));
}
