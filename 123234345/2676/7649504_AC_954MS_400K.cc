#include<stdio.h>
const int N=9;
int f[N][N];
int find=0;
int solve(int x,int y)
{
     if(find) return 1;     
     if(x==-1&&y==-1)
     {
          for(int i=0;i<N;i++,puts(""))
              for(int j=0;j<N;j++)
                   printf("%d",f[i][j]);
          find=1;
          return 1;
     }
     int nx=-1,ny=-1;
     for(int i=x;i<N&&nx==-1;i++)
          for(int j=0;j<N;j++)
             if(f[i][j]==0&&!(i==x&&j==y))
             {
                 nx=i,ny=j;
                 break;
             }
     int v[N]={0};
     for(int i=0;i<N;i++)
     {
         if(f[x][i]) v[f[x][i]-1]=1;
         if(f[i][y]) v[f[i][y]-1]=1;
     }
     for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(f[x/3*3+i][y/3*3+j])
               v[f[x/3*3+i][y/3*3+j]-1]=1;
     for(int i=0;i<N;i++) if(v[i]==0)
     {
            f[x][y]=i+1;
            if(solve(nx,ny)) return 1;
            f[x][y]=0;
     }
     return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[N+1];
        find=0;
        int si=-1,sj=-1;
        for(int i=0;i<N;i++)
        {
             scanf("%s",s);
             for(int j=0;j<N;j++)
             {
                 f[i][j]=s[j]-'0';
                 if(f[i][j]==0&&si==-1)
                    si=i,sj=j;
             }
        }
        if(si>=0)
           solve(si,sj);
        else
        {
            for(int i=0;i<N;i++,puts(""))
              for(int j=0;j<N;j++)
                   printf("%d",f[i][j]);
        }
    }
}
