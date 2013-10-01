#include<stdio.h>
int main()
{
    int T=0,p,i,d,e;
    while(scanf("%d%d%d%d",&p,&e,&i,&d),p+1)
    {
          int k=d+1;
          while((k-p)%23||(k-e)%28||(k-i)%33) k++;
          printf("Case %d: the next triple peak occurs in %d days.\n",++T,k-d);
    }
}
