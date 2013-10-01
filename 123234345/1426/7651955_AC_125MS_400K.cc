#include<stdio.h>
#include<string.h>
const int N=101;
int v[N],d[N],find,n,dep;
int dfs(int flag,int k,int cur)
{
    
     if(find) return 1;//printf("<%d %d %d %d>\n",flag,k,cur,dep);
     if(flag>0&&k==0) return 1;
     if(cur>dep) return 0;
     v[cur]=1;
     if(dfs(flag+1,(k+d[cur])%n,cur+1)) {find=1;return 1;}
     v[cur]=0;
     if(dfs(flag,k,cur+1)){find=1;return 1;}
     return 0;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         if(n==1)
         {
             printf("1\n");
             continue;
         }
         memset(v,0,sizeof(v));
         d[1]=1;
         for(int i=2;i<N;i++)
             d[i]=(d[i-1]%n)*10%n;
         
         dep=1;
         find=0;
         for(;;dep++)
         {
              if(dfs(0,0,1)) break;
         }
         for(int i=dep;i>=1;i--) printf("%d",v[i]);
         puts("");
    }
}
