#include<stdio.h>
#include<string.h>
const int N=16;
int v[N][N];
char map[N][N];
int n,m,st;
void solve()
{
     int r=1,c=st,step=1;
     while(1)
     {
            if(r<1||r>n||c<1||c>m)
            {
                  printf("%d step(s) to exit\n",step-1);
                  return ;
            }
            if(v[r][c])
            {
                  printf("%d step(s) before a loop of %d step(s)\n",v[r][c]-1,step-v[r][c]);
                  return ;
            }
            v[r][c]=step++;
            switch (map[r][c])
            {
                   case 'E':c++;break;
                   case 'W':c--;break;
                   case 'N':r--;break;
                   case 'S':r++;break;
            }
     }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&st),n)
    {
         for(int i=1;i<=n;i++)
             scanf("%s",map[i]+1);
         memset(v,0,sizeof(v));
         solve();
    }
}
