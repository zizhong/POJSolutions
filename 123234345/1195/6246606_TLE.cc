#include<stdio.h>
const int N=1025;
int n;
int a[N][N];
int Q(int l,int r,int b,int t)
{
    if(l==r&&b==t) return a[l][b];
    if(l>r||b>t) return 0;
    if(l==r) return Q(l,l,b,(b+t)>>1)+Q(l,l,((b+t)>>1)+1,t);
    if(b==t) return Q(l,(l+r)>>1,b,b)+Q(((l+r)>>1)+1,r,b,b);
    return Q(l,(l+r)>>1,b,(b+t)>>1)+Q(((l+r)>>1)+1,r,b,(b+t)>>1)+
           Q(l,(l+r)>>1,((b+t)>>1)+1,t)+Q(((l+r)>>1)+1,r,((b+t)>>1)+1,t);
}
int main()
{
    int way;
    while(scanf("%d",&way),way!=3)
    {
         if(way==0)
         {
               scanf("%d",&n);               
         }
         if(way==1)
         {
               int x,y,m;
               scanf("%d%d%d",&x,&y,&m);
               a[x][y]+=m;
         }
         if(way==2)
         {
               int l,r,b,t;
               scanf("%d%d%d%d",&l,&b,&r,&t);
               printf("%d\n",Q(l,r,b,t));
         }
    }
}
