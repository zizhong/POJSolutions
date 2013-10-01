#include<cstdio>
#include<cstring>
const int N=100010;
int a[N],b[N],nxt[N],mn1[N],mn2[N],res[N],t[30],n,k,s;
void add(int x,int d)
{
     for(;x>0 && x<=s;x+=x&-x) t[x]+=d;
}
int sum(int x)
{
    int ans=0;
    for(;x>0;x-=x&-x) ans+=t[x];
    return ans;
}
int main()
{
    memset(t,0,sizeof(t));
    scanf("%d%d%d",&n,&k,&s);
    int i,j;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&b[i]);
        add(b[i],1);
        mn1[i]=sum(b[i]);
        mn2[i]=sum(b[i]-1);
    }
    memset(t,0,sizeof(t));
    nxt[1]=0;
    for(i=1,j=0;i<k;)
    {
        add(b[i],1);
        if(j==0||mn1[j]==sum(b[i])&&mn2[j]==sum(b[i]-1))
               nxt[++i]=++j;
        else
        {
            for(int w=0;w<=j;w++)
                 add(b[i-w],-1);
            j=0;
        }  
    }
    memset(t,0,sizeof(t));
    add(a[0],1);
    int beg=0,end=0;
    for(i=j=0;i<n;)
    {
         while(j<k && i<n)
         {
               if(j==0||sum(a[i])==mn1[j]&&sum(a[i]-1)==mn2[j])
               {
                     ++i,++j;
                     if(i<n) add(a[i],1);
               }else
               {
                    for(int w=0;w<j-nxt[j];w++)
                         add(a[beg+w],-1);
                    beg+=j-nxt[j];
                    j=nxt[j];
               }
         }
         if(j==k)
         {
              res[++end]=beg;
              for(int w=0;w<j-nxt[j]&&beg+w<n;w++)
                     add(a[beg+w],-1);
              beg+=j-nxt[j];
              j=nxt[j];
         }
    }
    printf("%d\n",end);
    for(i=1;i<=end;i++) printf("%d\n",res[i]+1);
    //scanf("%'d");
}
