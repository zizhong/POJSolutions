#include<stdio.h>
int c[41][41];
int fun(int n)
{
    int sum=1,x=n,y=1,len=0;
    while(x) x>>=1,len++;
    for(int i=2;i<len;i++)
       for(int j=0;j<i-1;j++)
          if((j+1)*2<=i) sum+=c[i-1][j];
          else break;
    for(int i=len-2;i>=0;i--) 
        if(n & 1<<i)
        {
             for(int j=0;j<=i;j++)
                     if((j+y)*2<=len) sum+=c[i][j];
                     else break;
             y++;
        }
    return sum;
}
int main()
{
    for(int i=0;i<40;i++)
    {
       c[i][0]=c[i][i]=1;
       for(int j=1;j<i;j++)
           c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int a,b;
    while(scanf("%d%d",&a,&b)==2) printf("%d\n",fun(b+1)-fun(a));
}
