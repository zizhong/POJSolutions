#include<cstdio>
#include<cstring>
char cmd[81];
char map[110][110];
char msg[110*110];
int n;
void Shake()
{
     for(int i=1;i<=n;i++)
     {
          char tmp=(i&1) ? map[1][i]:map[n][i];
          if(i&1) 
          {
                  for(int j=1;j<n;j++)
                        map[j][i]=map[j+1][i];
                  map[n][i]=tmp;
          }else
          {
                  for(int j=n;j>1;j--)
                        map[j][i]=map[j-1][i];
                  map[1][i]=tmp;
          }          
     }
}
void Rattle()
{
     for(int i=1;i<=n;i++)
     {
          char tmp=(i&1)?map[i][n]:map[i][1 ];
          if(i&1)
          {
                for(int j=n;j>1;j--)
                      map[i][j]=map[i][j-1];
                map[i][1]=tmp;
          }else
          {
                for(int j=1;j<n;j++)
                      map[i][j]=map[i][j+1];
                map[i][n]=tmp;
          }
     }
}
char tmp[110][110];
void Loop()
{
     for(int i=1;i<=n/2;i++)
     {
         if(i&1)
         {
               for(int j=2;j<=n-i;j++)
               {
                    tmp[i][j]=map[i][j-1];
                    tmp[n-i+1][j]=map[n-i+1][j+1];
                    tmp[j][i]=map[j+1][i];
                    tmp[j][n-i+1]=map[j-1][n-i+1];
               }
               tmp[i][i]=map[i+1][i];
               tmp[i][n-i+1]=map[i][n-i+1-1];
               tmp[n-i+1][i]=map[n-i+1][i+1];
               tmp[n-i+1][n-i+1]=map[n-i+1-1][n-i+1];
         }
         else
         {
               for(int j=2;j<=n-1;j++)
               {
                    tmp[i][j]=map[i][j+1];
                    tmp[n-i+1][j]=map[n-i+1][j-1];
                    tmp[j][i]=map[j-1][i];
                    tmp[j][n-i+1]=map[j+1][n-i+1];
               }
               tmp[i][i]=map[i][i+1];
               tmp[i][n-i+1]=map[i+1][n-i+1];
               tmp[n-i+1][i]=map[n-i+1-1][i];
               tmp[n-i+1][n-i+1]=map[n-i+1][n-i+1-1];
         }
     }
     memcpy(map,tmp,sizeof(tmp));
}
int main()
{
    while(scanf("%s",cmd)==1)
    {
         getchar();
         gets(msg);
         n=(cmd[0]-'0')*10+cmd[1]-'0';
         if(n==0) n=100;
         
         int x=1,y=1;
         for(int i=0;msg[i];i++)
         {
              map[x][y]=msg[i];
              if(map[x][y]>='a'&&map[x][y]<='z')
                   map[x][y]+='A'-'a';
              y++;
              if(y>n) y=1,x++;
         }
         
         int p=0;
         for(int i=x;i<=n;i++)
              for(int j=(i==x?y:1);j<=n;j++)
              {
                   map[i][j]='A'+p;
                   p++;
                   if(p==26) p=0;
              }
         
         for(int i=2;cmd[i];i++)
         {
              switch(cmd[i])
              {
                    case 'S':Shake();break;
                    case 'R':Rattle();break;
                    case 'L':Loop();break;
              }
         }
         
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 putchar(map[i][j]);
         puts("");
    }
}
