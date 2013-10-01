#include<cstdio>
#include<cstring>
int map[16],n,m,Mask;
int calcs(int x,int p)
{
    x^=p,x^=(p<<1),x^=(p>>1);
    return x&Mask;
}
int main()
{    
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        map[i]=0;
        int x;
        for(int j=0;j<m;j++)
            scanf("%d",&x),map[i]=map[i]*2+x;
    }
    int K=1<<m;
    Mask=K-1;
    int flag=0;
    for(int k=0;k<K;k++)
    {
          
          int a[16]={0},w[16]={0};
          for(int i=0;i<n;i++)
               a[i]=map[i];
          for(int i=0;i<m;i++)
              w[0]|=(((k>>i)&1)<<(m-i-1)); 
          a[0]=calcs(a[0],w[0]);
          a[1]^=w[0];
          for(int i=1;i<n;i++)
          {
               w[i]=a[i-1];
               a[i]=calcs(a[i],w[i]);
               a[i+1]^=w[i];
          }
          //printf("%d %d %d %d\n",k,a[0],a[1],a[2]);
          if(a[n-1]==0)
          {
               flag=1;
               for(int i=0;i<n;i++)
                   for(int j=0;j<m;j++)
                       printf("%d%c",(w[i]>>(m-j-1))&1,j==m-1?'\n':' ');
               break;
          }
    }
    if(!flag) puts("IMPOSSIBLE");
    scanf("%'d");
}
