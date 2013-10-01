#include<cstdio>
#include<cstring>
char map[16][16];
int n,mask,inf=0x3fffffff;
int cntbit(int x)
{
    int r=0;
    while(x) r+=x&1,x>>=1;
    return r; 
}
int calc(int x,int p)
{
    x^=p,x^=(p>>1),x^=(p<<1);
    return x&mask;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          scanf("%d",&n);
          for(int i=0;i<n;i++)
              scanf("%s",map[i]);
          int map2[16]={0};
          for(int i=0;i<n;i++)
             for(int j=0;j<n;j++) if(map[i][j]=='y')
                  map2[i]|=(1<<j);
          mask=(1<<n)-1;
          int ans=inf;
          for(int k=0;k<=mask;k++)
          {
               int b[16];
               memcpy(b,map2,sizeof(b));
               int tmp=cntbit(k);
               int way=k;
               b[0]=calc(b[0],way);
               b[1]^=way;
               for(int i=1;i<n;i++)
               {
                     way=(~b[i-1])&mask;
                     b[i-1]=mask;
                     tmp+=cntbit(way);
                     b[i]=calc(b[i],way);
                     b[i+1]^=way;
               }
               if(b[n-1]==mask && ans>tmp) ans=tmp;
          }
          if(ans==inf) puts("inf");
          else printf("%d\n",ans);   
    }
}
