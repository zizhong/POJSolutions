#include<stdio.h>
#include<string.h>
char s[50001][51],num[101]={1};
int f[102],t[102];
int cn;
char map[]={"22233344115566070778889990"};
bool ok(int i,int j)
{
     for(int k=0;k<cn;k++)
           if(map[s[j][k]-'a']-num[i+k]) return false;
     return true;
}
int main()
{
        scanf("%s",num+1);
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) gets(s[i]);
    int len=strlen(num);
    len--;
    for(int i=0;i<=len;i++) f[i]=102;
    f[0]=0;
    for(int i=0;i<=len;i++)
       if(f[i]<102) for(int j=1;j<=n;j++)
          {
                cn=strlen(s[j]);
                if(i+cn<=len&&ok(i+1,j))
                {
                      if(f[i+cn]>f[i]+1)
                      {
                             f[i+cn]=f[i]+1;
                             t[i+cn]=j;
                      }
                }
          }
    if(f[len]==102) puts("No solution.");
    else
    {
        int stack[101],top=-1;
        for(int l=len,v=t[l];v;v=t[l])
        {
                cn=strlen(s[v]);
                stack[++top]=v;
                l-=cn;
        }
        while(top>-1)
        {
              printf("%s%c",s[stack[top--]],top?' ':'\n');              
        }
    }
}
