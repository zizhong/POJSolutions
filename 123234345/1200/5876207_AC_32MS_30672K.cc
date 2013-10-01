#include<stdio.h>
#include<string.h>
#define MX 159770003
int m,nc,ans,k;
int num[256];
char s[160000000];
int f[160000000];
void rk()
{
    int n=strlen(s);
    if(m>n) return ;
    
    int h=1,i=0;
    while(i<m-1) h=(h*nc)%MX,++i;
    int p=0;
    for(i=0;i<m;i++)
    {
        if(num[s[i]]==0) num[s[i]]=++k;
        p=(p*nc+num[s[i]])%MX;
    }
    f[p]=ans=1;
    for(i=0;i<n-m;i++)
    {
         if(num[s[i+m]]==0) num[s[i+m]]=++k;
         p=((p-num[s[i]]*h)*nc+num[s[i+m]])%MX;
         if(f[p]==0) f[p]=1,ans++;
    }
}
int main()
{
    scanf("%d%d",&m,&nc);
    gets(s);
    gets(s);
    rk();
    printf("%d\n",ans);
    //scanf("%d",&ans);
}
