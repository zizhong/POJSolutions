#include<stdio.h>
#include<string.h>
char color[10][11];
int w[10][100];
int m,n;
short v[1000000];
int idx(char *str)
{
    for(int i=0;i<m;i++) if(!strcmp(color[i],str)) return i;
}
int main()
{
    int t=0;   
    while(scanf("%d%d",&m,&n),n||m)
    {        
         getchar();
         for(int i=0;i<m;i++) scanf("%s",color[i]);
         int nk[10]={0};
         int sum[10]={0};
         for(int i=0;i<n;i++)
         {
              char str[100];
              int nc;
              scanf("%d%s",&nc,str);
              int id=idx(str);
              w[id][nk[id]++]=nc;
              sum[id]+=nc;
         }
         int ans=0;
         for(int i=0;i<10;i++)
         {
              int tans=0;
              t++;
              v[0]=t;
              for(int j=0;j<nk[i];j++)
                  for(int k=sum[i];k>=w[i][j];k--)
                      if(v[k-w[i][j]]==t) v[k]=t;
              int x=sum[i]/2;
              while(v[x]!=t) x--;
              ans+=sum[i]-x;
         }
         printf("%d\n",ans);
    }
}
