#include<stdio.h>
#include<string.h>
const int MAX=9999999,N=6;
int f[N][N][N][N][N],s,b;
int num[1001];
struct Goods
{
       int c,k,p;
}g[N];
struct Disc
{
       int n,pair[N][2],p;
}d[1001];
int _min(int x,int y)
{
    return x>y?y:x;
}
int main()
{
    scanf("%d",&b);
    for(int i=1;i<=b;i++) scanf("%d%d%d",&g[i].c,&g[i].k,&g[i].p),num[g[i].c]=i;
    for(int i1=0;i1<=g[1].k;i1++)
            for(int i2=0;i2<=g[2].k;i2++)
                    for(int i3=0;i3<=g[3].k;i3++)
                            for(int i4=0;i4<=g[4].k;i4++)
                                    for(int i5=0;i5<=g[5].k;i5++)
                                            f[i1][i2][i3][i4][i5]=i1*g[1].p+i2*g[2].p+i3*g[3].p+i4*g[4].p+i5*g[5].p;
    scanf("%d",&s);
    for(int i=1;i<=s;i++)
    {
            int m[N]={0};
            scanf("%d",&d[i].n);
            for(int j=0;j<d[i].n;j++)
            {
                 scanf("%d%d",&d[i].pair[j][0],&d[i].pair[j][1]);
                 d[i].pair[j][0]=num[d[i].pair[j][0]];
                 m[d[i].pair[j][0]]=d[i].pair[j][1];
            }
            scanf("%d",&d[i].p);
            f[m[1]][m[2]][m[3]][m[4]][m[5]]=_min(f[m[1]][m[2]][m[3]][m[4]][m[5]],d[i].p);
    }
    for(int i1=0;i1<=g[1].k;i1++)
            for(int i2=0;i2<=g[2].k;i2++)
                    for(int i3=0;i3<=g[3].k;i3++)
                            for(int i4=0;i4<=g[4].k;i4++)
                                    for(int i5=0;i5<=g[5].k;i5++)
                                            for(int n1=0;n1<=i1;n1++) 
                                            for(int n2=0;n2<=i2;n2++) 
                                            for(int n3=0;n3<=i3;n3++)
                                            for(int n4=0;n4<=i4;n4++) 
                                            for(int n5=0;n5<=i5;n5++)
                                            f[i1][i2][i3][i4][i5]=_min( f[i1][i2][i3][i4][i5],
                                                                        f[i1-n1][i2-n2][i3-n3][i4-n4][i5-n5]+
                                                                        f[n1][n2][n3][n4][n5]);
    printf("%d\n",f[g[1].k][g[2].k][g[3].k][g[4].k][g[5].k]);
}
