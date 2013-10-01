#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char alphabeta[16];
int cntbit(int x)
{
    int t=0;
    while(x) t+=(x&1),x>>=1;
    return t;
}
bool vowel[128];
int main()
{
    vowel['a']=vowel['o']=vowel['e']=vowel['i']=vowel['u']=true;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
          char s[2];
          scanf("%s",s);
          alphabeta[i]=s[0];
    }
    sort(alphabeta,alphabeta+m);
    for(int k=0;k<(1<<m);k++) if(cntbit(k)==n)
    {
         int cnt=0;   
         for(int i=0;i<m;i++) 
             if((k&(1<<i)) &&vowel[alphabeta[i]])
                 cnt++;
         if(cnt>=1 && n-cnt>=2)
         {
              for(int i=0;i<m;i++) if(k&(1<<i))
                   putchar(alphabeta[i]);
              puts("");
         }
    }
    scanf("%'d");
}
