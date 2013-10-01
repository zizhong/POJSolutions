#include<stdio.h>
const int N=21,P=10,S=33;
int dll[N],pro[P],tran[S];
char req[P][N];
int main()
{
    int n,p,s;
    while(scanf("%d",&n),n)
    {
         scanf("%d%d",&p,&s);
         for(int i=0;i<n;i++) scanf("%d",&dll[i]);
         for(int i=1;i<=p;i++)
             scanf("%d %s",&pro[i],req[i]);
         int ans=0;
         int vp[P]={0};
         for(int k=0;k<s;k++)
         {
              int x;
              scanf("%d",&x);
              if(x>0) vp[x]++;
              else vp[-x]--;
              int vd[N]={0};
              for(int i=1;i<=p;i++)
                  if(vp[i])
                  for(int j=0;req[i][j];j++)
                       vd[req[i][j]-'A']=1;
              int res=0;
              for(int i=1;i<=p;i++)
                   res+=vp[i]*pro[i];
              for(int i=0;i<n;i++)
                   res+=vd[i]*dll[i];
              if(res>ans) ans=res;
         }
         printf("%d\n",ans);
    }
}
