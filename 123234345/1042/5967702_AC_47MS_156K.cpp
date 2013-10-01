#include<stdio.h>
int cmp(int a[],int b[],int n)
{
    for(int i=1;i<=n;i++)
       if(a[i]!=b[i]) return a[i]<b[i];
    return 0;
}
void cpy(int a[],int b[],int n)
{
     while(n>=1) a[n]=b[n],n--;
}
int main()
{
    int N,fir=0;
    while(scanf("%d",&N),N)
    {
         int t;
         scanf("%d",&t);
         t*=12;
         int spend[26]={0},fish[26],d[26],cs[25],ans=0,tans;
         for(int i=1;i<=N;i++) scanf("%d",&fish[i]);
         for(int i=1;i<=N;i++) scanf("%d",&d[i]);
         for(int i=1;i<=N-1;i++) scanf("%d",&cs[i]);
         for(int n=1;n<=N;n++)
         {
              int tm=t;
              for(int i=1;i<=n-1;i++) tm-=cs[i];
              int tf[26]={0},ts[26]={0};
              cpy(tf,fish,n);
              tans=0;
              while((tm--)>0)
              {
                   int max=-1,mi=-1;
                   for(int i=1;i<=n;i++) if(max<tf[i]) max=tf[i],mi=i;
                   if(max<0) break;
                   ts[mi]+=5;
                   tans+=tf[mi];
                   tf[mi]-=d[mi];
                   if(tf[mi]<0) tf[mi]=0;
              }
              //printf("tans=%d\n",tans);
              if(tans>ans||(tans==ans&&cmp(spend,ts,N))) ans=tans,cpy(spend,ts,N);
         }
         if(fir) puts("");
         fir++;
         printf("%d",spend[1]);
         for(int i=2;i<=N;i++) printf(", %d",spend[i]);
         printf("\nNumber of fish expected: %d\n",ans);
    }
}
