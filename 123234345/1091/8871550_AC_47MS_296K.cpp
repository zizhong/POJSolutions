#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int N=10010;
bool v[N];
int pp[N][2],pl[N],cnt,pcnt;
int n,m;
__int64 ret;
void per()
{
     for(int i=2;i<N;i++) if(v[i]==false)
     {
          pl[cnt++]=i;   
          for(int j=i+i;j<N;j+=i) v[j]=true;
     }
}
void m2pp()
{
     pcnt=0;
     int x=m;
     for(int i=0;pl[i]*pl[i]<=x;i++) if(x%pl[i]==0)
     {
         pp[pcnt][0]=pl[i];
         pp[pcnt][1]=1;
         x/=pl[i];
         while(x%pl[i]==0)
         {
             x/=pl[i];
             pp[pcnt][1]++;
         }
         pcnt++;
     }
     if(x>1)
     {
         pp[pcnt][0]=x;
         pp[pcnt][1]=1;
         pcnt++;
     }
     //for(int i=0;i<pcnt;i++)
     //     printf("<%d,%d>\n",pp[i][0],pp[i][1]);
}
int tmpp[N];
__int64 pow(__int64 n,int m)
{
        __int64 ans=1,tmp=n;
        while(m)
        {
            if(m&1) ans*=tmp;
            m>>=1;
            tmp*=tmp;;
        }
        return ans;
}
void dfs(int st,int num,int need)
{
     if(num==need)
     {
          __int64 mul=1;
          for(int i=0;i<need;i++)
          {
               mul*=tmpp[i];
          }
          mul=m/mul;
          ret+=pow(mul,n);
     }
     else
     {
         for(int i=st;i<pcnt;i++)
         {
              tmpp[num]=pp[i][0];
              dfs(i+1,num+1,need);
         }
     }
}
int main()
{
    per();
    while(scanf("%d%d",&n,&m)==2)
    {
        m2pp();
        __int64 ans=pow(m,n);
        for(int i=1;i<=pcnt;i++)
        {
             ret=0;
             dfs(0,0,i);
             //cout<<i<<' '<<ret<<endl;
             if(i&1) ans-=ret;
             else ans+=ret;
        }
        cout<<ans<<endl;
    }
    system("pause");
}
