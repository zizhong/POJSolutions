#include<cstdio>
#include<cstring>
#include<cstdlib>
int num[64],n,bus[312];
int g[64][64];
int ans;
void disnum()
{
     for(int i=0;i<3;i++,puts(""))
        for(int j=0;j<19;j++)
            printf("%2d ",num[i*20+j]);
     puts("-------------");
}
void dfs(int t,int r)
{
     //disnum();
     //printf("%d %d\n",t,r);
     if(t==60)
     {
         
         if(ans>r) ans=r;
         return ;
     }
     if(ans<r) return ;
     if(!num[t]) {dfs(t+1,r);return ;}
     for(int t2=t+1;t2<60;t2++) if(g[t][t2]&&num[t2])
     {
           int k=0,inv=t2-t;
           while(t+k*inv<60&&num[t+k*inv]) k++;
           if(t+k*inv<60) continue;
           k=0;
           while(t+k*inv<60&&num[t+k*inv]) num[t+k*inv]--,k++;
           dfs(t,r+1);
           if(ans<=r) return ;
           while(t+k*inv<60&&num[t+k*inv]) num[t+k*inv]++,k++;
     }
}
int main()
{
        scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&bus[i]),num[bus[i]]++;
    for(int i=0;i<60;i++)
        for(int j=i+1;j<60;j++)
        {
            int inv=j-i,st=j;
            while(st<60&&num[st]) st+=inv;
            g[i][j]=!(st<60); 
        }
    ans=17;
    dfs(0,0);
    printf("%d\n",ans);
}
