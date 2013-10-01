#include<cstdio>
#include<cstring>
const int N=210;
char s[N];
int f[N][N][N],m,n;
int pre[N],rst[N],cnt,color[N],len[N];
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int main()
{    while(scanf("%d",&m)==1)
    {
         scanf("%s",s);
         n=strlen(s);
         
         cnt=0;
         for(int i=0;s[i];i++)
         {
             int j=i;
             while(s[i]==s[j]) j++;
             len[++cnt]=j-i;
             color[cnt]=s[i];
             i=j-1;
         }
         memset(pre,0,sizeof(pre));
         memset(rst,0,sizeof(rst));
         for(int i=cnt;i>=1;i--)
         {
             rst[i]=len[i];
             
             for(int j=i+1;j<=cnt;j++) if(color[i]==color[j])
             {
                 rst[i]+=rst[j];
                 pre[j]=i;
                 break;
             }
         }
         for(int i=1;i<=cnt;i++) for(int j=0;j<m;j++)
         {
              if(len[i]+j<m) f[i][i][j]=m-len[i]-j;
              else f[i][i][j]=(j==0);
              f[i][i-1][j]=0;
         }
         
         for(int l=2;l<=cnt;l++)
             for(int i=1;i+l-1<=cnt;i++)
             {
                  int j=i+l-1;
                  int lv=max(m-len[j],0);                 
                  for(int k=0;k<=lv+1;k++)
                  {
                      f[i][j][k]=f[i][j-1][0]; 
                      if(len[j]+k>=m) f[i][j][k]+=(k==0);
                      else f[i][j][k]+=m-len[j]-k;
                      //printf("%d %d %d \t%d\n",i,j,k,f[i][j][k]);
                      int p=pre[j];
                      while(p>=i)
                      {
                            int nx=f[p+1][j-1][0]+f[i][p][max(min(len[j]+k,m-len[p]),1)];
                            //printf("%d %d %d\n",p,f[p+1][j-1][0],f[i][p][max(min(len[j]+k,m-len[p]),0)]);
                            if(nx<f[i][j][k]) f[i][j][k]=nx;
                            p=pre[p];
                      }
                  }
             }
         //printf("%d\n",f[1][3][2]);
         printf("%d\n",f[1][cnt][0]);
    }
}
