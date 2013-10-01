#include<cstdio>
#include<cstring>
char map[5][5];
int n;
bool ok(int k)
{
     char tmp[5][5];
     memcpy(tmp,map,sizeof(map));
     for(int i=0;i<n*n;i++)
        if(k&(1<<i)) tmp[i/n][i%n]='A';
     //for(int i=0;i<n;i++,puts("")) for(int j=0;j<n;j++) putchar(tmp[i][j]);
     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) if(tmp[i][j]=='A')
        {
             int j1=j+1,i1=i+1;
             while(i1<n && tmp[i1][j]=='.') i1++;
             if(i1<n && tmp[i1][j]=='A') return false;
             while(j1<n && tmp[i][j1]=='.') j1++;
             if(j1<n && tmp[i][j1]=='A') return false;
        }
     return true;           
}
int cntbit(int x)
{
    int t=0;
    while(x) t+=(x&1),x>>=1;
    return t;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
            scanf("%s",map[i]);
         int wall=0;
         for(int i=0;i<n*n;i++) if(map[i/n][i%n]!='.')
             wall|=(1<<i);
         int ans=0;
         for(int k=0;k<(1<<(n*n));k++) if(!(wall & k))
         {
              if(ok(k))
              {
                   int tmp=cntbit(k);
                   if(ans<tmp) ans=tmp;
              }
         }
         printf("%d\n",ans);
    }
}
