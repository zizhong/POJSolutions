#include<stdio.h>
#include<string.h>
int num[301];
bool flag[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int g,m;
        scanf("%d",&g);
        for(int i=0;i<g;i++)
            scanf("%d",&num[i]);
        for(m=g;;m++)
        {
            int f=1;
            memset(flag,false,sizeof(bool)*m);
            for(int j=0;j<g;j++)
            {
                 int a=num[j]%m;
                 if(flag[a])
                 {
                     f=0;
                     break;
                 }
                 else flag[a]=true;
            }
            if(f) break;
        }
        printf("%d\n",m);
    }
}
