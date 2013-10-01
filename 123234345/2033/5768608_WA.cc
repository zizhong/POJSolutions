#include<stdio.h>
#include<string.h>
char s[100000];
int f[100000];
int main()
{
    
    while(gets(s),s[0]!='0')
    {
        int n=strlen(s);
        f[0]=1;
        if((s[0]-'0')*10+(s[1]-'0')<=26) f[1]=2;
        else f[1]=1;
        for(int i=2;i<n;i++)
        {
             f[i]=f[i-1];
             if((s[i-1]-'0')*10+(s[i]-'0')<=26) f[i]+=f[i-2];
        }
        printf("%d\n",f[n-1]);
    }
}
