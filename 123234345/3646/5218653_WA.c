#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n)
    {
       int i,j,flag=0;
       int head[20000]={0},knight[20000]={0},used[20000]={0};
       for(i=0;i<n;i++)
         scanf("%d",&head[i]);
       for(i=0;i<m;i++)
         scanf("%d",&knight[i]);
       if(n>m){printf("Loowater is doomed!\n"); continue;}
       for(i=0;i<n;i++)
       {
          
          int min=9999999,mj=-1;
          for(j=0;j<m;j++)
              if(head[i]<=knight[j]&&!used[i]&&knight[j]<min)
              {
                 min=knight[j];
                 mj=j;
              }
          if(mj==-1) {flag=1;break;}
          else used[mj]=1;
       }
       if(flag) printf("Loowater is doomed!\n");
       else
       {
           int sum=0;
           for(i=0;i<m;i++)
             if(used[i]) sum+=knight[i];
           printf("%d\n",sum);
       }
    }
}
