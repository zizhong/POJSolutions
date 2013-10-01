#include<stdio.h>
int d[]={1,10,100,1000,10000,100000,1000000};
int main()
{
    int n;
    char s[6];
    while(scanf("%s",&s))
    {
         n=d[s[3]-'0']*((s[0]-'0')*10+s[1]-'0');
         if(n==0) break;
         int i=1,j;
         int x=n;
         while(x>i) x-=i,i+=i;
         
         printf("%d\n",2*x-1); 
    }
}
