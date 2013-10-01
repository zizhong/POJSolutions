#include<stdio.h>
#include<string.h>
using namespace std;
const int CH=4,N=1010,INF=1010;
int chd[N][CH],sz;
int word[N],fail[N];
int Que[N];
int sw[128];
void insert(char *a)
{
     int p=0;
     for(;*a;a++)
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
     word[p]=1;
}
void AC()
{
     int *s=Que,*e=Que;
     for(int i=0;i<CH;i++)  if(chd[0][i])
     {
             fail[chd[0][i]]=0;
             *e++=chd[0][i];
     }
     while(s!=e)
     {
          int p=*s++;
          for(int i=0;i<CH;i++) 
             if(chd[p][i])
             {
                  int v=chd[p][i];
                  *e++=v;
                  fail[v]=chd[fail[p]][i]; 
				  word[v]|=word[fail[v]];
             }
             else chd[p][i]=chd[fail[p]][i];
     }
}
void init()
{
     memset(word,0,sizeof(word));
     memset(chd[0],0,sizeof(chd[0]));
     sz=1;
}
char str[1010];
int f[N][N],len;
char op[]={"ATCG"};
void dfs(int i,int p)
{
     //printf("%d %d %d\n",i,p,f[i][p]);
     for(int j=0;j<4;j++)
     {
          int dec=(op[j]!=str[i]);
          int pp=chd[p][j];
          //while(pp&&!chd[pp][j]) pp=fail[pp];
          if(word[pp]||f[i][p]+dec>=f[i+1][pp]) continue;
          f[i+1][pp]=f[i][p]+dec;
          dfs(i+1,pp);
     }
}

int main()
{
    fail[0]=0;
    sw['A']=0,sw['T']=1,sw['C']=2,sw['G']=3;
    int n,T=0;
    while(scanf("%d",&n),n)
    {
        init();
        for(int i=0;i<n;i++)
        {
             char s1[64];
             scanf("%s",s1);
             insert(s1);
        }
        AC();
        scanf("%s",str);
        len=strlen(str);
        
        for(int i=0;i<=len;i++)
            for(int j=0;j<=sz;j++)
                 f[i][j]=INF;
        f[0][0]=0;
        
        for(int i=0;i<len;i++)
              for(int j=0;j<sz;j++) if(f[i][j]<INF)
              {
                   for(int k=0;k<4;k++)
                   {
                        int dec=(op[k]!=str[i]);
                        int p=chd[j][k];
                        if(f[i][j]+dec<f[i+1][p]&&!word[p])
                           f[i+1][p]=f[i][j]+dec;
                   }
              }
        
        int ans=INF;
        for(int i=0;i<sz;i++)
            if(f[len][i]<ans) ans=f[len][i];
        if(ans==INF) ans=-1;
        printf("Case %d: %d\n",++T,ans);
    }
}
