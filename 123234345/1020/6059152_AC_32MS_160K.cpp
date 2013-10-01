#include<stdio.h>
int c[11],d[41],s,n,sum;
bool ok;
void dfs(int a)
{
     int i,j,put,p;
     bool f=0;
     if(ok) return ;
     if(a==n) {ok=true; return ;}
     for(i=1,put=41;i<=s;i++)
         if(d[i]<put)  put=d[i],p=i;
     for(i=10;i>=1;i--)
        if(c[i]>0&&put+i-1<=s&&p+i-1<=s)
        {
             for(j=p,f=true;j<=p+i-1;j++)
                if(d[j]>put)
                {
                    f=false;
                    break;
                }
             if(f)
             {
                  for(j=p;j<=p+i-1;j++)  d[j]+=i;
                  c[i]--;
                  dfs(a+1);
                  c[i]++;
                  for(j=p;j<=p+i-1;j++) d[j]-=i;
             }
        }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
         scanf("%d%d",&s,&n);
         for(int i=0;i<11;i++) c[i]=0;
         sum=0;
         int st;
         for(int i=1;i<=n;i++)
             scanf("%d",&st),c[st]++,sum+=st*st;
         ok=false;
         if(sum==s*s) dfs(0);
         if(ok) puts("KHOOOOB!");
         else puts("HUTUTU!");
    }
}
