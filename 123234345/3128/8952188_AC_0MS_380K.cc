#include<cstdio>
#include<cstring>
const int N=32;
char s[N];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
          scanf("%s",s);
          int v[32]={0},num[32]={0};
          for(int i=0;i<26;i++) if(v[i]==0)
          {
                int l=0,p=i;
                while(v[p]==0) v[p]=1,++l,p=s[p]-'A';
                num[l]++;
          }
          int flag=1;
          for(int i=2;i<26;i+=2) if(num[i]%2) flag=0;
          puts(flag?"Yes":"No");
    }    
}
