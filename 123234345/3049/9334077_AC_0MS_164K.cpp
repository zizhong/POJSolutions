#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
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
char str[1<<15][16];
int cc;
int cmp(const void *p1,const void* p2)
{
     char * s1 = (char *)p1;
     char * s2 = (char *)p2;
     return strcmp(s1,s2);
}
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
              int j=0;
              for(int i=0;i<m;i++) if(k&(1<<i))
                   str[cc][j++]=alphabeta[i];
              str[cc++][j]=0;                   
         }
    }
    qsort(str,cc,sizeof(str[0]),cmp);
    for(int i=0;i<cc;i++) puts(str[i]);
    //scanf("%'d");
}
