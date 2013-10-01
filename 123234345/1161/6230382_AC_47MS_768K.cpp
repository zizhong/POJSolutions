#include<stdio.h>
int town[252][202],g[202][202],club[31],line[251][251];
const int MAX=999999;
int main()
{
        int m,n,l;
    scanf("%d%d%d",&m,&n,&l);
    for(int i=0;i<l;i++) scanf("%d",&club[i]);
    for(int i=1;i<=m;i++)
       for(int j=1;j<=m;j++)
           if(i!=j) g[i][j]=MAX;
    for(int i=1;i<=m;i++)
    {
         int nw,t1,t2,tp;
         scanf("%d",&nw);
         for(int j=1;j<=nw;j++)
         {
              scanf("%d",&t1);
              town[t1][i]=1;
              if(j==1) t2=tp=t1;
              else
              {
                  if(line[t1][t2]) g[i][line[t1][t2]]=g[line[t1][t2]][i]=1;
                  else line[t1][t2]=line[t2][t1]=i;
                  t2=t1;
              }
         }
         if(line[t1][tp]) g[i][line[t1][tp]]=g[line[t1][tp]][i]=1;
         else line[t1][tp]=line[tp][t1]=i;
    }
    for(int k=1;k<=m;k++)
       for(int i=1;i<=m;i++)
          for(int j=1;j<=m;j++)
              if(g[i][k]+g[k][j]<g[i][j]) g[i][j]=g[i][k]+g[k][j];
    int ans=MAX;
    for(int to=1;to<=m;to++)
    {
          int min=0;
          for(int i=0;i<l;i++)
          {
               int md=MAX;
               for(int j=1;j<=m;j++)
                  if(town[club[i]][j]&&md>g[j][to]) md=g[j][to];
               min+=md;                  
          }
          if(ans>min) ans=min;
    }
    printf("%d\n",ans);    
}
