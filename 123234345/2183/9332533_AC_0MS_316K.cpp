#include<cstdio>
#include<cstring>
short e[1000000];
int main()
{
    int x;
    scanf("%d",&x);
    int c=0;
    while(1)
    {
            x=x%100000/10;
            x=x*x;
            x%=1000000;
            c++;
            if(e[x])
            {
               printf("%d %d %d\n",x,c-e[x],c);
               break;
            }
            e[x]=c;
    }
    scanf("%'d");
}
