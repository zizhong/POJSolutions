#include<stdio.h>
const int N=51;
int cal[26];
void add(char s[],int x)
{
     for(int i=0;s[i];i++)
        cal[s[i]-'a']+=x;
}
int main()
{
    int T;
    char s[N];
    scanf("%d",&T);
    gets(s);
    for(int t=1;t<=T;t++)
    {
         gets(s);
         add(s,1);
         gets(s);
         add(s,-1);
         int ans=0;
         for(int i=0;i<26;i++)
         {
            ans+=cal[i]>0?cal[i]:-cal[i];
            cal[i]=0;
         }
         printf("Case #%d:  %d\n",t,ans);
    }
}
