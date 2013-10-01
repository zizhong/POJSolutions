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
        if(s[2]=='0') f[2]=1;
        else if((s[1]-'0')*10+(s[2]-'0')<=26) f[2]=2;
        if(!f[2]) f[2]=1;
        for(int i=3;i<n;i++)
        {
             if(s[i]=='0')
             {
                  f[i]=f[i-2];
                  continue;
             }
             f[i]=f[i-1];
             if((s[i-1]-'0')*10+(s[i]-'0')<=26&&s[i-1]!='0') f[i]+=f[i-2];
        }
        //for(int i=1;i<n;i++) printf("f[%d]=%d\n",i,f[i]);
        printf("%d\n",f[n-1]);
    }
}
