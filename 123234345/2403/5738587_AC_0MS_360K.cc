#include<stdio.h>
#include<string.h>
struct Dic
{
       char s[20];
       int n;
}d[1000];
int main()
{
    int m,t;
    scanf("%d%d",&m,&t);
    for(int i=0;i<m;i++)
       scanf("%s%d",d[i].s,&d[i].n);
    while(t--)
    {
        int sum=0;
        char str[20];
        while(scanf("%s",str),str[0]!='.')
        {
             for(int i=0;i<m;i++)
                if(strcmp(str,d[i].s)==0) sum+=d[i].n;
        }
        printf("%d\n",sum);
    }
}
