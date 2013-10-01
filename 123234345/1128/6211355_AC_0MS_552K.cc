#include<stdio.h>
#include<string.h>
const int M=31,N=27;
int g[N][N],n,m,in[N],num;
char map[M][M];
int x1,y1,x2,y2;
void display();
void search(char c)
{
     x1=y1=M,x2=y2=-1;
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(map[i][j]==c)
        {
             if(i<x1) x1=i;
             if(i>x2) x2=i;
             if(j<y1) y1=j;
             if(j>y2) y2=j;
        }
}
void buildG()
{
     num=0;
     memset(g,0,sizeof(g));
     memset(in,-1,sizeof(in));
     num=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
              if(map[i][j]=='.'||(in[map[i][j]-'A']>-1)) continue;
              in[map[i][j]-'A']=0;
              num++;
              search(map[i][j]);
              for(int k=x1;k<=x2;k++)
              {
                      char key=map[k][y1];
                      if(key=='.'||key==map[i][j]||g[key-'A'][map[i][j]-'A']) continue;
                      g[map[i][j]-'A'][key-'A']=1;
              }
              for(int k=x1;k<=x2;k++)
              {
                      char key=map[k][y2];
                      if(key=='.'||key==map[i][j]||g[key-'A'][map[i][j]-'A']) continue;
                      g[map[i][j]-'A'][key-'A']=1;
              }
              for(int k=y1;k<=y2;k++)
              {
                      char key=map[x1][k];
                      if(key=='.'||key==map[i][j]||g[key-'A'][map[i][j]-'A']) continue;
                      g[map[i][j]-'A'][key-'A']=1;
              }
              for(int k=y1;k<=y2;k++)
              {
                      char key=map[x2][k];
                      if(key=='.'||key==map[i][j]||g[key-'A'][map[i][j]-'A']) continue;
                      g[map[i][j]-'A'][key-'A']=1;
              }
         }
     }
     for(int i=0;i<N-1;i++)
             for(int j=0;j<N-1;j++)
                 if(g[i][j])
                            in[j]++;
}
void Seq(char *s,int *in,int level)
{
     if(level==num) {puts(s);return ;}
     for(int i=0;i<=25;i++)
     {
          if(in[i]==0)
          {            
                char s2[N];
                strcpy(s2,s);
                int in2[N];
                for(int j=0;j<=25;++j) in2[j]=in[j];
                s2[level]='A'+i,s2[level+1]=0;
                in2[i]=-1;
                for(int j=0;j<=25;++j) if(g[i][j]) in2[j]--;
                Seq(s2,in2,level+1);
          }
     }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          getchar();
          for(int i=0;i<n;i++) gets(map[i]);
          buildG();
          char s[N]={0};
          Seq(s,in,0);
    }
}
