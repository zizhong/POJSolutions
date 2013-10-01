#include<stdio.h>
const int N=2001;
char type[N][8];
int caldif(int i,int j)
{
    int ans=0;
    for(int k=0;type[i][k];k++)
       if(type[i][k]!=type[j][k])
            ans++;
    return ans;
}
int g[N][N];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         gets(type[0]);
         for(int i=0;i<n;i++)
            gets(type[i]);
         int ans=0;
         for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                g[i][j]=g[j][i]=caldif(i,j);
         int d[N],v[N];
         for(int i=1;i<n;i++)
             d[i]=g[i][0],v[i]=0;
         while(1)
         {
              int min=7,mi=-1;
              for(int i=1;i<n;i++)
                if(!v[i]&&d[i]<min)
                    min=d[i],mi=i;
              if(mi==-1) break;
              v[mi]=1;
              for(int i=1;i<n;i++)
                  if(!v[i]&&d[i]>g[i][mi])
                      d[i]=g[i][mi];
         }
         for(int i=1;i<n;i++) ans+=d[i];
         printf("The highest possible quality is 1/%d.\n",ans);
    }
}
