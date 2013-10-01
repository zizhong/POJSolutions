#include<stdio.h>
#include<stdlib.h>
const int N=65;
int stamp[N],ans[4],nt,nans,tie;
int n;
int findmax(int a[4],int nn)
{
    int max=-1;
    for(int i=0;i<nn;i++)
          if(max<stamp[a[i]]) max=stamp[a[i]];
    return max;
}
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int same(int a[4],int b[4],int nn)
{
    qsort(a,nn,sizeof(a[0]),cmp);
    qsort(b,nn,sizeof(b[0]),cmp);
    for(int i=0;i<nn;i++) if(a[i]!=b[i]) return 0;
    return 1;
}
void update(int d[4],int nn)
{
     
     if(nt>=0&&same(ans,d,nn)) return ;
     int ns=1;
     for(int i=1;i<nn;i++)
          for(int j=0;j<i;j++)
          {
                if(d[j]==d[i]) break;
                if(j==i-1)ns++;
          }
     if(ns>nt)
     {
              for(int i=0;i<nn;i++) ans[i]=d[i];
              nt=ns,nans=nn;
              tie=0;
              return ;
     }
     if(ns==nt)
     {
               if(nn<nans)
               {
                       for(int i=0;i<nn;i++) ans[i]=d[i];
                       nt=ns,nans=nn;
                       tie=0;
                       return ;
               }
               if(nn==nans)
               {
                      int a=findmax(d,nn),b=findmax(ans,nans);
                      if(a>b)
                      {
                             for(int i=0;i<nn;i++) ans[i]=d[i];
                             nt=ns,nans=nn;
                             tie=0;
                             return ;
                      }
                      if(a==b)
                              tie=1;
               }
     }
}
void dfs(int sum,int nn,int d[4],int ss)
{
     if(sum==0&&nn<=4)
     {
               update(d,nn);
               return ;
     }
     if(nn>3) return;
     for(int i=ss;i<n;i++)
     {
             if(sum>=stamp[i]) d[nn]=i,dfs(sum-stamp[i],nn+1,d,i);
     }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    while(scanf("%d",&t)==1)
    {
          int i=0,j=0;
          while(t) stamp[i++]=t,scanf("%d",&t);
          n=i;
          scanf("%d",&t);
          while(t)
          {
               int d[4]={0};
               nt=nans=-1,tie=0;
               dfs(t,0,d,0);
               if(nt==-1) printf("%d ---- none\n",t);
               else
               {
                   int v[N]={0};
                   for(int i=0;i<nans;i++) v[ans[i]]++;
                   printf("%d (%d):",t,nt);
                   if(tie) puts("tie");
                   else
                   {
                       int fir=0;
                       for(int i=0;i<N;i++)
                       while(v[i]--)
                       {
                            if(fir) printf(" ");
                            fir=1;
                            printf("%d",stamp[i]);
                      }
                      puts("");
                   }
               }
               scanf("%d",&t);
          }
    }
}
