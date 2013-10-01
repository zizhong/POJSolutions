#include<stdio.h>
int father[50005],rank[50005];
void Make_Set(int x)
{
     father[x]=x;
}
int Find_Set(int x)
{
    int t;
    if(father[x]==x) return x;
    t=father[x];
    father[x]=Find_Set(father[x]);
    rank[x]=(rank[t]+rank[x])%3;
    return father[x];
}
void Union_Set(int a,int b,int len)
{
     int ra=Find_Set(a),
         rb=Find_Set(b);
     father[ra]=rb;
     rank[ra]=(rank[b]-rank[a]+3+len)%3;
}
int main()
{
    int i,n,m;
    int d,x,y,rx,ry;
    int sum=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
       Make_Set(i);
    while(m--)
    {
       scanf("%d%d%d",&d,&x,&y);
       if(x>n||y>n||x==y&&d==2)
            sum++;
       else
       {
           rx=Find_Set(x),
           ry=Find_Set(y);
           if(rx==ry)
           {
               if((rank[x]-rank[y]+3)%3!=d-1)
                   sum++;               
           }
           else Union_Set(x,y,d-1);
       }
    }
    printf("%d\n",sum);
    return 0;
}
