#include<stdio.h>
int tab[1001];
int phi(int n)
{
    int ret=1,i;
    for(i=2;i*i<=n;i++)
       if(n%i==0)
       {
           n/=i;
           ret*=i-1;
           while(n%i==0)
           {
               n/=i;
               ret*=i;
           }
       }
    if(n>1) ret*=n-1;
    return ret;
} 
void table()
{
     int i;
     tab[1]=3;
     for(i=2;i<1001;i++)
        tab[i]=tab[i-1]+phi(i)*2;//思路很强悍~ 
}
int main()
{
    int ncase,t;
    table();
    scanf("%d",&ncase);
    t=ncase;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d %d %d\n",ncase-t,n,tab[n]);
    }
}
