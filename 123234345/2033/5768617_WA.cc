#include<stdio.h>
#include<string.h>
char s[100000]={'*'};
int f[100000];
int main()
{
    
    while(scanf("%s",s+1),s[1]!='0')
    {
        int n=strlen(s);
        f[0]=0,f[1]=1;
        for(int i=2;i<n;i++)
        {
             if(s[i]=='0')
             {
                  f[i]=f[i-2];
                  if(f[i]==0) f[i]=1;
                  continue;
             }
             f[i]=f[i-1];
             if((s[i-1]-'0')*10+(s[i]-'0')<=26&&s[i-1]!='0') f[i]+=f[i-2];
        }
        printf("%d\n",f[n-1]);
    }
}
