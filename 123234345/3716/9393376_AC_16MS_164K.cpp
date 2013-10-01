#include<cstdio>
#include<cstring>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         printf("%.3f\n",(a+b+10)/7.0);
    }
}
