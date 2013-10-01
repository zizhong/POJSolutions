#include<cstdio>
#include<cstring>
const int N=201;
int g[N][N];
int val[N],d[N];
char s[400][200];
int idx(char str[],int i)
{
    return ((str[i]-'0')*10+str[i+1]-'0')*20
            +(str[i+3]-'0')*10+str[i+4]-'0';
}
int main()
{    
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int n=0; 
    while(gets(s[n])!=NULL) n++;
    for(int i=0;i<n;i++)
    {
         int v=idx(s[i],1);
         for(int j=6;s[i][j];j++)
         {
              if(s[i][j]=='R')
              {
                   int u=idx(s[i],j+1);
                   if(g[u][v]==0)
                       g[u][v]=1,d[v]++;
              }
         }
         if(d[v]==0) val[v]=1;
    }
    while(1)
    {
             
         int flag=0;
         for(int i=0;i<200;i++) if(d[i]==0)
         {
               d[i]=-1;
               for(int j=0;j<200;j++)
                    if(g[i][j])
                    {
                        g[i][j]=0;
                        d[j]--;
                        if(d[j]==0)
                        {
                             
                             flag=1;
                             val[j]=1;
                        }
                    }
         }
         if(flag==0) break;
    }
    for(int i=0;i<n;i++) 
    {
         int v=idx(s[i],1);
         s[i][6]=0;
         printf("%s %s\n",s[i],val[v]?"ok":"circular");
    }
    
}   
