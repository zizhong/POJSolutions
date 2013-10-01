#include<stdio.h>
const int N=11;
char map[N][N];
int p[21],n;
struct Node
{   
    int j,x,y;
}st[21];
int top; 
bool dfs(int x,int y,int z)
{
     if(x==10 && y==10) return true;
     for(int i=1;i<x;i++) if(map[i][y]=='*')
          for(int j=0;j<n;j++) 
              if((z&(1<<j))==0&&p[j]==x-i)
                   if(dfs(i,y,z|(1<<j)))
                   {
                         //printf("place plank %d to stump (%d,%d)\n",j+1,i,y);
                         st[top].j=j+1,st[top].x=i,st[top].y=y,top++;
                         return true;
                   }
     
     for(int i=x+1;i<=10;i++) if(map[i][y]=='*')
          for(int j=0;j<n;j++) 
              if((z&(1<<j))==0&&p[j]==i-x)
                   if(dfs(i,y,z|(1<<j)))
                   {
                         //printf("place plank %d to stump (%d,%d)\n",j+1,i,y);
                         st[top].j=j+1,st[top].x=i,st[top].y=y,top++;
                         return true;
                   }
     
     for(int i=1;i<y;i++) if(map[x][i]=='*')
          for(int j=0;j<n;j++) 
              if((z&(1<<j))==0&&p[j]==y-i)
                   if(dfs(x,i,z|(1<<j)))
                   {
                         //printf("place plank %d to stump (%d,%d)\n",j+1,x,i);
                         st[top].j=j+1,st[top].x=x,st[top].y=i,top++;
                         return true;
                   }
     
     for(int i=y+1;i<=10;i++) if(map[x][i]=='*')
          for(int j=0;j<n;j++) 
              if((z&(1<<j))==0&&p[j]==i-y)
                   if(dfs(x,i,z|(1<<j)))
                   {
                         //printf("place plank %d to stump (%d,%d)\n",j+1,x,i);
                         st[top].j=j+1,st[top].x=x,st[top].y=i,top++;
                         return true;
                   }
                   
     return false;
}
int main()
{
    for(int i=1;i<=10;i++)
         scanf("%s",map[i]+1);
    
    int T=0;
    while(scanf("%d",&n)==1)
    {
         if(T) puts("");T=1;
         for(int i=0;i<n;i++) scanf("%d",&p[i]);
         if(!dfs(1,1,0)) puts("no solution possible");
         while(top)
         {
              --top;
              printf("place plank %d to stump (%d,%d)\n",st[top].j,st[top].x,st[top].y);
         }
    }
}
