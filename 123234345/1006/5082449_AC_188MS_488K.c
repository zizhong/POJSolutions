#include<stdio.h>
#define N 30000
unsigned short a[3][N];
int main()
{
    int p,e,i,r;
    int t=0;
    while(1)
    {  t++;
       int j=0;
       scanf("%d%d%d%d",&p,&e,&i,&r);
       if(p==-1&&e==-1&&i==-1) break;
       memset(a,0,sizeof(a));
       for(j=p%23;j<N;j+=23)
          a[0][j]=1;
       for(j=e%28;j<N;j+=28)
          a[1][j]=1;
       for(j=i%33;j<N;j+=33)
          a[2][j]=1;
       for(j=r+1;;j++)
       {
          if(a[0][j]==1&&a[1][j]==1&&a[2][j]==1)
             break;
       }
       printf("Case %d: the next triple peak occurs in %d days.\n",t,j-r);
    }
}
