#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define i64 __int64
i64 fac[21];
int main()
{
    fac[0]=1;
    for(int i=1;i<=20;i++)
       fac[i]=i*fac[i-1];
    int T;
    scanf("%d",&T);
    while(T--)
    {
         char s[24];
         scanf("%s",s);
         i64 ans=0;
         int len=strlen(s);
         for(int i=0;s[i];i++)
         {
              char left[24];
              memcpy(left,s+i,(len-i)*sizeof(char));
              left[len-i]=0;
              sort(left,left+len-i);
              int cnt[26]={0};
              for(int j=0;left[j];j++)
                  cnt[left[j]-'A']++;
              for(int j=0;left[j]!=s[i];j++) if(left[j]!=left[j+1])
              {
                   cnt[left[j]-'A']--;
                   long long tmp=fac[len-i-1];
                   for(int k=0;k<26;k++)
                      tmp/=fac[cnt[k]];
                   ans+=tmp;
                   cnt[left[j]-'A']++;
              }
         }
         printf("%I64d\n",ans);
    }
}
