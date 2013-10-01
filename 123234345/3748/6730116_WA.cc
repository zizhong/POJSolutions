#include<stdio.h>
char f[]="0123456789abcdef";
int main()
{
    char c;
    int x=0,y=0,ans;
    int a[9]={0},n=0;
    int b[33]={0};
    while((c=getchar())!=',')
        a[n++]=c;
    while((c=getchar())>='0'&&c<='9')
        x=x*10+(c-'0');
    while((c=getchar())>='0'&&c<='9')
        y=y*10+(c-'0');
    int f2[128]={0};
    for(int i=0;f[i];i++)
         f2[f[i]]=i;
    for(int i=0;i<n;i++)
    {
         int t=f2[a[i]];
         b[i*4+0]=((t>>3)&1);
         b[i*4+1]=((t>>2)&1);
         b[i*4+2]=((t>>1)&1);
         b[i*4+3]=((t>>0)&1);
    }
    b[4*n-1-x]=0;
    b[4*n-1-y]=1;
    b[4*n-y]=1;
    b[4*n+1-y]=0;
    int flag=1;
    for(int i=0;i<n;i++)
    {
          int t=b[i*4+0]*8+b[i*4+1]*4+b[i*4+2]*2+b[i*4+3]*1;
          if(t==0)
          {
                  if(flag) continue;
          }
          putchar(f[t]);
          flag=0;
    }
    
    if(flag) putchar('0');
    puts("");
}
