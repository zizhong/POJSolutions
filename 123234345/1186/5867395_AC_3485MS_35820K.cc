#include<stdio.h>
#define tmax 4000037
int hash[tmax],C[tmax];
bool use[tmax];
int k[6],p[6],n,M,ans,mid;
int locate(int s)
{
    int temp;
    temp=s;
    while(temp<0) temp+=tmax;
    while(temp>=tmax) temp-=tmax;
    while(use[temp]&&hash[temp]!=s)
    {
         temp++;
         if(temp>=tmax) temp-=tmax;
    }
    return temp;
}
void insert(int s)
{
     int pos=locate(s);
     hash[pos]=s;
     use[pos]=1;
     C[pos]++;
}
void lefthalf(int d,int s)
{
     int i,j,temp;
     if(d==mid)
     {
         insert(s);
         return ;
     }
     for(i=1;i<=M;i++)
     {
         temp=k[d];
         if(temp!=0&&i!=1)
             for(j=0;j<p[d];j++)
                 temp*=i;
         lefthalf(d+1,s+temp);
     }
}
void righthalf(int d,int s)
{
     int i,j,temp,pos;
     if(d==n)
     {
         s=-s;
         pos=locate(s);
         if(hash[pos]==s) ans+=C[pos];
         return ;
     }
     for(i=1;i<=M;i++)
     {
          temp=k[d];
          if(i!=1&&temp!=0)
          {
               for(j=0;j<p[d];j++)
                   temp*=i;
          }
          righthalf(d+1,s+temp);
     }
}
int main()
{
    int i;
    scanf("%d%d",&n,&M);
    for(int i=0;i<n;i++) scanf("%d%d",&k[i],&p[i]);
    mid=n/2;
    ans=0;
    lefthalf(0,0);
    righthalf(mid,0);
    printf("%d\n",ans);
}







