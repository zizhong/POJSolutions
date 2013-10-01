#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char map[128][128];
int calc(int x1,int y1,int x2,int y2)
{
    
    char key=map[x1][y1];
    for(int i=x1;i<=x2;i++) 
        if(map[i][y1]!=key || map[i][y2]!=key)
             return 0;
    for(int i=y1;i<=y2;i++)
        if(map[x1][i]!=key || map[x2][i]!=key)
             return 0;
    for(int i=x1+1;i<x2;i++)
        for(int j=y1+1;j<y2;j++)
             if(map[i][j]!='.')
                 return 0;
    return 1;
}
int main()
{    
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
         for(int i=0;i<n;i++)
               scanf("%s",map[i]);
         int top[26];
         memset(top,-1,sizeof(top));
         for(int i=0;i<n;i++)
         {
              for(int j=0;j<m;j++) if(map[i][j]!='.' && top[map[i][j]-'A']==-1)
              {
                    int x1=n,y1=m,x2=0,y2=0;
                    for(int x=0;x<n;x++)
                        for(int y=0;y<m;y++)
                           if(map[x][y]==map[i][j])
                            {
                                 x1=min(x1,x);
                                 x2=max(x2,x);
                                 y1=min(y1,y);
                                 y2=max(y2,y);
                            }
                    top[map[i][j]-'A']=calc(x1,y1,x2,y2);
              }
         }
         for(int i=0;i<26;i++) if(top[i]==1)
               putchar('A'+i);
         puts("");
    } 
}
