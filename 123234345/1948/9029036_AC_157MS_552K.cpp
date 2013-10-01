#include<cstdio>
#include<cstring>
#include<cmath>
const int N=810;
bool can[N][N];
int len[41],n;
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++)
         scanf("%d",&len[i]),sum+=len[i];
    can[0][0]=true;
    for(int k=0;k<n;k++)
    {
        for(int i=sum/2;i>=0;i--)
              for(int j=sum/2;j>=0;j--)
              if(can[i][j])
             {
                if(i+len[k]<=sum/2) can[i+len[k]][j]=true;
                if(j+len[k]<=sum/2) can[i][j+len[k]]=true;
             }
    }
    int ans=0;
    for(int i=1;i<=sum/2;i++)
       for(int j=1;j<=sum/2;j++) if(can[i][j]&&sum-i-j>0)
       {
             double p=0.5*sum;
             int tmp=(int)(100*sqrt(p* (p-i) * (p-j) * (p-(sum-i-j)) ));
             if(tmp>ans) ans=tmp;
       }
    printf("%d\n",ans?ans:-1);
    //scanf("%'d");       
}
