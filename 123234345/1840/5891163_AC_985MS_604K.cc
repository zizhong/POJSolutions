#include<stdio.h>
#include<stdlib.h>
int a[6];
int xcb[110],ans1[10001],N;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int bs(int val)
{
    int left=0,right=N-1,mid=(left+right)>>1,cnt=0;
    while(left<=right)
    {
         if(ans1[mid]<val) left=mid+1,mid=(left+right)>>1;
         else if(ans1[mid]>val) right=mid-1,mid=(left+right)>>1;
         else
         {
             int l=mid-1,r=mid+1;
             cnt++;
             while(l>=0&&ans1[l--]==val) cnt++;
             while(r<N&&ans1[r++]==val) cnt++;
             return cnt;
         }
    }
    return 0;
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
                  ans1[N++]=a[1]*xcb[x1+50]+a[2]*xcb[x2+50];  
    qsort(ans1,N,sizeof(int),cmp);
    for(x3=-50;x3<=50;x3++)
       if(x3)
       for(x4=-50;x4<=50;x4++)
          if(x4)
          for(x5=-50;x5<=50;x5++)
             if(x5)
             {
                   int val=a[3]*xcb[x3+50]+a[4]*xcb[x4+50]+a[5]*xcb[x5+50];
                   res+=bs(-val);
             }
    printf("%d\n",res);}
