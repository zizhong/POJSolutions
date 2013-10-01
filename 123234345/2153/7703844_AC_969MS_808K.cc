#include<stdio.h>
#include<string.h>
const int N=10001,M=14993;
int h[M];
char s[N][31];
int sc[M];
void hashin(int x)
{
     int key=1;
     for(int i=0;s[x][i];i++)
         key=(key*s[x][i])%M;
     while(h[key]) key=(key+1)%M;
     h[key]=x;
}
int hashfind(char name[])
{
    int key=1;
    for(int i=0;name[i];i++)
        key=(key*name[i])%M;
    while(h[key]&&strcmp(s[h[key]],name)) key=(key+1)%M;
    return key;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        gets(s[i]);
        hashin(i);
    }
    int m,g;
    char name[31];
    scanf("%d",&m);
    getchar();
    int idx=hashfind("Li Ming");
    while(m--)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d ",&g);
            gets(name);
            sc[hashfind(name)]+=g;
        }
        int ans=1;
        for(int i=1;i<M;i++)
             if(sc[i]>sc[idx]) ans++;
        printf("%d\n",ans);
    }
    scanf("%'d");
}
