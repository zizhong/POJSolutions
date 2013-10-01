#include<stdio.h>
const int MX=147031;
int f[150000];
int snow[150000][6];
int same(int *a,int *b)
{
    int i=0;
    for(;i<6;++i) if(*(a+i)!=*(b+i)) break;
    return i==6;
}
int a[6];
void ind()
{
     int b[6],c[6];
     int min=10000001,mi=-1;
     for(int i=0;i<6;i++)
     {
         scanf("%d",&a[i]);
         if(min>a[i]) min=a[i],mi=i;         
     }
     for(int i=0;i<6;i++)
     {
          b[i]=a[(mi+i)%6];
          c[i]=a[(mi-i+6)%6];
     }
     int cmp=0;
     for(int i=0;i<6;i++)
         if(b[i]!=c[i])
         {
             if(b[i]<c[i])
                 cmp=1;
             break;
         }
     for(int i=0;i<6;i++) a[i]=cmp?b[i]:c[i];
}
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         ind();
         
         int key=0;
         for(int j=0;j<6;j++)
             key=(key*13+a[j])%MX;
         //printf("key=%d\n",key);
         while(f[key])
         {
              if(same(snow[key],a))
              {
                   puts("Twin snowflakes found.");
                   return 0;
              }
              key=(key+1)%MX;
         }
         for(int i=0;i<6;i++) snow[key][i]=a[i];
         f[key]=1;
    }
    puts("No two snowflakes are alike.");
    //scanf("%d",&n);
}
