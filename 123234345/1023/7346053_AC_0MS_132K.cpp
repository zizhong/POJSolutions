#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         char s[65];
         scanf("%d%s",&n,s);
         __int64 k;
         scanf("%I64d",&k);
         for(int i=n-1;i>=0;i--,k>>=1)
            if(k&1)
            {
                if(s[i]=='n') k++;
                s[i]='1';
            }
            else s[i]='0';
         s[n]=0;
         puts(k?"Impossible":s);
    }
}
