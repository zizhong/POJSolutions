#include<cstdio>
#include<cstring>
const int N=500010;
int num[N];
bool vst[N];
void prenum()
{
     int tmp=0,k;
     num[1]=1;
     for(int i=2;i<=N;i++) if(!vst[i])
     {
          num[i]=2;
          for(int j=i+i;j<=N;j+=i)
          {
              if(!vst[j]) vst[j]=true,num[j]=1;
              k=j,tmp=0;
              while(k%i==0) k/=i,tmp++;
              num[j]*=(tmp+1); 
          }
     }
}
int n,k;
struct Peo
{
     char name[16];
     int x;
     void init(){scanf("%s%d",name,&x);}
}peo[N];
int cnt[N];
void build(int l,int r,int i)
{
     cnt[i]=r-l+1;
     if(l==r) return ;
     build(l,(l+r)/2,i*2);
     build((l+r)/2+1,r,i*2+1);
}
int del(int x,int l,int r,int i)
{
    cnt[i]--;
    if(l==r) return l;
    int mid=l+r>>1;
    if(cnt[2*i]>x) return del(x,l,mid,2*i);
    return del(x-cnt[2*i],mid+1,r,2*i+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    prenum();
    //for(int i=1;i<=10;i++) printf("%d ",num[i]);puts("");
    while(scanf("%d%d",&n,&k)==2)
    {
         for(int i=1;i<=n;i++) peo[i].init();
         build(1,n,1);
         int mi=-1,mt;
         k--;
         for(int t=1;t<=n;t++)
         {
              int i=del(k,1,n,1);
              if(mi==-1) mi=i,mt=t;
              else if(num[t]>num[mt]) mi=i,mt=t;
              if(cnt[1]) 
              {
                   if(peo[i].x<0) k=(((k+cnt[1]+peo[i].x)%cnt[1])+cnt[1])%cnt[1];
                   else k=((k-1+peo[i].x)%cnt[1]+cnt[1])%cnt[1];     
              }
              //printf("<%s %d %d %d %d>\n",peo[i].name,i,k,cnt[1],peo[i].x);
         }
         printf("%s %d\n",peo[mi].name,num[mt]);
    }
}
