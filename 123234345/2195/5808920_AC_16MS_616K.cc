#include<stdio.h>
#include<string.h>
#define clr(a) memset(a,0,sizeof(a))
#define abs(a) ((a)>0?(a):(-(a)))
const int MAXN=101,inf=999999999;
int n,m,x[MAXN][2],y[MAXN][2],lx[MAXN],ly[MAXN],g[MAXN][MAXN],xi,yi;
char map[MAXN][MAXN];
int marka[MAXN],markb[MAXN];
int mb[MAXN];
int total,al;
int find(int x)
{
    int j;
    marka[x]=1;
    for(j=1;j<=yi;j++)
        if(!markb[j]&&(lx[x]+ly[j]==g[x][j]))
        {
            markb[j]=1;
            if(!mb[j]||find(mb[j]))
            {
                mb[j]=x;
                return 1;
            }
        }
    return 0;
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m),n||m)
    {
         clr(x),clr(y),clr(ly),clr(g),clr(mb),clr(map);
         xi=yi=total=0;
         for(i=1;i<=n;i++)
         {
            getchar();
            for(j=1;j<=m;j++)
            {
                map[i][j]=getchar();
                if(map[i][j]=='m') xi++,x[xi][0]=i,x[xi][1]=j;
                if(map[i][j]=='H') yi++,y[yi][0]=i,y[yi][1]=j;
            }
         }
		for(i=1;i<=xi;i++)
			lx[i]=0x80000000;
		for(i=1;i<=xi;i++)
			for(j=1;j<=yi;j++){
				g[i][j]=-(abs(x[i][0]-y[j][0])+abs(x[i][1]-y[j][1]));
				if(lx[i]<g[i][j]) lx[i]=g[i][j];
			}      
         for(i=1;i<=xi;i++)
         while(1)
         {
              clr(marka),clr(markb);
              if(find(i)) break;
              al=inf;
              for(j=1;j<=xi;j++)
                 if(marka[j])
                 for(k=1;k<=yi;k++)
                    if(!markb[k]&&(al>lx[j]+ly[k]-g[j][k]))
                        al=lx[j]+ly[k]-g[j][k];
              for(j=1;j<=xi;j++) if(marka[j]) lx[j]-=al;
              for(j=1;j<=yi;j++) if(markb[j]) ly[j]+=al;
         }
         for(i=1;i<=yi;i++) total+=g[mb[i]][i];
         printf("%d\n",-total);
    }
}