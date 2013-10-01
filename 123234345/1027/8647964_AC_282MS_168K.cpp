#include<stdio.h>
#include<cstring>
char s[10][16];
char tmp[10][16];
int cnt[10][16],cc;
bool isOk(char c)
{
     return c=='R'||c=='G'||c=='B';
}
int dfs(int x,int y,char c)
{
     if(x<0||x>=10||y<0||y>=15||tmp[x][y]!=c) return 0;
     tmp[x][y]='R'+cc+1;
     return 1+dfs(x-1,y,c)+dfs(x+1,y,c)+dfs(x,y-1,c)+dfs(x,y+1,c);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
         for(int i=9;i>=0;i--)
             scanf("%s",s[i]);
         int ans=0,move=0;
         printf("Game %d:\n\n",tt);
         int ret=0;
         while(1)
         {
              memcpy(tmp,s,sizeof(s)); 
              memset(cnt,0,sizeof(cnt)); 
              cc=0;
              for(int j=0;j<15;j++) 
                 for(int i=0;i<10;i++)
                  if(isOk(tmp[i][j]))
                  {
                      cnt[i][j]=dfs(i,j,tmp[i][j]);
                      cc++;
                  }
              int x=-1,y=-1,ans=0,sum=0;              
              
                  for(int j=0;j<15;j++) for(int i=0;i<10;i++)
                  {
                       if(isOk(s[i][j])&&cnt[i][j]>1&&cnt[i][j]>ans)
                       {
                            ans=cnt[i][j];
                            x=i;
                            y=j;
                       }
                       sum+=cnt[i][j]?cnt[i][j]:isOk(s[i][j]);
                  }
              if(x==-1)
              {
                  if(sum==0) ret+=1000;
                  printf("Final score: %d, with %d balls remaining.\n",ret,sum);
                  if(tt!=T) puts("");
                  break;
              }
              printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
                     ++move,x+1,y+1,cnt[x][y],s[x][y],(cnt[x][y]-2)*(cnt[x][y]-2));
              ret+=(cnt[x][y]-2)*(cnt[x][y]-2);
              //remove
              int key=tmp[x][y];
              for(int i=0;i<10;i++)
                    for(int j=0;j<15;j++) 
                        if(tmp[i][j]==key) s[i][j]='*';
              //top->bottom
              for(int i=0;i<15;i++)
              {   
                   int k=10;
                   for(int j=0;j<k;j++)
                       while(s[j][i]=='*')
                       {
                             for(int h=j;h<k;h++)
                                  s[h][i]=s[h+1][i];
                             k--;
                             s[k][i]=0;
                       }
              }
              //right->left
              int line[15],nline=0;
              for(int i=0;i<15;i++)  if(s[0][i])
                  line[nline++]=i;
              for(int i=0;i<nline;i++)
              {
                    for(int j=0;j<10;j++)
                    {
                       if(line[i]!=i) 
                       {
                           s[j][i]=s[j][line[i]];
                           s[j][line[i]]=0;
                       }
                    }
              }
         }
    }
}