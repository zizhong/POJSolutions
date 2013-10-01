//zz from duoshute
#include<stdio.h>
#include<string.h>
const int Mid=401,MAX=2*Mid+2;
unsigned int p2[21];
int ans[21][MAX][11],sum[21][MAX],
    minus[220],plus[220];
int i,j,k,n,m,p,t1,t2,s,l;
void output(int i)
{
     printf("Best jury has value %d for prosecution and value %d for defence:\n",
            (sum[m][Mid+i]+i)>>1,(sum[m][Mid+i]-i)>>1);
     for(p=0;p<=n/20;p++) 
        for(s=0;s<=20;s++) 
            if((p2[s]&ans[m][Mid+i][p])==p2[s])
                printf("%d ",p*20+s+1);
    puts("");puts("");
}
int main()
{
    for(p2[0]=1,i=1;i<=20;i++) p2[i]=1<<i;
    while(scanf("%d%d",&n,&m),n)
    {
          printf("Jury #%d\n",++l);
          memset(ans,0,sizeof(ans));
          memset(sum,-1,sizeof(sum));
          sum[0][Mid]=0;
          for(i=0;i<n;i++)
               scanf("%d%d",&j,&k),minus[i]=j-k,plus[i]=j+k;
          for(i=0;i<n;i++)
              for(s=m;s>=1;s--)
                 for(j=Mid-20*m;j<=Mid+20*m;j++)
                 if(sum[s-1][j]>=0)
                 {
                      t1=sum[s-1][j]+plus[i];
                      t2=j+minus[i];
                      if(t1>sum[s][t2])
                      {
                            sum[s][t2]=t1;
                            for(p=0;p<=i/20;p++)
                                 ans[s][t2][p]=ans[s-1][j][p];
                            ans[s][t2][i/20]+=p2[i%20];                            
                      }
                 }
          for(i=0;i<=20*m;i++)
          {
                if(sum[m][Mid-1]>=0||sum[m][Mid+i]>=0)
                if(sum[m][Mid-i]>sum[m][Mid+i]) {output(-i);break;}
                else {output(i);break;}
          }
                 
    }    
}
