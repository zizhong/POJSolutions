#include<stdio.h>
#include<string.h>
const int CH=4,N=101,mod=100000;
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
char str[12];
int n,m; 
struct Matrix
{
       __int64 a[N][N];
       Matrix(){memset(a,0,sizeof(a));}
       void One(){for(int i=0;i<sz;i++) a[i][i]=1;}
       Matrix operator *(Matrix &l)
       {
              Matrix tmp;
              for(int i=0;i<sz;i++)
                  for(int j=0;j<sz;j++)
                       for(int k=0;k<sz;k++)
                            tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*l.a[k][j]%mod)%mod;
              return tmp;
       }
}M,g;
Matrix pow(Matrix &t,int k)
{
       Matrix tmp;
       tmp.One();
       while(k)
       {
            if(k&1) tmp=tmp*t;
            t=t*t;
            k>>=1;
       }
       return tmp;
}
int main()
{
    fail[0]=0;
    sw['A']=0,sw['C']=1,sw['T']=2,sw['G']=3;
    while(scanf("%d%d",&m,&n)==2)
    {
         init();
         for(int i=0;i<m;i++) 
         {
              scanf("%s",str);
              insert(str);
         }
         AC();
         Matrix mm,tmp;
         for(int i=0;i<sz;i++)  if(word[i]==0)
         {
             for(int j=0;j<4;j++) 
             {
                 int p=chd[i][j];
                 if(word[p]==0) mm.a[i][p]++;
             }
         }
         //adisM(mm);
         tmp=pow(mm,n);
         int ans=0;
         for(int i=0;i<sz;i++) //if(!word[i]) 
             ans=ans+(tmp.a[0][i])%mod;
         printf("%d\n",ans);
    }
}
