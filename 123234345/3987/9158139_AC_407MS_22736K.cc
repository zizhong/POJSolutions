#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int CH=26,N=230000;
int chd[N][CH],sz,word[N],fail[N],Que[N],sw[128];
void insert(char *a,int x)
{
     int p=0;
     for(;*a;++a)
     {
          int c=sw[*a];
          if(!chd[p][c])
          {
               memset(chd[sz],0,sizeof(chd[sz]));
               word[sz]=0;
               chd[p][c]=sz++;
          }
          p=chd[p][c];
     }
     word[p]=x;
}
void AC()
{
     int *s=Que,*e=Que;
     for(int i=0;i<CH;i++) if(chd[0][i])
     {
         fail[chd[0][i]]=0;
         *e++=chd[0][i];
     }
     while(s!=e)
     {
         int p=*s++;
         for(int i=0;i<CH;i++) if(chd[p][i])
         {
             int v=chd[p][i];
             *e++=v;
             fail[v]=chd[fail[p]][i];
         }else chd[p][i]=chd[fail[p]][i];
     }
}
void init()
{
     memset(word,0,sizeof(word));
     memset(chd[0],0,sizeof(chd[0]));
     sz=1;
}
char pro[5100010];
char txt[251][1010];
bool vst[N];
int main()
{
    int T;
    scanf("%d",&T);
    fail[0]=0;
    for(int i=0;i<CH;i++) sw[i+'A']=i;
    while(T--)
    {     
         init();    
         int n;
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
         {
             scanf("%s",txt+i);
             insert(txt[i],i);
         }
         AC();
         scanf("%s",pro);
         memset(vst,false,sizeof(vst));
         int v[260]={0};
         int cur=0,ans=0;
         for(int i=0;pro[i];i++)
         {
               if(pro[i]=='[')
               {
                    int j=i+1;
                    int x=0;
                    while(pro[j]>='0'&&pro[j]<='9')
                          x=x*10+pro[j]-'0',j++;
                    char c=pro[j++];
                    i=j;
                    while(x--)
                    {
                        cur=chd[cur][sw[c]];
                        int p=cur;
                        while(p&&!vst[p]) vst[p]=1,v[word[p]]=1,word[p]=0,p=fail[p];
                    }
                    continue;      
               }
               cur=chd[cur][sw[pro[i]]];
               int p=cur;
               while(p&&!vst[p]) vst[p]=1,v[word[p]]=1,word[p]=0,p=fail[p];
         }
         init();
         memset(vst,false,sizeof(vst));
         for(int i=1;i<=n;i++)
         {
               int len=strlen(txt[i]);
               for(int j=0;j<len/2;j++) swap(txt[i][j],txt[i][len-1-j]);
               insert(txt[i],i);
         }
         AC();
         cur=0,ans=0;
         for(int i=0;pro[i];i++)
         {
               if(pro[i]=='[')
               {
                    int j=i+1;
                    int x=0;
                    while(pro[j]>='0'&&pro[j]<='9')
                          x=x*10+pro[j]-'0',j++;
                    char c=pro[j++];
                    i=j;
                    while(x--)
                    {
                        cur=chd[cur][sw[c]];
                        int p=cur;
                        while(p&&!vst[p]) vst[p]=1,v[word[p]]=1,word[p]=0,p=fail[p];
                    }
                    continue;      
               }
               cur=chd[cur][sw[pro[i]]];
               int p=cur;
               while(p&&!vst[p]) vst[p]=1,v[word[p]]=1,word[p]=0,p=fail[p];
         }
         for(int i=1;i<=n;i++) ans+=v[i];
         printf("%d\n",ans);
    }
}
