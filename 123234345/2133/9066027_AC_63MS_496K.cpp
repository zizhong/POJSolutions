#include<cstdio>
const int maxn=(1<<16)+5;
const int INF=100000000;
int n,m;
int dp[maxn];
bool use[maxn];
int a[101],goal;
int min(int a,int b){return a<b?a:b;}
int getnum(char *b)
{
    int i,num=0;
    for(i=0;b[i];i++)num=num*2+b[i]-'0';
    return num;
}
int cal(int k)
{
    int num;
    for(num=0;k;k>>=1)num+=k%2;
    return num;
}
void output(int num)
{
    int str[100],i;
    for(i=0;i<n;i++,num>>=1)str[i]=num%2;
    for(i=n-1;i>=0;i--)printf("%d",str[i]);
    printf("\n");    
}      
int main()
{
    int i,j,k,t,ans,dis,id,v;
    char b[100];
    scanf("%d%d",&n,&m);
    scanf("%s",b);
    goal=getnum(b);
    for(i=0;i<m;i++){scanf("%s",b);a[i]=getnum(b);}
         
    for(i=0;i<(1<<n);i++){dp[i]=INF;use[i]=0;}
    for(i=0;i<m;i++){use[a[i]]=1;dp[a[i]]=2;}
         
    for(i=0;i<m;i++)
    {
        for(j=0;j<(1<<n);j++)
        {
            if(dp[j]<INF||use[j])
            {
               if(use[j])t=0;
               else t=dp[j];
               k=(j^a[i]);
               dp[k]=min(dp[k],t+1);
               }                
            }           
        }
    dis=INF;v=INF;       
    for(i=0;i<(1<<n);i++)
    {
        if(dp[i]==INF)continue;
        k=cal(i^goal);
        if(k<dis||k==dis&&dp[i]<v)
        {
           dis=k;
           v=dp[i];
           id=i;                      
        }                
    }
    printf("%d\n",v);
    output(id); 
} 
